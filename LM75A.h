#ifndef LM75A_H
#define LM75A_H

#include "hardware/i2c.h"
#include "pico/stdlib.h"

class LM75A {
public:
    LM75A(i2c_inst_t* i2c_port, uint8_t address);
    void begin();
    float readTemperature();

private:
    i2c_inst_t* i2c;
    uint8_t addr;
    uint16_t read16(uint8_t reg);
};

#endif

