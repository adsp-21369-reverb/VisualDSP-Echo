#ifndef __DSP__
#define __DSP__

#include "tt.h"
#include "DSP_delay.h"
#include "DSP_lowpass.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~ DEFINE GLOBAL CONSTANTS ~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define FS 48000 // DACFS48 set in init1835viaSPI.c
#define mix 0.5 // 0.0 for dry signal, 1.0 for wet signal
#define bandwidth 0.9995
#define g1 0.7
#define g2 0.49
#define g3 0.343
#define g4 0.2401


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~ EXTERN VARIABLES ~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ...



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~ FUNCTION PROTOTYPES ~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

extern void DSP_init(void);
extern void DSP_program(float *leftChannel, float *rightChannel);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~ FILTER STRUCTS ~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern struct_delay delay1;
extern struct_delay delay2;
extern struct_delay delay3;
extern struct_delay delay4;

extern struct_lp lp1;
extern struct_lp lp2;
extern struct_lp lp3;
extern struct_lp lp4;

#endif
