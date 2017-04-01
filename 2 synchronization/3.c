//use synchronization and avoid the false sharing problem in the pi program

#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h>   
static long num_steps = 100000000; 
double step; 
#define NUM 4
int main(void) 
{     
	 int i;
	double  pi;
	step = 1.0/(double) num_steps; 
	int nthreads;
	double sum[NUM]   ;
	omp_set_num_threads(NUM);
	
	#pragma omp parallel
	{
		int nthrds;
		int i;
		double x;
		int ID = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if(ID==0)
			nthreads = nthrds;
		     
		for (i=ID,sum[ID] = 0.0;i<num_steps;i += nthrds) 
		{         
			x = (i+0.5)*step;         
			sum[ID] = sum[ID] + 4.0/(1.0+x*x);     
		}    
	    
 	}  
	for(i = 0,pi=0.0; i<nthreads;i++) pi +=sum[i]*step;    
	printf("pi=%f\n",pi);     
	return EXIT_SUCCESS; 
}
