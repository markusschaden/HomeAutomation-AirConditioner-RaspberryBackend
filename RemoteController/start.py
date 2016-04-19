import binascii

# byte 0
BYTE_0 = 0x83

# byte 1
BYTE_1 = 0x6

# byte 2
BYTE_2 = 0x0
OFF = 0x40
FAN_SPEED_FULL = 0x0
FAN_SPEED_3 = 0x1
FAN_SPEED_2 = 0x2
FAN_SPEED_1 = 0x5
SWING = 0x80

# byte 3
BYTE_3 = 0x0

# temp add 10
TEMPERATURE_START = 0x0
TEMPERATURE_ADD = 0x10

MODE_EGG = 0x3
MODE_RAD = 0x4
MODE_SUN = 0x0
MODE_COOL = 0x2

SENSE_6TH = 0x1

# byte 4
BYTE_4 = 0x0

# byte 5
BYTE_5 = 0x0
JET_ON = 0x90

# byte 6
BYTE_6 = 0x1

# byte 7
BYTE_7 = 0x28

# byte 8
BYTE_8 = 0x0

# byte 9
BYTE_9 = 0x0

# byte 10
BYTE_10 = 0xC

# byte 11
BYTE_11 = 0x0

# byte 12
BYTE_12 = 0x0

# byte 13 => checksum
BYTE_13 = 0x0


def byte_to_binary(n):
    return ''.join(str((n & (1 << i)) and 1) for i in reversed(range(8)))


def hex_to_binary(h):
    return ''.join(byte_to_binary(ord(b)) for b in binascii.unhexlify(h))


def reverse(str):
    return str[::-1]


print(byte_to_binary(BYTE_0))
print(byte_to_binary(BYTE_1))


test = reverse(byte_to_binary(BYTE_0))






