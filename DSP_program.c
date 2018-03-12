#include "DSP.h"
#include "DSP_delay.h"
#include "DSP_lowpass.h"

// define size of delaylines for each module

#define delaysize_delay1 12000
#define delaysize_delay2 12000
#define delaysize_delay3 12000
#define delaysize_delay4 12000

#define delaysize_lp1 1
#define delaysize_lp2 1
#define delaysize_lp3 1
#define delaysize_lp4 1

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~ CREATE FILTER STRUCTS + global buffers ~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// always add 1 sample for write/read index offset


struct_delay delay1;
#pragma section ("seg_ext_data")
float buffer_delay1[delaysize_delay1+1];

struct_lp lp1;
float buffer_lp1[delaysize_lp1+1];

struct_delay delay2;
#pragma section ("seg_ext_data")
float buffer_delay2[delaysize_delay2+1];

struct_lp lp2;
float buffer_lp2[delaysize_lp2+1];

struct_delay delay3;
#pragma section ("seg_ext_data")
float buffer_delay3[delaysize_delay3+1];

struct_lp lp3;
float buffer_lp3[delaysize_lp3+1];

struct_delay delay4;
#pragma section ("seg_ext_data")
float buffer_delay4[delaysize_delay4+1];

struct_lp lp4;
float buffer_lp4[delaysize_lp4+1];


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~ CREATE GLOBAL VARIABLES ~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float In;
//float delay1_in, delay1_out;
//float delay2_in, delay2_out;
//float delay3_in, delay3_out; 
//float delay4_in, delay4_out;



void DSP_init(void)
{
		
    delay_init(&delay1, buffer_delay1, delaysize_delay1);
	lp_init(&lp1, buffer_lp1, delaysize_lp1, bandwidth);
    delay_init(&delay2, buffer_delay2, delaysize_delay2);
	lp_init(&lp2, buffer_lp2, delaysize_lp2, bandwidth);
    delay_init(&delay3, buffer_delay3, delaysize_delay3);
	lp_init(&lp3, buffer_lp3, delaysize_lp3, bandwidth);
    delay_init(&delay4, buffer_delay4, delaysize_delay4);
	lp_init(&lp4, buffer_lp4, delaysize_lp4, bandwidth);

}


// -------------------------------------------------
// ~~~ Main DSP Path ~~~
// -------------------------------------------------
void DSP_program(float *leftChannel, float *rightChannel)
{
	int i;

	for(i=0; i<NUM_SAMPLES/2; i++)
	{
		In = (leftChannel[i] + rightChannel[i])/2;

		//delay1_in = In;
		delay(&delay1, In);
		//delay1_out = delay1.out;

		lp(&lp1, delay1.out);

		//delay2_in = lp1.out;
		delay(&delay2, lp1.out);
		//delay2_out = delay2.out;

		lp(&lp2, delay2.out);

		//delay3_in = In;
		delay(&delay3, lp2.out);
		//delay3_out = delay3.out;

		lp(&lp3, delay3.out);

		//delay4_in = In;
		delay(&delay4, lp3.out);
		//delay4_out = delay4.out;

		lp(&lp4, delay4.out);


		leftChannel[i] = g1*lp1.out + g3*lp3.out;
		rightChannel[i] = g2*lp2.out + g4*lp4.out;


	}

}
