/*!
 * \file      delay-board.c
 *
 * \brief     Target board delay implementation
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    Johannes Bruder ( STACKFORCE )
 */
#include "stm32l1xx.h"
#include "delay-board.h"

void DelayMsMcu( uint32_t ms )
{
    HAL_Delay( ms );
}

void HAL_Delay(uint32_t Delay) {
	/* Delay for amount of milliseconds */
	/* Check if we are called from ISR */
	if (__get_IPSR() == 0) {
		/* Called from thread mode */
		uint32_t tickstart = HAL_GetTick();
		
		/* Count interrupts */
		while ((HAL_GetTick() - tickstart) < Delay) {
#ifdef DELAY_SLEEP
			/* Go sleep, wait systick interrupt */
			__WFI();
#endif
		}
	} else {
		/* Called from interrupt mode */
		while (Delay) {
			/* Check if timer reached zero after we last checked COUNTFLAG bit */
			if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) {
				Delay--;
			}
		}
	}
}
