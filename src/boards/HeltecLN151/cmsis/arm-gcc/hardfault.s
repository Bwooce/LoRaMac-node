.syntax unified
.cpu cortex-m3
.thumb

.global HardFault_Handler
.global WWDG_IRQHandler
.global UsageFault_Handler
.global BusFault_Handler2
.global TIM2_IRQHandler
.global TIM3_IRQHandler
.extern hard_fault_handler_c

HardFault_Handler:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c

WWDG_IRQHandler:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c

UsageFault_Handler:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c

BusFault_Handler2:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c

TIM2_IRQHandler:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c

TIM3_IRQHandler:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c
