#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
	omp_set_num_threads(4);
	

	#pragma omp parallel
	{
	int ID = omp_get_thread_num();
	cout<<"HELLO"<<ID<<"WORLD"<<ID<<endl;
	cout<<omp_get_num_threads()<<endl;
	}
	
	return 0;
}

