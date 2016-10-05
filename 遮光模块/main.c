/*****************************************************************************
*  项目名称  ： 敲击传感器模块
*    作者    ： 郑朋桥
*    时间    ： 2016/08/10
******************************************************************************/

/*****************************************************************************
*  添加头文件
******************************************************************************/
#include "ioCC2530.h"
#include "LED.h"

#define DATA_PIN P0_7        //定义P0.7口为传感器的输入端

void pinInit()
{
  P0SEL &= ~(1 << 7);
  P0DIR &= ~(1 << 7);
}
void main()
{
  ledInit();
  pinInit();
  while(1)
  {
    
    if(DATA_PIN == 1)
    {        
         led1On();
    }
    else
    {
         led1Off();
    }
  }
}

