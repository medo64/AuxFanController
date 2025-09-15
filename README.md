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
|  40-80 °C   |  10-75% (linear increase) |
|    >80 °C   | 100%                      |
