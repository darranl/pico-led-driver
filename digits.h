/* Copyright 2023, Darran A Lofthouse
 *
 * This file is part of pico-led-driver.
 *
 * pico-led-driver is free software: you can redistribute it and/or modify it under the terms 
 * of the GNU General Public License as published by the Free Software Foundation, either 
 * version 3 of the License, or (at your option) any later version.
 *
 * pico-led-driver is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with pico-security.
 * If  not, see <https://www.gnu.org/licenses/>. 
 */

#ifndef DIGITS_H
#define DIGITS_H

#include <stdint.h>

#ifndef SEGMENT_MAPPINGS
#define SEGMENT_MAPPINGS
// The segment mappings can be mapped to alternative values
// before this header is parsed.
#define SEGMENT_A  0b00100000
#define SEGMENT_B  0b00010000
#define SEGMENT_C  0b00000100
#define SEGMENT_D  0b00000010
#define SEGMENT_E  0b00000001
#define SEGMENT_F  0b01000000
#define SEGMENT_G  0b10000000
#define SEGMENT_DP 0b00001000

#endif // ifndef SEGMENT_MAPPINGS

const uint8_t digit_0 = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F;
const uint8_t digit_1 = SEGMENT_B | SEGMENT_C;
const uint8_t digit_2 = SEGMENT_A | SEGMENT_B | SEGMENT_G | SEGMENT_E | SEGMENT_D;
const uint8_t digit_3 = SEGMENT_A | SEGMENT_B | SEGMENT_G | SEGMENT_C | SEGMENT_D;
const uint8_t digit_4 = SEGMENT_F | SEGMENT_G | SEGMENT_B | SEGMENT_C;
const uint8_t digit_5 = SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_C | SEGMENT_D;
const uint8_t digit_6 = SEGMENT_A | SEGMENT_F | SEGMENT_G | SEGMENT_C | SEGMENT_D | SEGMENT_E;
const uint8_t digit_7 = SEGMENT_A | SEGMENT_B | SEGMENT_C;
const uint8_t digit_8 = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G;
const uint8_t digit_9 = SEGMENT_G | SEGMENT_F | SEGMENT_B | SEGMENT_C | SEGMENT_A;
const uint8_t decimal_point = SEGMENT_DP;

#endif // ifndef DIGITS_H