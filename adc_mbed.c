#include "mbed.h"
#include <stdio.h>
#include <math.h>

// Serial connection to pc
RawSerial pc(USBTX, USBRX);

// Serial connection to Nucleo F334R8
RawSerial dev(PA_2, PA_3);

// ADCs ana_in PA_0,1,X2X,X3X,4,5,6,7, PB_0,PC_0,1,
// DACs ana_out PA_4,5,6
// ADC goes from 0-3.3V in 4096 grades->.8057mV/bit
AnalogIn ain0(PA_0);

int main()
{   
    pc.baud(115200);
    dev.baud(115200);
    
    led1=1;
    char buffer[5];

    while(1){
        wait_ms(50);
        snprintf(buffer,5,"%.4x",ain0.read_u16());       
        pc.puts(buffer);
        pc.putc('-');
        wait_ms(50);
    }
}
