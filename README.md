# AuxFanController

Allows for PWM control of 4 fans based on the on-board temperature reaading.

Features:
* supports up to 3 fans
* temperature controlled speed
* short startup burst to avoid stall


## PWM Ranges

| Temperature |  PWM                      |
|:-----------:|---------------------------|
|   < 40 °C   |  10%                      |
|  40-60 °C   |  10-50% (linear increase) |
|  60-70 °C   |  50%                      |
|    >70 °C   | 100%                      |
