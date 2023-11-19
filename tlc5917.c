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

#include "pico/stdlib.h"
#include "hardware/spi.h"

#include "digits.h"
#include "tlc5917.h"

static uint8_t convert_to_pattern(uint8_t value, bool with_dp);

void tlc5917_init(tlc5917_definition_t *driver_definition)
{
    spi_init(driver_definition->spi_instance, driver_definition->baudrate);
    spi_set_format(driver_definition->spi_instance, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
    gpio_set_function(driver_definition->gpio_misi, GPIO_FUNC_SPI); // TO SDI
    gpio_set_function(driver_definition->gpio_sck,  GPIO_FUNC_SPI); // To CLK
    gpio_set_function(driver_definition->gpio_cs,   GPIO_FUNC_SIO); // TO LE
    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_set_dir(driver_definition->gpio_cs, GPIO_OUT);
    gpio_put(driver_definition->gpio_cs, 1);
}

void tlc5917_write(tlc5917_definition_t *driver_definition, uint8_t digits[], uint8_t digit_count, uint32_t dp_mask)
{
    gpio_put(driver_definition->gpio_cs, 0);

    for (int8_t i = digit_count -1 ; i >= 0 ; i--)
    {
        bool add_dp = dp_mask & 0x1;
        uint8_t to_send = convert_to_pattern(digits[i], add_dp);
        spi_write_blocking(driver_definition->spi_instance, &to_send, 1);
        dp_mask = dp_mask >> 1;
    }

    gpio_put(driver_definition->gpio_cs, 1); // Latch enable once all written.
}

static uint8_t convert_to_pattern(uint8_t value, bool with_dp)
{
    uint8_t result = 0;
    // TODO To skip the switch could use an array?
    switch (value)
    {
        case 0:
            result = digit_0;
            break;
        case 1:
            result = digit_1;
            break;
        case 2:
            result = digit_2;
            break;        
        case 3:
            result = digit_3;
            break;        
        case 4:
            result = digit_4;
            break;        
        case 5:
            result = digit_5;
            break;        
        case 6:
            result = digit_6;
            break;        
        case 7:
            result = digit_7;
            break;        
        case 8:
            result = digit_8;
            break;        
        case 9:
            result = digit_9;
            break;        
    }

    if (with_dp)
    {
        result = result | decimal_point;
    }
    return result;
}