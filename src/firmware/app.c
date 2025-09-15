#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "app.h"
#include "adc.h"
#include "pwm.h"

#define SPEED_SPEC_MIN   77  //  30%
#define SPEED_SPEC_MAX  255  // 100%
#define SPEED_USE_MIN    26  //  10%
#define SPEED_USE_MAX   191  //  75%

void startup(void);

void main(void) {
    init();
    pwm_init();
    adc_init();

    startup();

    uint16_t temperatureSum = (uint16_t)(adc_get_temperature()) << 3;  // 8x running average
    while(true) {
        CLRWDT();

        uint8_t temperatureNew = adc_get_temperature();  // measure new temperature
        uint8_t temperatureAvg = (uint8_t)(temperatureSum >> 3);  // take average from previous run
        temperatureSum = (temperatureSum - temperatureAvg) + temperatureNew;  // add new measure in

        uint8_t pwm;
        if (temperatureAvg < 40) {  // minimum fan speed up to 40 °C
            pwm = SPEED_USE_MIN;
        } else if (temperatureAvg < 80) {  // linear increase 40-80 °C
            uint8_t scaleSpeedPerC = (SPEED_USE_MAX - SPEED_USE_MIN) / 40;
            uint8_t scaleT = temperatureAvg - 40;
            pwm = SPEED_USE_MIN + scaleSpeedPerC * scaleT;
        } else {  // max speed if higher than 80 °C
            pwm = SPEED_SPEC_MAX;
        }

        pwm_set_all(pwm);
        __delay_ms(100);  // delay speed changes a bit
    }
}

void startup(void) {
    // each fan:
    // * starts at 30% for 1.5 seconds
    // * goes to full speed for 0.5s
    // * and then goes down to 10%.

    CLRWDT();
    pwm_set_individual(SPEED_SPEC_MIN, 0, 0, 0);
    __delay_ms(500);

    CLRWDT();
    pwm_set_individual(SPEED_SPEC_MIN, SPEED_SPEC_MIN, 0, 0);
    __delay_ms(500);

    CLRWDT();
    pwm_set_individual(SPEED_SPEC_MIN, SPEED_SPEC_MIN, SPEED_SPEC_MIN, 0);
    __delay_ms(500);

    CLRWDT();
    pwm_set_individual(SPEED_SPEC_MAX, SPEED_SPEC_MIN, SPEED_SPEC_MIN, SPEED_SPEC_MIN);
    __delay_ms(500);

    CLRWDT();
    pwm_set_individual(SPEED_USE_MIN, SPEED_SPEC_MAX, SPEED_SPEC_MIN , SPEED_SPEC_MIN);
    __delay_ms(500);

    CLRWDT();
    pwm_set_individual(SPEED_USE_MIN, SPEED_USE_MIN, SPEED_SPEC_MAX, SPEED_SPEC_MIN);
    __delay_ms(500);

    CLRWDT();
    pwm_set_individual(SPEED_USE_MIN, SPEED_USE_MIN, SPEED_USE_MIN, SPEED_SPEC_MAX);
    __delay_ms(500);

    CLRWDT();
    pwm_set_all(SPEED_USE_MIN);
}

void init(void) {
    // Interrupt Control
    GIE = 0;               // Disables all interrupts

    // Oscillator Control
    OSCCON = 0b01111011;   // 16 MHz
}
