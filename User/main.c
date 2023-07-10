#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
#include "PWM.h"
#include "Ctrl6612.h"

int16_t Num;
uint8_t Speed;

int main(void)
{
	OLED_Init();
	Encoder_Init();
	CTRL_Init();
	
	OLED_ShowString(1, 1, "Speed:");
	OLED_ShowString(2, 1, "RPM:");

	
	while (1)
	{
		Num += Encoder_Get();
		//OLED_ShowSignedNum(2, 7, Num, 3);
		if (Num > 100)
		{
			Speed = 100;
		} else if (Num < 0)
		{
			Speed = 0;
		} else{
			Speed = Num;
		}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1, 7, Speed, 3);
	}
}
