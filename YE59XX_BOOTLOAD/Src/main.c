/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *

  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "bsp.h"
#include "app.h"
#include "bsp_flash.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
struct PARAMETER Parameter;
struct  CONFIG  config={
    .vaildsign = 0xAA55, //	uint16_t vaildsign;
	.baundrate =  1,//uint8_t baundrate;    
	.addr = 1,//uint8_t addr; 
	.SNnumber = {'W',100,0,0,0x31,0x00,0x11,0x01},//0x6275110032120001,//0x6275110032120003,//0x5955125011120002, 03 yec-test 101
	.parity = 0, //uint8_t parity;		// =0 : n,8,1   =1: o,8,1  =2: e,8,1  
	.floatscale = {0.03333f,0.0075756f,0.0075756f,1,1,1,1,1,1,1,1,1},
	.DisplayMode = 0, //uint8_t DisplayMode;  // ???? = 0 ?? =1 ??
	.interface_type = {TYPE_IEPE,TYPE_IEPE,TYPE_IEPE,TYPE_IEPE,TYPE_NONE,TYPE_IEPE,TYPE_IEPE,TYPE_IEPE,TYPE_IEPE,1,1,1}, //uint8_t interface_type[12]; // 
	.unit = {UNIT_M_S2,UNIT_TEMP,UNIT_M_S2,UNIT_M_S2,UNIT_M_S2,UNIT_M_S2,1,1,1,1,1,1},//uint8_t unit[12];  // 
	.floatrange = {3000,3000,3000,3000,1000,1000,1000,1000,10000,10000,10000,10000},//uint32_t scale[12]; // 
	.floatadjust = {0.0f,0.0f,0.0f,0.0f,1250.f,0,0,0,8192,8192,8192,8192},//uint32_t adjust[12]; // 
	//	{0,1,2,~0,~0,~0,~0,~0,3,4,5,6},//uint16_t interface_addr[12]; // modbus  
	.alarmgate = {100,100,100,100,100,100},//	float alarmgate[12]; // float 
	.floatadc =  {1.01f,1.0f,1.0f,1.0f,1.0f,1.0f},
	.means = 0,//uint8_t means	;// 
	.means_times =  1,//uint16_t means_times; // 
	.freq = 20000,//uint16_t freq;  //  Hz
	.avr_count = 4096,//uint16_t avr_count;
	.reflash = 2, // uint8_t reflash; // 
	.din_addr = ~0, //	uint16_t din_addr;  // 
	.dout_addr = ~0, // uint16_t dout_addr; //  
	.force_gate =  300,  // 
	.force_backlash =  30, // uint32_t force_gate,force_backlash,   // 
	.max_addr0 = ~0,
	.max_addr1 = ~0, 	//	uint16_t max_addr0,max_addr1; 
	.vlpsseconds = 300,
	.vlprseconds = 300,
	.runseconds =  300,
	.pga = 0x4a,                          //PGA
	.workcycleseconds =  30,              
	.fangda = 0x0100,                     
	.boardset = 0x11,                     // 
	.ADtime = 0x01,                       //AD
	.ADfrequence = 8192,                  //AD
	.alarmminutetime = 0x58B6A4C3,        //
	.FLASH_WRADDR = 0,                    //
	.DataToBoardMode = PARAMETERMODE,
	.DataToSendChannel =  0x1F,           //
	.DHCP = 1, //DHCP
	.APssid =   "yec-test",//"TP-LINK_FF18E4",//"Tenda_4F7AC0",//"yec-test",//"wifi-sensor",//"Tenda_1E6760",//"TP-LINK-SCZZB",//"yec-test",//"wifi-sensor",//"TP-LINK-sczzb2",//"hold-704",//"wifi-test1",//"yec-test",//"wifi-test",//"yec-test",//"zl_sensor",/////"yec-test",//"test3",//"qiangang2", //"qiangang1", //"qiangang1", /////
	.APpassword = "",//"",//"china-yec",//"",//"wifi-sensor",//"18051061462",//"wifi-test",//"zl_sensor",///"china-yec",//"",////"",//"zl_sensor",/"lft13852578307",//"",//"",//"123456789",//"china-yec.com",// //
	.TcpServer_IP = "192.168.100.234",// "218.91.149.114",//"192.168.0.234",//"192.168.0.233",//"192.168.0.233",//"192.168.0.141",// "192.168.0.112",//
	.TcpServer_Port = "8712", //
	.LocalIP = "192.168.99.45",  //LocalIP
	.LocalGATEWAY =  "192.168.99.1",  //LocalGATEWAY
	.LocalMASK = "255.255.255.0",	//LocalMASK
	.PeriodTransimissonCounter = 1,
	.PeriodTransimissonStatus = 1,
	.ParameterTransimissonStatus = 1,
	.RequirePeriodChannel = 0x1f,
	.RESETTIME = 1,
	.Enable_active_beacon = 0,  //
	.Iap_flag = 0,
	.Iap_datalength = 0,
	.channel_freq = {16384,8192,8192,8192,51200,51200,51200,51200,51200,51200,12800,12800},
	.BeaconInterval = 5, //
	.server_address = "www.av.com",
	.DNS_SERVERIP = "192.168.120.120",
	.Lowpower_Mode = 0,  //Lowpower_Mode 1
	.scan_channel = 6,  //scan_channel
	.Waitforsleeptime = 12, //Waitforsleeptime
	.WaitforIEPEtime = 2,//WaitforIEPEtime
	.filterMean = { 0.25f,0.25f,0.25f,0.25f,0.25f,0.25f},
	.WaitToPeriodTransmissonCounter = 0,//WaitToPeriodTransmissonCounter
	.Alarm_value_junyue = 	{10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,
		10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,10000.0f,
	 10000.0f,10000.0f},
	.battery = 100 ,
	.workcycleseconds_inAlarmStatue = 20,
	.tempCompensation = -5 ,
	//.Alarm_source_number = ,
	//.Alarm_source = 
};

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;


typedef StaticSemaphore_t osStaticSemaphoreDef_t;
osThreadId_t defaultTaskHandle;
osThreadId_t DateProcessHandle;
osThreadId_t DateEmuHandle;
osThreadId_t RxdBufProcessHandle;
osThreadId_t Esp32ProcessHandle;
/* USER CODE BEGIN PV */
osSemaphoreId_t ad7682_readyHandle;
osSemaphoreId_t seconds_sample_data_readyHandle;
osSemaphoreId_t write_data_readyHandle;
osStaticSemaphoreDef_t myBinarySem01ControlBlock;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void Flash_Erase(uint32_t Address,uint32_t NumToWrite);

extern void DataProcessFunction(void *argument);
extern void DataEmuFunction(void *argument);
extern void DataProcessFunction(void *argument);
extern void RxdBufProcessFunction(void *argument);
extern void Esp32ProcessFunction(void *argument);

extern void WRBYTES(uint32_t address,uint32_t num, uint8_t *Data);
extern void RDBYTES(uint32_t address,uint32_t num, uint8_t *Data);
//uint8_t update_program[120000];
iapfun jump2app; 
void iap_load_app(uint32_t appxaddr);

void iap_load_app(uint32_t appxaddr)
{ 
//	SCB_DisableDCache();
//	if(((*(uint32_t*)appxaddr)&0x2FF00000)==0x24000000)	//检查栈顶地址是否合法.
	{ 
//        printf("跳转到APP\r\n");
		SCB->VTOR =  appxaddr; //中断向量起始地址
//		__disable_irq();
		jump2app=(iapfun)*(__IO uint32_t*)(appxaddr+4);		//用户代码区第二个字为程序开始地址(复位地址)		
		__set_MSP(*(__IO uint32_t*) appxaddr);//__set_MSP(*(uint32_t*)appxaddr);					//初始化APP堆栈指针(用户代码区的第一个字用于存放栈顶地址)
		jump2app();									//跳转到APP.
	}
}

uint8_t update_program[0x32000];
FLASH_EraseInitTypeDef EraseInitStruct;

/**
 0x08000000-0x08020000   bootload
 0x08020000-0x08100000   APP 0x08020000 + 200kb(0x32000)  = 0x08052000
 0x08100000-0x081A0000   BACKUP   0x08052000 + 4kB(0x1000) = 0x08053000  + 200kb(0x32000)  = 0x08085000
 0x081D0000-0x08200000	 CONFIG   0x08085000 + 4kb(0x1000) = 0x08086000  
  */
int main(void)
{

	bsp_Init();


	if(config.Iap_flag==1)
	{
//		EarsePage_program(0x00050000,0x80000);
		
		Flash_Erase(0x08020000,0x32000);
		RDBYTES(0x08053000,config.Iap_datalength,update_program);
		WRBYTES(0x08020000,config.Iap_datalength,update_program);	
		config.Iap_flag = 0;
		saveConfig();
		iap_load_app(0x08020000);
	}
	else
	{
		iap_load_app(0x08020000);
	}
	


  while (1)
  {


  }

}
void software_reset(void)
{
	

	__disable_irq();
	NVIC_SystemReset();
	                                                   /* wait until reset */
}
/**
  * @brief System Clock Configuration
  * @retval None
  */


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 30;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_LPTIM1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.Lptim1ClockSelection = RCC_LPTIM1CLKSOURCE_PCLK;
//  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

void SystemClock_Config_copy(void)  //新版本用来调试RTC唤醒后，重新设置时间
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 30;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_LPTIM1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.Lptim1ClockSelection = RCC_LPTIM1CLKSOURCE_PCLK;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}



uint32_t sleepcounter=0;
void StartDefaultTask(void *argument)
{

}

/**
  * @brief  Pre Sleep Processing
  * @param  ulExpectedIdleTime: Expected time in idle state
  * @retval None
  */
extern RTC_HandleTypeDef RtcHandle;
static void GPIO_ConfigAN(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Configure all GPIO as analog to reduce current consumption on non used IOs */
  /* Enable GPIOs clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();

  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Pin = GPIO_PIN_All;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /* Disable GPIOs clock */
  __HAL_RCC_GPIOA_CLK_DISABLE();
  __HAL_RCC_GPIOC_CLK_DISABLE();
  __HAL_RCC_GPIOC_CLK_DISABLE();
  __HAL_RCC_GPIOD_CLK_DISABLE();
  __HAL_RCC_GPIOE_CLK_DISABLE();
  __HAL_RCC_GPIOF_CLK_DISABLE();
  __HAL_RCC_GPIOG_CLK_DISABLE();
  __HAL_RCC_GPIOH_CLK_DISABLE();
  __HAL_RCC_GPIOI_CLK_DISABLE();
}

extern RTC_T g_tRTC;
uint32_t rtc_awaketime(void)
{
	 RTC_ReadClock(); //读取下时间
	 
	 uint32_t vllstartclock=RTC_ConvertDatetimeToSeconds(&g_tRTC);//(uint32_t)(RTC->TSR);                    //获取当前时间
	 uint32_t intervalclock=0;
	 if(config.alarmminutetime>vllstartclock)                     //config.alarmminutetime是闹钟开始时间
	 {
		  intervalclock=config.alarmminutetime-vllstartclock;
		  return(intervalclock%(config.workcycleseconds));
	 }
	 else {
		  intervalclock=vllstartclock-config.alarmminutetime;
			return(config.workcycleseconds-intervalclock%config.workcycleseconds);
	 }
}

void PreSleepProcessing(uint32_t * ulExpectedIdleTime)
{
  /* Called by the kernel before it places the MCU into a sleep mode because
  configPRE_SLEEP_PROCESSING() is #defined to PreSleepProcessing().

  NOTE:  Additional actions can be taken here to get the power consumption
  even lower.  For example, peripherals can be turned off here, and then back
  on again in the post sleep processing function.  For maximum power saving
  ensure all unused pins are in their lowest power state. */

  /* 
    (*ulExpectedIdleTime) is set to 0 to indicate that PreSleepProcessing contains
    its own wait for interrupt or wait for event instruction and so the kernel vPortSuppressTicksAndSleep 
    function does not need to execute the wfi instruction  
  */
	*ulExpectedIdleTime = 0;
	GPIO_ConfigAN();

	
	HAL_RTCEx_DeactivateWakeUpTimer(&RtcHandle);
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	HAL_RTCEx_SetWakeUpTimer_IT(&RtcHandle, config.workcycleseconds, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
	
	/* Enter STOP 2 mode */
	HAL_SuspendTick();
	HAL_PWR_EnterSTANDBYMode();
	//		system_power_config();

	/* Enter Stop Mode */
	//    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
//	HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
  /*Enter to sleep Mode using the HAL function HAL_PWR_EnterSLEEPMode with WFI instruction*/
//  HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);  
}

/**
  * @brief  Post Sleep Processing
  * @param  ulExpectedIdleTime: Not used
  * @retval None
  */
void PostSleepProcessing(uint32_t * ulExpectedIdleTime)
{
  /* Called by the kernel when the MCU exits a sleep mode because
  configPOST_SLEEP_PROCESSING is #defined to PostSleepProcessing(). */

  /* Avoid compiler warnings about the unused parameter. */
  (void) ulExpectedIdleTime;
	 /* Clear all related wakeup flags */
	 __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
	SystemClock_Config();
	HAL_ResumeTick();

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM7) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
