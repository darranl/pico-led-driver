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

#ifndef TLC5917_H
#define TLC5917_H

#include "hardware/spi.h"

typedef struct {
    spi_inst_t *spi_instance;
    uint baudrate;
    uint gpio_misi;
    uint gpio_sck;
    uint gpio_cs;

} tlc5917_definition_t;

/**
 * Initialise SPI to communicate with the TLC5917 chip(s). 
 */
void tlc5917_init(tlc5917_definition_t *driver_definition);

void tlc5917_write(tlc5917_definition_t *driver_definition, uint8_t digits[], uint8_t digit_count, uint32_t dp_mask);

#endif