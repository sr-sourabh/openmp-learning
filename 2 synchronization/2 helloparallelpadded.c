#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h>   
static long num_steps = 100000000; 
double step; 
#define PAD 16
#define NUM 16
int main(void) 
{     
	 int i;
	double  pi;
	step = 1.0/(double) num_steps; 
	int nthreads;
	double sum[NUM][PAD]   ;
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
		     
		for (i=ID,sum[ID][0] = 0.0;i<num_steps;i += nthrds) 
		{         
			x = (i+0.5)*step;         
			sum[ID][0] += + 4.0/(1.0+x*x);     
		}    
	    
 	}  
	for(i = 0,pi=0.0; i<nthreads;i++) pi +=sum[i][0]*step;    
	printf("pi=%f\n",pi);     
	return EXIT_SUCCESS; 
}
