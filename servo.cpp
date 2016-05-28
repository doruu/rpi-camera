#include <iostream>
#include <cstdlib>
#include "wiringPi.h"
#define PWM_CLOCK 384
#define PWM_RANGE 1000

#define WRITE_MIN 50.f
#define WRITE_MAX 100.f

#define INPUT_MIN -90.f
#define INPUT_MAX 90.f

#define LR_SERVO 18
#define TB_SERVO 13

int main(int argc, char *argv[]) {
	
	if(argc != 3) {
		return 1;
	}
	
	if(wiringPiSetupGpio() ==  -1 )  {
        return 1;
    }
	
	float lr = atof(argv[1]);
	float tb = atof(argv[2]);

	if(lr < INPUT_MIN) {
		lr = INPUT_MIN; 
	}
	if(lr > INPUT_MAX) {
		lr = INPUT_MAX;
	}
	if(tb < INPUT_MIN) {
		tb = INPUT_MIN;
	}
	if(tb > INPUT_MAX) {
		tb = INPUT_MAX;
	}

	// INPUT_MIN ~ INPUT_MAX -> WRITE_MIN ~ WRITE_MAX;
	float di = (WRITE_MAX - WRITE_MIN)/180.f;
	lr = WRITE_MIN + (lr - INPUT_MIN)*di;
	tb = WRITE_MIN + (tb - INPUT_MIN)*di;
	
	pinMode(LR_SERVO, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(PWM_CLOCK);
	pwmSetRange(PWM_RANGE);
	pwmWrite(LR_SERVO, lr);
	
	pinMode(TB_SERVO, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(PWM_CLOCK);
	pwmSetRange(PWM_RANGE);
	pwmWrite(TB_SERVO, tb);
	
	return 0;
}
