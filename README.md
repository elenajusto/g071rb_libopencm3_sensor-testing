
# Description
 Talking to sensors to practice embedded and apply some robotics concepts (Kalman filtering and odometry). 

This project is using an STM32G071RB which uses the ARM Cortex M0+.

This project uses the libopencm3 framework.

Repository is based off the libopencm3 template: https://github.com/libopencm3/libopencm3-template.git

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