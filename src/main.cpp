// Your First C++ Program

#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "lib/sht35/driver_sht35_basic.h"

int main() {
    std::cout << "sht35: start.\n";
    uint8_t res;
    uint8_t i;
    uint8_t sn[4];
    float temperature;
    float humidity;

    res = sht35_basic_init(SHT35_ADDRESS_1);
    if (res != 0)
    {
        std::cerr << "Failed to open the i2c bus\n";
        return 1;
    }

    sht35_interface_delay_ms(1000);
    res = sht35_basic_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        std::cerr << "Failed to read temperature\n";
        (void)sht35_basic_deinit();

        return 1;
    }
    sht35_interface_debug_print("sht35: temperature is %0.2fC.\n", temperature);
    sht35_interface_debug_print("sht35: humidity is %0.2f%%.\n", humidity);
    std::cout << "sht35: temperature is " << temperature << "C." << std::endl;
    std::cout << "sht35: humidity is " << humidity << "%" << std::endl;



    const char *i2cDevice = "/dev/i2c-1"; // I2C bus
    int address = 0x68; // replace with your device's I2C address

    return 0;
}

