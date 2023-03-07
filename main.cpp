#include "mbed.h"
#include <cmath>
#include <cstdint>
#include <cstdio>

const double pi = 3.141592653589793238462;

AnalogOut aout(PA_4);

int main()
{
    int value[360];

    for (int i = 0; i < 180; i++) {
        //rads = (pi * i) / 180.0f;
        value[i] = (int)(65535 * (3 / 3.3 * (tanh((pi * i) / 180.0f))));
    }
    for (int i = 180; i < 360; i++) {
        //rads = (pi * i) / 180.0f;
        value[i] = (int)(65535 * (3 / 3.3 * (tanh(2*pi-(pi * i) / 180.0f))));
    }
    while (1)
    {
        for (int i = 0; i < 360; i++)
        {
            aout.write_u16(value[i]);
        }
    }
}

