// STM32L432KC_TIMER.c
// Source code for TIMER functions

#include "STM32L432KC_TIMER.h"
#include "STM32L432KC_RCC.h"

void configureTimer(void){
  //TIM7 clock enable
  RCC->APB1ENR1 |=  (1 << 5);

  //TIM6 clock enable
  RCC->APB1ENR1 |=  (1 << 4);
}

void startPitchTimer(uint32_t frequency){

  // Stop timer during configuration
  TIM6->CR1 &= ~(1 << 0);

  // Set prescaler 80 MHz / (79 + 1) = 1 MHz = 1000000
  TIM6->PSC = 79;

  // Set period based on frequency ( has to go high and low)
  TIM6->ARR = ((1000000) / (2* frequency) - 1);

  // Reset count
  TIM6->CNT = 0;

  // Load PSC/ARR values
  TIM6->EGR |= (1 << 0);

  // Clear completion flag
  TIM6->SR &= ~(1 << 0);

  // Start count
  TIM6->CR1 |= (1 << 0);
}

void startDurationTimer(uint32_t duration){

  // Stop timer during configuration
  TIM7->CR1 &= ~(1 << 0);

  // Set prescaler 80 MHz / (7999 + 1) = 10 KHz = 10000
  TIM7->PSC = 7999;

  // wait the duration
  TIM7->ARR = ((duration * 10) - 1);

  // Reset count
  TIM7->CNT = 0;

  // Load PSC/ARR values
  TIM7->EGR |= (1 << 0);

  // Clear completion flag
  TIM7->SR &= ~(1 << 0);

  // Start count
  TIM7->CR1 |= (1 << 0);

} 

int timerDone(TIMER_TypeDef *timer){
  //check if max count has been reached
  if (timer->SR & (1 << 0))
    {
        // timer is done
        timer->SR &= ~(1 << 0);
        return 1;
    }

    return 0;
}

void stopTimer(TIMER_TypeDef *timer){
  // stop timer
  timer->CR1 &= ~(1 << 0);
}

