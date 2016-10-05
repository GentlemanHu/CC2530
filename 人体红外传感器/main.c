/*****************************************************************************
*  项目名称  ： 人体红外传感器
*    作者    ： 郑朋桥
*    时间    ： 2016/08/10
******************************************************************************/


/*****************************************************************************
*  添加头文件
******************************************************************************/
#include <ioCC2530.h>
#include "LED.h"
#include "INTUART.h"
#include "LCD.h"
#define DATA_PIN P0_4        //定义P0.4口为传感器的输入端

/*****************************************************************************
*  函数介绍  ： 不精确延时函数
*            ： 
*    参数    ： 毫秒数
*   返回值   ： 无
******************************************************************************/
void delayMS(int ms)
{
  int i,j;
  for(i = 0; i < ms; i++)
  {
    for(j = 0; j < 535; j++);
  }
}


void main()
{
  setSystemCLK();
  ledInit();
  initUart();
  LCD_Init();                      //oled 初始化  
  LCD_CLS();
  led2On();
  while(1)
  {
    
    if(DATA_PIN)
    {
         sendString("ON",2);
         sendNewLine();
         LCD_P16x16Ch(48,2,32);  //点阵显示
         LCD_P16x16Ch(64,2,33);  //点阵显示
         led1On();
    }
    else
    {
         sendString("OFF",3);
         sendNewLine();
         LCD_P16x16Ch(48,2,34);  //点阵显示
         LCD_P16x16Ch(64,2,33);  //点阵显示
         led1Off();
    }
    
    delayMS(100);
  }
}
