/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
RCC_OscInitTypeDef RCC_OscInitStruct;
RCC_ClkInitTypeDef RCC_ClkInitStruct;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#ifndef __UUID_H
#define __UUID_H
//#define STM32_UUID ((uint32_t *)0x1FF0F420)
#define STM32_UUID ((uint32_t *)UID_BASE)
#endif //__UUID_H

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
  char uart2Data[24] = "Connected to UART Two\r\n";
   HAL_UART_Transmit(&huart2, (uint8_t *)&uart2Data,sizeof(uart2Data), 0xFFFF);

 	uint8_t len = 0;
 	char devidString[14] = {0};
 	uint32_t idcode = DBGMCU->IDCODE & 0xFFF;
 	//len += sprintf(devidString, "Device ID: 0x%lX\r\n", idcode);
 	//printf("%s", devidString);
 	switch (idcode)
 	{
	case 0x410: len += sprintf(devidString+len, "stm32f1xx medium-density\r\n"); break;
	case 0x411: len += sprintf(devidString+len, "stm32f2xx\r\n"); break;
	case 0x412: len += sprintf(devidString+len, "stm32f1xx low-density\r\n"); break;
	case 0x413: len += sprintf(devidString+len, "stm32f4xx\r\n"); break;
	case 0x414: len += sprintf(devidString+len, "stm32f1xx high-density\r\n"); break;
	case 0x415: len += sprintf(devidString+len, "stm32l4xx\r\n"); break;
	case 0x416: len += sprintf(devidString+len, "stm32l1xx medium-density\r\n"); break;
	case 0x417: len += sprintf(devidString+len, "stm32l0xx\r\n"); break;
	case 0x418: len += sprintf(devidString+len, "stm32f1xx connectivity line\r\n"); break;
	case 0x419: len += sprintf(devidString+len, "stm32f4xx high-density\r\n"); break;
	case 0x420: len += sprintf(devidString+len, "stm32f1xx value line low/medium-density\r\n"); break;
	case 0x421: len += sprintf(devidString+len, "stm32f446\r\n"); break;
	case 0x422: len += sprintf(devidString+len, "stm32f3xx\r\n"); break;
	case 0x423: len += sprintf(devidString+len, "stm32f4xx low power\r\n"); break;
	case 0x425: len += sprintf(devidString+len, "stm32l0xx cat. 2\r\n"); break;
	case 0x427: len += sprintf(devidString+len, "stm32l1xx medium-density/plus\r\n"); break;
	case 0x428: len += sprintf(devidString+len, "stm32f1xx value line high-density\r\n"); break;
	case 0x429: len += sprintf(devidString+len, "stm32l1xx cat. 2\r\n"); break;
	case 0x430: len += sprintf(devidString+len, "stm32f1xx xl-density\r\n"); break;
	case 0x431: len += sprintf(devidString+len, "stm32f411re\r\n"); break;
	case 0x432: len += sprintf(devidString+len, "stm32f37x\r\n"); break;
	case 0x433: len += sprintf(devidString+len, "stm32f4xx de\r\n"); break;
	case 0x434: len += sprintf(devidString+len, "stm32f4xx dsi\r\n"); break;
	case 0x435: len += sprintf(devidString+len, "stm32l43x\r\n"); break;
	case 0x436: len += sprintf(devidString+len, "stm32l1xx high-density\r\n"); break;
	case 0x437: len += sprintf(devidString+len, "stm32l152re\r\n"); break;
	case 0x438: len += sprintf(devidString+len, "stm32f334\r\n"); break;
	case 0x439: len += sprintf(devidString+len, "stm32f3xx small\r\n"); break;
	case 0x440: len += sprintf(devidString+len, "stm32f0xx\r\n"); break;
	case 0x441: len += sprintf(devidString+len, "stm32f412\r\n"); break;
	case 0x442: len += sprintf(devidString+len, "stm32f09x\r\n"); break;
	case 0x444: len += sprintf(devidString+len, "stm32f0xx small\r\n"); break;
	case 0x445: len += sprintf(devidString+len, "stm32f04x\r\n"); break;
	case 0x446: len += sprintf(devidString+len, "stm32f303 high-density\r\n"); break;
	case 0x447: len += sprintf(devidString+len, "stm32l0xx cat. 5\r\n"); break;
	case 0x448: len += sprintf(devidString+len, "stm32f0xx can\r\n"); break;
	case 0x449: len += sprintf(devidString+len, "stm32f7\r\n"); break;
	case 0x451: len += sprintf(devidString+len, "stm32f7xx\r\n"); break;
	case 0x457: len += sprintf(devidString+len, "stm32l011\r\n"); break;
	case 0x458: len += sprintf(devidString+len, "stm32f410\r\n"); break;
	case 0x463: len += sprintf(devidString+len, "stm32f413\r\n"); break;
	default: len += sprintf(devidString+len, "unknown device\r\n");
 	}
 	printf("%s", devidString);
 	//GUI_DispString(devidString);

 	len = 0;
 	uint32_t cpuid = SCB->CPUID;
 	uint32_t var, pat;
 	pat = (cpuid & 0x0000000F);
 	var = (cpuid & 0x00F00000) >> 20;
 	uint32_t mvfr0;
 	char cpuString[24] = {0};

 	//len += sprintf(cpuString, "CPU ID: 0x");
 	//len += sprintf(cpuString+len, "%lX\r\n", cpuid);

 	if ((cpuid & 0xFF000000) == 0x41000000) // ARM
 		{
 			len += sprintf(cpuString+len, "ARM ");
 			switch((cpuid & 0x0000FFF0) >> 4)
 				{
 					case 0xC20 : len += sprintf(cpuString+len, "Cortex M0 r%ldp%ld\r\n", var, pat); break;
 					case 0xC60 : len += sprintf(cpuString+len, "Cortex M0+ r%ldp%ld\r\n", var, pat); break;
 					case 0xC21 : len += sprintf(cpuString+len, "Cortex M1 r%ldp%ld\r\n", var, pat); break;
 					case 0xC23 : len += sprintf(cpuString+len, "Cortex M3 r%ldp%ld\r\n", var, pat); break;
 					case 0xC24 : len += sprintf(cpuString+len, "Cortex M4 r%ldp%ld\r\n", var, pat); break;
 					case 0xC27 : len += sprintf(cpuString+len, "Cortex M7 r%ldp%ld\r\n", var, pat); break;

 					default : len += sprintf(cpuString+len, "Unknown CORE\r\n");
 				}
 		}

     mvfr0 = *(volatile uint32_t *)0xE000EF40;

     if (mvfr0 > 0){
 	 //mvfr0 = SCB->MVFR0;
     /*
     printf("FPCCR: %08lX\r\n", *(volatile uint32_t *)0xE000EF34); // 0xC0000000
     printf("FPCAR: %08lX\r\n", *(volatile uint32_t *)0xE000EF38);
     printf("FPDSCR: %08lX\r\n", *(volatile uint32_t *)0xE000EF3C);
     printf("MVFR0: %08lX\r\n", *(volatile uint32_t *)0xE000EF40); // 0x10110021 single or 10110221 double
     printf("MVFR1: %08lX\r\n", *(volatile uint32_t *)0xE000EF44); // 0x11000011 or 12000011
     printf("MVFR2: %08lX\r\n", *(volatile uint32_t *)0xE000EF48); // 0x00000040
	 */
     switch(mvfr0)
     	 {
     	 case 0x10110021 : len += sprintf(cpuString+len, "Single-precision FPU\r\n"); break;
     	 case 0x10110221 : len += sprintf(cpuString+len, "Double-precision FPU\r\n"); break;
     	 //default : len += sprintf(cpuString+len, "No FPU\r\n");
     	 default: ;
     	 }
     }
 	printf("%s",cpuString);

 	len = 0;
 	char flashString[14] = {0};
 	//len += sprintf(flashString, "%d KB Flash\r\n", *((unsigned short *)0x1FF0F442));
 	len += sprintf(flashString, "%d KB Flash\r\n", *((unsigned short *)FLASHSIZE_BASE));
 	printf("%s", flashString);

 	len = 0;
 	char idString[44] = {0};
 	len += sprintf(idString, "Device Unique ID: ");
 	uint32_t idPart1 = STM32_UUID[0];
 	uint32_t idPart2 = STM32_UUID[1];
 	uint32_t idPart3 = STM32_UUID[2];
 	len += sprintf(idString+len, "%08lX %08lX %08lX\r\n", idPart1, idPart2, idPart3);
 	printf("%s", idString);

 	printf("Oscillators and clocks\r\n");
 	printf("----------------------\r\n");
 	//HAL_RCC_GetOscConfig(&RCC_OscInitStruct);
 	//printf("      Oscillator type: %08lX\r\n", RCC_OscInitStruct.OscillatorType);

 	if (RCC_OscInitStruct.HSEState > 0) {
 	printf("            HSE State: %08lX\r\n", RCC_OscInitStruct.HSEState);
 	//printf("          HSE Prediv1: %08lX\r\n", RCC_OscInitStruct.HSEPredivValue);
 	  } else {
 	printf("            HSE State: Off\r\n");
 	}

 	if (RCC_OscInitStruct.LSEState > 0) {
 	printf("            LSE State: %08lX\r\n", RCC_OscInitStruct.LSEState);
 	  } else {
    printf("            LSE State: Off\r\n");
 	}

 	if (RCC_OscInitStruct.HSIState > 0) {
 	printf("            HSI State: On\r\n");
 	printf("HSI Calibration value: %08lX\r\n", RCC_OscInitStruct.HSICalibrationValue);
 	  } else {
    printf("            HSI State: Off\r\n");
 	}

 	if (RCC_OscInitStruct.LSIState > 0) {
 	printf("            LSI State: On\r\n");
 	  } else {
 	printf("            LSI State: Off\r\n");
 	}

 	if (RCC_OscInitStruct.PLL.PLLState > 0) {
 	printf("           PLL Source: %08lX\r\n", RCC_OscInitStruct.PLL.PLLSource);
 	//printf("       PLL Multiplier: %08lX\r\n", RCC_OscInitStruct.PLL.PLLMUL);
 	}

	uint32_t latency;
	HAL_RCC_GetClockConfig(&RCC_ClkInitStruct, &latency);
	//printf("           Clock Type: %08lX\r\n", RCC_ClkInitStruct.ClockType);
	printf("\r\n");

	printf("        SYSCLK Source: ");
	switch (RCC_ClkInitStruct.SYSCLKSource)
	{
		case 0 : printf("HSI\r\n"); break;
		case 1 : printf("HSE\r\n"); break;
		case 2 : printf("PLL\r\n"); break;
		default : printf("??\r\n");
	}

	printf("       AHBCLK Divider: ");
	switch (RCC_ClkInitStruct.AHBCLKDivider)
	{
	case RCC_SYSCLK_DIV1 : printf("1\r\n"); break;
	case RCC_SYSCLK_DIV2 : printf("2\r\n"); break;
	case RCC_SYSCLK_DIV4 : printf("4\r\n"); break;
	case RCC_SYSCLK_DIV8 : printf("8\r\n"); break;
	case RCC_SYSCLK_DIV16 : printf("16\r\n"); break;
	case RCC_SYSCLK_DIV64 : printf("64\r\n"); break;
	case RCC_SYSCLK_DIV128 : printf("128\r\n"); break;
	case RCC_SYSCLK_DIV256 : printf("256\r\n"); break;
	case RCC_SYSCLK_DIV512 : printf("512\r\n"); break;
	}

	printf("      APB1CLK Divider: ");
	switch (RCC_ClkInitStruct.APB1CLKDivider)
	{
	case RCC_CFGR_PPRE1_DIV1 : printf("1\r\n"); break;
	case RCC_CFGR_PPRE1_DIV2 : printf("2\r\n"); break;
	case RCC_CFGR_PPRE1_DIV4 : printf("4\r\n"); break;
	case RCC_CFGR_PPRE1_DIV8 : printf("8\r\n"); break;
	case RCC_CFGR_PPRE1_DIV16 : printf("16\r\n"); break;
	}


	printf("      APB2CLK Divider: ");
	switch (RCC_ClkInitStruct.APB2CLKDivider)
	{
	case RCC_CFGR_PPRE1_DIV1 : printf("1\r\n"); break;
	case RCC_CFGR_PPRE1_DIV2 : printf("2\r\n"); break;
	case RCC_CFGR_PPRE1_DIV4 : printf("4\r\n"); break;
	case RCC_CFGR_PPRE1_DIV8 : printf("8\r\n"); break;
	case RCC_CFGR_PPRE1_DIV16 : printf("16\r\n"); break;
	}

	printf("        Flash latency: %lX\r\n", latency);

 	len = 0;
 	char sysclkString[29] = {0};
 	len += sprintf(sysclkString, "    System core clock: ");
 	len += sprintf(sysclkString+len, "%lu\r\n", HAL_RCC_GetSysClockFreq());
 	printf("%s", sysclkString);

 	printf("\r\n");
 	printf("Core registers\r\n");
 	printf("--------------\r\n");
	register int r0 asm ("r0");
	printf("           r0: 0x%08X\r\n", r0);
	register int r1 asm ("r1");
	printf("           r1: 0x%08X\r\n", r1);
	register int r2 asm ("r2");
	printf("           r2: 0x%08X\r\n", r2);
	register int r3 asm ("r3");
	printf("           r3: 0x%08X\r\n", r3);
	register int r4 asm ("r4");
	printf("           r4: 0x%08X\r\n", r4);
	register int r5 asm ("r5");
	printf("           r5: 0x%08X\r\n", r5);
	register int r6 asm ("r6");
	printf("           r6: 0x%08X\r\n", r6);
	register int r7 asm ("r7");
	printf("           r7: 0x%08X\r\n", r7);
	register int r8 asm ("r8");
	printf("           r8: 0x%08X\r\n", r8);
	register int r9 asm ("r9");
	printf("           r9: 0x%08X\r\n", r9);
	register int r10 asm ("r10");
	printf("          r10: 0x%08X\r\n", r10);
	register int r11 asm ("r11");
	printf("          r11: 0x%08X\r\n", r11);
	register int r12 asm ("r12");
	printf("          r12: 0x%08X\r\n", r12);
	register int sp asm ("sp");
	printf("stack pointer: 0x%08X\r\n", sp);
	register int lr asm ("lr");
	printf("link register: 0x%08X\r\n", lr);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART2 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/