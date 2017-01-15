/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO(R)
**                STMicroelectronics STM32F4xx Standard Peripherals Library
**
**  Distribution: The file is distributed "as is", without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. This file may only be built (assembled or compiled and linked)
**  using the Atollic TrueSTUDIO(R) product. The use of this file together
**  with other tools than Atollic TrueSTUDIO(R) is not permitted.
**
*****************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32f4xx_i2c.h"
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */
#include "defines.h"
#include "tm_stm32f4_mpu6050.h"
/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  /**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used. 
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates 
  *  SCB->VTOR register.  
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /* TODO - Add your application code here */
	TM_MPU6050_t MPU6050_Data0;
	TM_MPU6050_t MPU6050_Data1;
	uint8_t sensor1 = 0, sensor2 = 0;
	char str[120];
	/* Initialize MPU6050 sensor 0, address = 0xD0, AD0 pin on sensor is low */
	if (TM_MPU6050_Init(&MPU6050_Data0, TM_MPU6050_Device_0, TM_MPU6050_Accelerometer_8G, TM_MPU6050_Gyroscope_250s) == TM_MPU6050_Result_Ok) {
		/* Display message to user */
		//sprintf("MPU6050 sensor 0 is ready to use!\n");

		/* Sensor 1 OK */
		sensor1 = 1;
	}


  /* Infinite loop */
  while (1)
  {
	  if (sensor1) {
	  				/* Read all data from sensor 1 */
	  				TM_MPU6050_ReadAll(&MPU6050_Data0);

	  				/* Format data */
	  				/*
	  				sprintf(str, "1. Accelerometer\n- X:%d\n- Y:%d\n- Z:%d\nGyroscope\n- X:%d\n- Y:%d\n- Z:%d\nTemperature\n- %3.4f\n\n\n",
	  					MPU6050_Data0.Accelerometer_X,
	  					MPU6050_Data0.Accelerometer_Y,
	  					MPU6050_Data0.Accelerometer_Z,
	  					MPU6050_Data0.Gyroscope_X,
	  					MPU6050_Data0.Gyroscope_Y,
	  					MPU6050_Data0.Gyroscope_Z,
	  					MPU6050_Data0.Temperature
	  				);*/
	  	  }

}

}
/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
