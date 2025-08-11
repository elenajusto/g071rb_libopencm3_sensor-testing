
# Description
 Talking to sensors to practice embedded and apply some robotics concepts (Kalman filtering and odometry). 

This project is using an STM32G071RB which uses the ARM Cortex M0+.

This project uses the libopencm3 framework.

Repository is based off the libopencm3 template: https://github.com/libopencm3/libopencm3-template.git

# Commands
Flashing program to microcontroller:
```sh
st-flash --reset write <file.bin> 0x8000000
```

Checking connected programmers:
```sh
st-info --probe
```

# Objectives
## Objective Set 0
- Setup development environment outside of STM32CubeIDE [X]
- Confirm ability to flash programs to microcontroller (blinky) [X]
- Test logging ability (USART) [-]
- Test I2C ability (I2C) [-]

## Objective Set 1
- Interface to the BMI160 via I2C [-]
- Record data from the BMI160 [-]
- Convert raw data into meaningful quantity [-]
- Log those quantities and raw data [-]

## Objective Set 2
- Interface with an additional sensor via I2C (I have a knockoff MPU6050) [-]
- Record data from the additional sensor simultaenously (or near simultaenously) [-]
- Convert the raw data from the additional sensor into meaningful qauntity [-]
- Log quantity and raw data [-]

## Objective Set 3
- Use Kalman Filtering to fuse the quantity values from the two sensors to get an accurate reading [-]

# Branches
## project/serial-print
- Figure out how to use the USART peripheral
- Enable its operation with libopencm3
- Send test messages back to host from the microcontroller

## project/app-main
- Reorganise project directory for further development
- Serve as main branch for further iterations

# Notes
## USART
### Available USART Peripherals
* USART1 - Full featured
* USART2 - Full featured
* USART3 - Basic
* USART4 - Basic   
* LPUART1 - Low Power

Note: This project uses USART2 (connected to ST-LINK Virtual COM port)

### USART Pin Functions
* USART_TX - Transmit pin (Output)
* USART_RX - Receive pin (Input)
* USART_CTS - Clear To Send
* USART_RTS - Ready To Send
* USART_DE - Driver Enable
* USART_CK - Clock
* USART_NSS - Slave Select

Note: For basic serial communication, we only need:
* TX (PA2) - Connected to ST-LINK Virtual COM RX
* RX (PA3) - Connected to ST-LINK Virtual COM TX

### USART Setup Procedure
1. Enable USART clock in RCC
2. Configure GPIO pins for USART
3. Configure USART parameters (baud rate, data bits, etc.)
4. Enable USART

# Reference
- Getting started with libopencm3 for STM programming: https://youtu.be/YEGKD6JQJyM?si=YNFPlLzbZi3yefhI
- Explanation on UART: https://youtu.be/V6m2skVlsQI?si=Plv4Vpjfjrmk72-c