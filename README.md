# ArduinoM32

把 STM32F103 的 GPIO 封装成 Arduino 风格的函数——点灯、读按键，一行搞定。

## 三个函数

| 函数 | 对应 Arduino | 作用 |
|------|-------------|------|
| `PinMode(口, 引脚, 模式)` | `pinMode()` | 初始化引脚（自动开时钟） |
| `DigitalWrite(口, 引脚, 电平)` | `digitalWrite()` | 输出高 / 低 |
| `DigitalRead(口, 引脚)` | `digitalRead()` | 读输入电平 |

## 快速上手（点板载 LED，PC13 低电平亮）

```c
#include "stm32f10x.h"
#include "ArduinoM32.h"

int main(void) {
    PinMode(G_C, 13, OUT_PP);        // PC13 推挽输出
    while (1) {
        DigitalWrite(G_C, 13, LOW);  // 亮
        // 延时...
        DigitalWrite(G_C, 13, HIGH); // 灭
        // 延时...
    }
}
```

## 端口 / 引脚 / 电平

- 端口简写：`G_A` `G_B` `G_C`（= GPIOA / GPIOB / GPIOC）
- 引脚写**数字** 0~15，内部自动 `1 << n` 转成掩码
- 电平：`HIGH`(1) / `LOW`(0)

## 模式（PinMode 第三参数）

| 模式 | 含义 | 典型用途 |
|------|------|---------|
| `OUT_PP` | 推挽输出 | LED、普通输出 |
| `OUT_OD` | 开漏输出 | I2C |
| `AF_PP` | 复用推挽 | 串口 / PWM |
| `AF_OD` | 复用开漏 | — |
| `IN_PU` | 上拉输入 | 按键接 GND |
| `IN_PD` | 下拉输入 | 按键接 VCC |
| `IN_FLOAT` | 浮空输入 | 外部已有上下拉 |
| `AIN` | 模拟输入 | ADC |

## 依赖

- STM32F103C8（Blue Pill）
- Keil5 MDK + 标准外设库（SPL，需要 `stm32f10x.h`）

## 注意

- **PA13 / PA14 是 SWD 调试口**，别配成普通 GPIO，否则烧不进程序。
- 只有 A / B / C 三个端口（F103C8 没有 D / E）。

## 目录

```
ArduinoM32/
├── ArduinoM32.h    声明 + 枚举
├── ArduinoM32.c    实现
└── README.md
```
