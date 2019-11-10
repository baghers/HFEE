#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float uniformity(float data[], int n)
{
    float mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<n;++i)
    {
        mean+=data[i];
    }
    mean=mean/n;
    for(i=0; i<n;++i)
    sum_deviation+=(data[i]-mean)*(data[i]-mean);
    return 1-(sqrt(sum_deviation/(n-1))/mean);           
}
void main(int argc, char **argv)
{
	int i,m=40;
    float data[40];
  	m=atoi(argv[1]);
      for(i=0; i<m;i++)
    {
        data[i]=atof(argv[i+2]);
    }
    

    printf("\n%.2f", uniformity(data,m));
    return ;
}
