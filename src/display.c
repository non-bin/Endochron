#include "stm32l1xx.h"
#include "config.c"

uint16_t encodeCharToDisplay(char c) {
  switch (c) {
    case '0': return 0b0000110000111111;
    case '1': return 0b0000010000000110;
    case '2': return 0b0000100010001011;
    case '3': return 0b0000000010001111;
    case '4': return 0b0000000011100110;
    case '5': return 0b0000000011101101;
    case '6': return 0b0000000011111101;
    case '7': return
  }
}

/*
M
TUE
W
THR
F
SATR
SUN

JA
FE
MR
AP
MY
JN
JL
AU
SE
OC
NO
DE
*/
