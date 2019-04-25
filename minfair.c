#include <stdio.h>
#include <stdlib.h>
const int maxprgcnt = 1000;
const int prjcnt = 4;
const int fastcnt = 2;
const int slowcnt = 2;

double required_f_share(int i,double target,double efficiency[] ) 

{

   double  f_base=(float)fastcnt/(float)prjcnt;
   double  s_base=(float)slowcnt/(float)prjcnt;
   double perf_base=efficiency[i]*f_base+s_base;
   double f_minF;
   int i1;
   for(i1 = 3; i1 < 100; ) 
   {
   		f_minF=(double)i1/(double)100;
   		if( ((efficiency[i]*f_minF+(f_base+s_base-f_minF))/perf_base)>target )
   			return f_minF;
   			
   		i1=i1+3;
   }
   
   return f_minF;
}
double * sched_min_fair(double target,double efficiency[])
{
  int keyorder[maxprgcnt];
  static double fi[9999];
  double si[maxprgcnt];
  int i1,j1;
  double f_remain,share;
  
  
	f_remain=fastcnt;
	for(i1 = 0; i1 < prjcnt; i1++) 
   	{
   		share=required_f_share( i1, target ,efficiency);
   		fi[i1]=share; 
   		si[i1]=1-share; 
   		f_remain=f_remain-share;
   	}	
	
	//printf("%f %f %f %f",fi[0],fi[1],fi[2],fi[3]);
	//printf("f_remain:%f",f_remain);
	
	
	for(i1 = 0; i1 < prjcnt; i1++) 
	{
		keyorder[i1]=0;
		for(j1 = 0; j1 < prjcnt; j1++) 
		{
			if (efficiency[j1]>efficiency[i1]) keyorder[i1]=keyorder[i1]+1;
		}
	}
	//printf("%d %d %d %d",keyorder[0],keyorder[1],keyorder[2],keyorder[3]);
	
	
	for(i1 = 0; i1 < prjcnt; i1++) 
	{
		int minval=9999;
		int findindex;
		for(j1 = 0; j1 < prjcnt; j1++) 
		{
			if (keyorder[j1]<minval)
			{
				minval=keyorder[j1];
				findindex=j1;
			}
		}
		keyorder[findindex]=9999;
		
		
		//do the monopolize share differentiate
		if ((1-fi[findindex])>f_remain) share=f_remain; else share=1-fi[findindex];
   		fi[findindex]=fi[findindex]+share; 
   		si[findindex]=si[findindex]-share; 
   		f_remain=f_remain-share;
   		if (f_remain<=0) break;
				
		
	}
	return fi;
}
void main(int argc, char **argv)
{

  double efficiency[maxprgcnt];
  double target;
  double * fi;
  
  target=atof(argv[1]);
  efficiency[0]=atof(argv[2]);
  efficiency[1]=atof(argv[3]);
  efficiency[2]=atof(argv[4]);
  efficiency[3]=atof(argv[5]);
  
  /*
  target=0.98;
  efficiency[0]=1.22;
  efficiency[1]=0.9;
  efficiency[2]=1.22;
  efficiency[3]=1.66;
  */
  fi=sched_min_fair( target,efficiency);
  
	printf("\n%d %d %d %d",(int) (fi[0]/0.015),(int)(fi[1]/0.015),(int)(fi[2]/0.015),(int)(fi[3]/0.015));
  return;
}
