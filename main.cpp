#include <iostream>
#include "overload.h"
#include "Allocator.h"

int main()
{
	Over* a = new Over;
	delete a;

	Over* b = new Over[5];
	delete[] b;

	Allocator<double> alloc(10);
	double* c = alloc.allocate(6);
	alloc.deallocate(c, 6);

	double* Arr = new double[5];
	alloc.construct(Arr, 5);
	alloc.deallocate(Arr, 5);
}
