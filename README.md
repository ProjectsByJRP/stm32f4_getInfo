# stm32f4_getInfo
Reads chip info and core registers
STM32F4xx - read chip info and core registers, output to UART 2 at 115200 8n1<br>
Output should look similar to this:<br>
Connected to UART Two<br>
stm32f446<br>
ARM Cortex M4 r0p1<br>
Single-precision FPU<br>
512 KB Flash<br>
Device Unique ID: 0029003B 30355105 31303734<br>
Oscillators and clocks<br>
----------------------<br>
            HSE State: Off<br>
            LSE State: Off<br>
            HSI State: On<br>
HSI Calibration value: 00000010<br>
            LSI State: Off<br>
           PLL Source: 00000000<br>
<br>
        SYSCLK Source: PLL<br>
       AHBCLK Divider: 1<br>
      APB1CLK Divider: 4<br>
      APB2CLK Divider: 2<br>
        Flash latency: 5<br>
    System core clock: 180000000<br>
<br>
Core registers<br>
--------------<br>
           r0: 0x0000000A<br>
           r1: 0x200002FB<br>
           r2: 0x00000000<br>
           r3: 0x12000000<br>
           r4: 0x00000000<br>
           r5: 0x00000000<br>
           r6: 0x00000000<br>
           r7: 0x2001FF48<br>
           r8: 0x00000000<br>
           r9: 0x00000000<br>
          r10: 0x00000000<br>
          r11: 0x00000000<br>
          r12: 0x00000014<br>
stack pointer: 0x2001FF28<br>
link register: 0x08001E83<br>
<br>