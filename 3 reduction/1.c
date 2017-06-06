#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h>   
static long num_steps = 100000000; 
double step; 
#define NUM 2
int main(void) 
{     
	int i;
	double  pi;
	step = 1.0/(double) num_steps; 
	double sum = 0.0   ;
	omp_set_num_threads(NUM);
	
	#pragma omp parallel
	{
		int i;
		double x;
		# pragma omp for reduction(+:sum)  
		for (i=0;i<num_steps;i++) 
		{         
			x = (i+0.5)*step;         
			sum = sum + 4.0/(1.0+x*x);     
		}    
	    
 	}  
	pi = step * sum;    
	printf("pi=%f\n",pi);     
	return EXIT_SUCCESS; 
}
