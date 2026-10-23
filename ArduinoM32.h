#ifndef __ArduinoM32_H
#define __ArduinoM32_H
#include "stm32f10x.h"
#define HIGH  1
#define LOW   0
//简写定义
#define G_A  GPIOA
#define G_B  GPIOB
#define G_C  GPIOC
typedef enum {
    OUT_PP,      // 推挽输出（LED）
    OUT_OD,      // 开漏输出（I2C OLED）
    AF_PP,       // 复用推挽（PWM 电机/串口）
    AF_OD,       // 复用开漏
    IN_PU,       // 上拉输入（按键接GND）
    IN_PD,       // 下拉输入（按键接VCC）
    IN_FLOAT,    // 浮空输入
    AIN,         // 模拟输入（ADC）
} PinMode_t;
//初始化引脚
void PinMode(GPIO_TypeDef* GPIOx,uint16_t PinNum,PinMode_t Mode);
//写
void DigitalWrite(GPIO_TypeDef* GPIOx, uint16_t PinNum, uint8_t Level);
//读
uint8_t DigitalRead (GPIO_TypeDef* GPIOx, uint16_t PinNum);

#endif
