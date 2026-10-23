#include "ArduinoM32.h"//说明书
//初始化引脚
//////////////////////
void PinMode(GPIO_TypeDef* GPIOx,uint16_t PinNum,PinMode_t Mode){
    GPIOMode_TypeDef st_mode;
    switch (Mode) {
        case OUT_PP:    st_mode = GPIO_Mode_Out_PP;        break;
        case OUT_OD:    st_mode = GPIO_Mode_Out_OD;        break;
        case AF_PP:     st_mode = GPIO_Mode_AF_PP;         break;
        case AF_OD:     st_mode = GPIO_Mode_AF_OD;         break;
        case IN_PU:     st_mode = GPIO_Mode_IPU;           break;
        case IN_PD:     st_mode = GPIO_Mode_IPD;           break;
        case IN_FLOAT:  st_mode = GPIO_Mode_IN_FLOATING;   break;
        case AIN:       st_mode = GPIO_Mode_AIN;           break;
        default: return;
    }
    //开时钟
    uint32_t rcc;
    if      (GPIOx == GPIOA) rcc = RCC_APB2Periph_GPIOA;
    else if (GPIOx == GPIOB) rcc = RCC_APB2Periph_GPIOB;
    else if (GPIOx == GPIOC) rcc = RCC_APB2Periph_GPIOC;
    else return;
    RCC_APB2PeriphClockCmd(rcc,ENABLE);
    //开引脚
    //////////////////////////////////
    GPIO_InitTypeDef cfg;
    cfg.GPIO_Pin   = (uint16_t)1 << PinNum;
    cfg.GPIO_Mode  = st_mode;
    cfg.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &cfg);


}
//写
/////////////////////////////////////////
void DigitalWrite(GPIO_TypeDef* GPIOx, uint16_t PinNum, uint8_t Level){
    uint16_t mask=(uint16_t)1<<PinNum;//把数字变成电子掩码（挪它！）
    if(Level==1){
          GPIO_SetBits(GPIOx,mask);
      }
      if(Level==0){
          GPIO_ResetBits(GPIOx,mask);
      }
}
//读
/////////////////////////////////////////
uint8_t DigitalRead(GPIO_TypeDef* GPIOx, uint16_t PinNum) {
      return GPIO_ReadInputDataBit(GPIOx,(uint16_t)1<<PinNum);
  }
