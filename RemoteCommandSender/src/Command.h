/*
 * Command.h
 *
 *  Created on: 19.04.2016
 *      Author: Markus
 */

#ifndef SRC_COMMAND_H_
#define SRC_COMMAND_H_

#include <string>
#include <sstream>
#include <bitset>
#include <vector>

enum class FAN_SPEED {
	FAN_SPEED_FULL = 0x0, FAN_SPEED_3 = 0x1, FAN_SPEED_2 = 0x2, FAN_SPEED_1 = 0x3
};

enum class MODE {
	MODE_EGG = 0x3, MODE_RAD = 0x4, MODE_SUN = 0x0, MODE_COOL = 0x2
};

enum class JET {
	JET_ON = 0x9, JET_OFF = 0x0
};

enum class SWING {
	SWING_ON = 0x8, SWING_OFF = 0x0
};

enum class SIX_TH_SENSE {
	SIX_TH_SENSE_ON = 0x1, SIX_TH_SENSE_OFF = 0x0
};

enum class POWER {
	ON = 0x0, OFF = 0x4
};
auto START_1 = std::bitset<4>(12);
auto START_2 = std::bitset<4>(1);
auto START_3 = std::bitset<4>(6);
auto START_4 = std::bitset<4>(0);

struct Command {

	FAN_SPEED fan_speed { };
	JET jet { };
	POWER power { };
	int temperature { 32 };
	MODE mode { };
	SWING swing { };

	std::string generateCommand() {
		power = POWER::ON;
		fan_speed = FAN_SPEED::FAN_SPEED_FULL;
		mode = MODE::MODE_COOL;
		jet = JET::JET_OFF;
		swing = SWING::SWING_OFF;

		auto powerbytes = reverse(std::bitset<4>(static_cast<unsigned>(power)));
		auto fanspeedbytes = reverse(std::bitset<4>(static_cast<unsigned>(fan_speed)));
		auto part5 = powerbytes | fanspeedbytes;
		auto part6 = reverse(std::bitset<4>(static_cast<unsigned>(swing)));
		auto part7 = reverse(std::bitset<4>(static_cast<unsigned>(mode)));
		auto part8 = reverse(std::bitset<4>(temperature - 18));
		auto part9 = std::bitset<4>(0);
		auto part10 = std::bitset<4>(0);
		auto part11 = std::bitset<4>(0);
		auto part12 = reverse(std::bitset<4>(static_cast<unsigned>(jet)));
		auto part13 = std::bitset<4>(8);
		auto part14 = std::bitset<4>(0);

		//special checksum
		auto part15 = std::bitset<4>(1);
		auto part16 = std::bitset<4>(4);

		auto part17 = std::bitset<4>(0);
		auto part18 = std::bitset<4>(0);
		auto part19 = std::bitset<4>(0);
		auto part20 = std::bitset<4>(0);
		auto part21 = std::bitset<4>(3);
		auto part22 = std::bitset<4>(0);
		auto part23 = std::bitset<4>(0);
		auto part24 = std::bitset<4>(0);
		auto part25 = std::bitset<4>(0);
		auto part26 = std::bitset<4>(0);

		auto part27 = part5 ^ part7 ^ part9 ^ part11 ^ part13 ^ part15 ^ part17 ^ part19 ^ part21 ^ part23 ^ part25;
		auto part28 = part6 ^ part8 ^ part10 ^ part12 ^ part14 ^ part16 ^ part18 ^ part20 ^ part22 ^ part24 ^ part26;

		std::vector<std::bitset<4>> list { START_1, START_2, START_3, START_4, part5, part6, part7, part8, part9, part10, part11, part12, part13,
				part14, part15, part16, part17, part18, part19, part20, part21, part22, part23, part24, part25, part26, part27, part28 };

		std::ostringstream oss;

		std::for_each(list.begin(), list.end(), [&](auto item){oss << item << " ";});

		return oss.str();
	}

private:
	void calculateChecksum() {

	}

	template<size_t n>
	std::bitset<n> reverse(std::bitset<n> set) {
		std::bitset<n> result;

		for (size_t i = 0; i < n; i++)
			result[i] = set[n - i - 1];

		return result;
	}

	std::bitset<4> calculateChecksum1() {

		return std::bitset<4> { };
	}
};

#endif /* SRC_COMMAND_H_ */
