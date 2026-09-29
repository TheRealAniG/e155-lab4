// STM32L432KC_TIMER.h
// Header for TIMER functions

#ifndef STM32L4_TIMER_H
#define STM32L4_TIMER_H

#include <stdint.h> // Include stdint header

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////


#define __IO volatile

#define TIM_BASE6 (0x40001000UL) // base address of TIM6
#define TIM_BASE7 (0x40001400UL) // base address of TIM7


typedef struct
{
  __IO uint32_t CR1;  /*Address offset: 0x00 */
  __IO uint32_t CR2;  /*Address offset: 0x04 */
  uint32_t RESERVED0; /*Address offset: 0x08 */
  __IO uint32_t DIER; /*Address offset: 0x0C */
  __IO uint32_t SR;   /*Address offset: 0x10 */
  __IO uint32_t EGR;  /*Address offset: 0x14 */
  uint32_t RESERVED1; /*Address offset: 0x18 */
  uint32_t RESERVED2; /*Address offset: 0x1C */
  uint32_t RESERVED3; /*Address offset: 0x20 */
  __IO uint32_t CNT;  /*Address offset: 0x24 */
  __IO uint32_t PSC;  /*Address offset: 0x28 */
  __IO uint32_t ARR;  /*Address offset: 0x2C */
} TIMER_TypeDef;

#define TIM6 ((TIMER_TypeDef *) TIM_BASE6)
#define TIM7 ((TIMER_TypeDef *) TIM_BASE7)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void configureTimer(void);

void startPitchTimer(uint32_t frequency);

void startDurationTimer(uint32_t duration); 

int timerDone(TIMER_TypeDef *timer);

void stopTimer(TIMER_TypeDef *timer);

#endif