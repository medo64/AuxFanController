## AuxFanController Parts

|      |                           |
|------|---------------------------|
| Size | 26.0 x 20.0 mm ~ 0.9 sqin |


### Parts

|  # | Part name                                    | RefDes  | DigiKey PN                   |
|---:|----------------------------------------------|---------|------------------------------|
|  2 | C 100nF X7R 50V (0805)                       | C1-C2   | 478-5311-1-ND                |
|  1 | C 1uF X7R 25V (0805)                         | C3      | 1276-1066-1-ND               |
|  1 | J MC 1,5/ 2-G-3,81                           | J1†     | 277-1206-ND -or- 277-1221-ND |
|  3 | J Fan PWM (4w)                               | J2-J4   | WM4330-ND                    |
|  1 | U Micro [PIC12F1501] (SOIC-8)                | U1      | PIC12F1501-I/SN-ND           |
|  1 | U Temperature Analog [MCP9701A] (SOT23-3)    | U2      | MCP9701AT-E/TTCT-ND          |
|  1 | VR Linear 5V 100mA [AS78L05RTR-E1] (SOT89-3) | VR1     | AS78L05RTR-E1DICT-ND         |
|  1 | P Phoenix MC 1,5/ 2-ST-3,81 (2w)             | P1      | 277-1161-ND                  |

† Alternate PN is for vertical variant


### Pin Usage

|  # | Pin | ICSP | Function | Description        |
|---:|:---:|------|----------|--------------------|
|  1 | Vdd | Vdd  |          |                    |
|  2 | RA5 |      |          |                    |
|  3 | RA4 |      | PWM3     | Fan 3 Control      |
|  4 | RA3 | Vpp  |          |                    |
|  5 | RA2 |      | PWM1     | Fan 1 Control      |
|  6 | RA1 | Clk  | AN1      | Temperature sensor |
|  7 | RA0 | Dat  | PWM2     | Fan 2 Control      |
|  8 | Vss | Vss  |          |                    |
