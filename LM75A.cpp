#include "lm75a.h"

LM75A::LM75A(i2c_inst_t* i2c_port, uint8_t address) {
    i2c = i2c_port;
    addr = address;
}

void LM75A::begin() {
    // Nothing needed if already initialized in main
}

uint16_t LM75A::read16(uint8_t reg) {
    uint8_t buf[2];
    i2c_write_blocking(i2c, addr, &reg, 1, true);
    i2c_read_blocking(i2c, addr, buf, 2, false);
    return (buf[0] << 8) | buf[1];
}

float LM75A::readTemperature() {
    uint16_t raw = read16(0x00);
    int16_t temp = raw >> 7;
    if (temp & 0x0100) temp |= 0xFE00;
    return temp * 0.5f;
}
