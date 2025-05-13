#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "lm75a.h"

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5
#define LM75A_ADDR 0x48

int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    LM75A sensor(I2C_PORT, LM75A_ADDR);
    sensor.begin();

    while (true) {
        float temp = sensor.readTemperature();
        printf("Temperature: %.2f °C\n", temp);
        sleep_ms(1000);
    }
}
