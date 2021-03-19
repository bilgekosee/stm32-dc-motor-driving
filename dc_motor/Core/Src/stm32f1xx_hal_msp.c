/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32f1xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_AFIO_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /** NOJTAG: JTAG-DP Disabled and SW-DP Enabled
  */
  __HAL_AFIO_REMAP_SWJ_NOJTAG();

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief I2C MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hi2c->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspInit 0 */

  /* USER CODE END I2C1_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();
  /* USER CODE BEGIN I2C1_MspInit 1 */

  /* USER CODE END I2C1_MspInit 1 */
  }
  else if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */

  /* USER CODE END I2C2_MspInit 1 */
  }

}

/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspDeInit 0 */

  /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();

    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }
  else if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_11);

  /* USER CODE BEGIN I2C2_MspDeInit 1 */

  /* USER CODE END I2C2_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */
 void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  __HAL_RCC_TIM2_CLK_ENABLE();

   HAL_NVIC_SetPriority(TIM2_IRQn  , 0, 0);
   HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/**
  * @brief  DeInitializes TIM Base MSP.
  * @param  htim TIM Base handle
  * @retval None
  */
 void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */

	 __HAL_RCC_TIM2_CLK_DISABLE();
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_Base_MspDeInit could be implemented in the user file
   */
}
 void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim)
 {
   /* Prevent unused argument(s) compilation warning */


   /* NOTE : This function should not be modified, when the callback is needed,
             the HAL_TIM_Encoder_MspInit could be implemented in the user file
    */
 }

 /**
   * @brief  DeInitializes TIM Encoder Interface MSP.
   * @param  htim TIM Encoder Interface handle
   * @retval None
   */
  void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim)
 {
   /* Prevent unused argument(s) compilation warning */


   /* NOTE : This function should not be modified, when the callback is needed,
             the HAL_TIM_Encoder_MspDeInit could be implemented in the user file
    */
 }
  void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim)
 {
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  	  if(htim->Instance==TIM2)
	  	  {
	  	  /* USER CODE BEGIN TIM2_MspPostInit 0 */

	  	  /* USER CODE END TIM2_MspPostInit 0 */

	  	    __HAL_RCC_GPIOA_CLK_ENABLE();
	  	    /**TIM2 GPIO Configuration
	  	    PA0-WKUP     ------> TIM2_CH1
	  	    PA1     ------> TIM2_CH2
	  	    */
	  	    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
	  	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	  	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  	  /* USER CODE BEGIN TIM2_MspPostInit 1 */

	  	  /* USER CODE END TIM2_MspPostInit 1 */
	  	  }
 }

 /**
   * @brief  DeInitializes TIM Output Compare MSP.
   * @param  htim TIM Output Compare handle
   * @retval None
   */
 void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim)
 {
	 __HAL_RCC_TIM2_CLK_DISABLE();
		 HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1);
		 HAL_NVIC_DisableIRQ(TIM2_IRQn);
 }
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
