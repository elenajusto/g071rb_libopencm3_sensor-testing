
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

# Objective Set 1
- Interface to the BMI160 via I2C
- Record data from the BMI160
- Convert raw data into meaningful quantity
- Log those quantities and raw data

# Objective Set 2
- Interface with an additional sensor via I2C (I have a knockoff MPU6050)
- Record data from the additional sensor simultaenously (or near simultaenously)
- Convert the raw data from the additional sensor into meaningful qauntity
- Log quantity and raw data

# Objective Set 3
- Use Kalman Filtering to fuse the quantity values from the two sensors to get an accurate reading

# project/serial-print
- Figure out how to use the USART peripheral
- Enable its operation with libopencm3
- Send test messages back to host from the microcontroller

## USART Notes
- The STM32G071RB has access to the following USART peripherals:
-- USART1 - Full
-- USART2 - Full
-- USART3 - Basic
-- USART4 - BASIC   
-- LPUART1 - LP

For purposes of this project I will only be using USART1.

- The STM32G071RB USART pins are as follows:
-- USART_RX
-- USART_TX
-- USART_CTS
-- USART_RTS
-- USART_DE
-- USART_CK
-- USAT_NSS

Since I am only interested in sending basic text messages to the host PC, I will focus only on USART_RX and USART_TX. Where:
- USART_RX: Input
- USART_TX: Output

## USART Procedure
1. Turn USART1 on


# Reference
- Getting started with libopencm3 for STM programming: https://youtu.be/YEGKD6JQJyM?si=YNFPlLzbZi3yefhI