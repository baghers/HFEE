#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(int argc, char **argv)
{

  double power,a,b,c,d,Vdd,T;
  int freq,lb;
  
  
  freq=atof(argv[1]);
  Vdd=atof(argv[2]);
  T=atof(argv[3]);
  lb=atof(argv[4]);
  
  if (lb==0)//little
  {
	switch(freq)
    {
        case 200:
		a=-1.25E-08;b=3.50E-06;c=-5.55E-08;d=2.299;
            break;
        case 300:
		a=-8.34E-09;b=3.50E-06;c=-3.48E-27;d=2.299;
            break;
        case 400:
            a=-6.26E-09;b=3.50E-06;c=-1.11E-11;d=2.299;
            break;
        case 500:
            a=-5.01E-09;b=3.50E-06;c=-1.30E-27;d=2.299;
            break;
        case 600:
            a=-4.17E-09;b=3.50E-06;c=1.55E-10;d=2.298;
            break;
        case 700:
            a=-9.91E-10;b=2.81E-06;c=8.56E-01;d=0.7066;
            break;
        case 800:
            a=-6.45E-10;b=2.46E-06;c=-3.28E-01;d=0.5598;
            break;
        case 900:
            a=-8.18E-10;b=2.57E-06;c=-2.23E-01;d=0.7825;
            break;
        case 1000:
            a=-1.32E-10;b=2.47E-06;c=1.03E+00;d=0.1824;
            break;
        case 1100:
            a=-1.58E-10;b=2.45E-06;c=1.009;d=0.2264;
            break;
        case 1200:
            a=-1.32E-10;b=2.74E-06;c=1.03E+00;d=0.2091;
            break;
        case 1300:
            a=-1.09E-10;b=2.71E-06;c=1.05E+00;d=0.1919;
            break;
        case 1400:
            a=5.43E-10;b=6.66E-06;c=-10;d=-0.8848;
            break;
    }
  }
  else//big
  {
	switch(freq)
    {        
		case 200:
		a=8.64E-09;b=1.08E-05;c=1.00E+01;d=-1.44;
            break;
        case 300:
		a=5.66E-09;b=1.08E-05;c=1.00E+01;d=-1.414;
            break;
        case 400:
            a=-8.19E-08;b=7.43E-05;c=-6.14E-01;d=29.99;
            break;
        case 500:
            a=-9.14E-09;b=-9.52E-06;c=1.00E+01;d=4.621;
            break;
        case 600:
            a=-7.63E-09;b=-9.52E-06;c=1.00E+01;d=4.632;
            break;
        case 700:
            a=-6.54E-09;b=-9.52E-06;c=1.00E+01;d=4.628;
            break;
        case 800:
            a=-1.70E-09;b=-5.77E-06;c=1.00E+01;d=1.742;
            break;
        case 900:
            a=-1.22E-08;b=-2.82E-05;c=7.16E-01;d=10.79;
            break;
        case 1000:
            a=-9.86E-09;b=-2.86E-08;c=2.55E-27;d=10;
            break;
        case 1100:
            a=-2.66E-08;b=-6.07E-06;c=40.9;d=29.3;
            break;
        case 1200:
            a=-2.46E-08;b=1.36E-05;c=2.29E-01;d=30.29;
            break;
        case 1300:
            a=-2.22E-08;b=-3.23E-05;c=1.05E+00;d=30.46;
            break;
        case 1400:
            a=4.81E-08;b=-1.87E-05;c=0.1113;d=-70;
            break;
        case 1500:
            a=4.38E-08;b=-6.13E-05;c=2.13E+00;d=-69.77;
            break;
        case 1600:
            a=1.73E-08;b=-1.93E-05;c=1.75E-02;d=-30;
            break;
        case 1700:
            a=7.71E-08;b=-5.43E-05;c=2.82E-01;d=-150;
            break;
        case 1800:
            a=3.38E-08;b=-1.78E-05;c=2.51E+01;d=-71.56;
            break;
        case 1900:
            a=1.05E-08;b=-1.62E-04;c=-2.00E+01;d=-23.45;
            break;
        case 2000:
            a=2.73E-08;b=-2.80E-05;c=4.47E-02;d=-70;
            break;
	}
  }
  power=a*(Vdd*Vdd)*freq*1000000+Vdd*(b*(T*T)*exp(c/T)+d);
            
  
	printf("\n%f",power);
  return;
}
