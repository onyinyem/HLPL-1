#include <iostream>
#include <stdexcept>
// global array
int ga[10] ={1,2,4,8,16,32,64,128,256,512};

void f(int a[], int n)
{
	// define local array
	int la[10];
	//copying values
	for (int i = 0;i < 10;i++)
		la[i] = ga[i];
	//printing values
	std::cout<<"Local array: ";
	for (int i = 0;i < 10;i++)
		std::cout<<la[i]<<" ";

	// pointer
	int* p = new int[n];
	// copy argumented arr
	for (int i = 0;i < 10;i++)
		p[i] = a[i];
	// printing
	std::cout << std::endl;
	std::cout<<"Pointer array: ";
	for (int i = 0;i < 10;i++)
		std::cout << p[i] << " ";
	std::cout << std::endl;
	delete[] p;
}
int main()
{
	f(ga, 10);
	int aa[10] = {1,2,6,24,120,720,5040,40320,362880,3628800};
	f(aa, 10);

	
	return 0;
}
