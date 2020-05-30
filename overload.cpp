#include <iostream>

#include "overload.h"
#include "Allocator.h"


using namespace std;

void* Over::operator new(size_t size) 
{	
	void* allocMem = malloc(size);
	if (allocMem == 0)
	{
		throw bad_alloc();
	}
	else
	{
		return allocMem;
	}
}

void Over::operator delete(void* tmp) 
{
	std::free(tmp);
}

void* Over::operator new[](size_t size)
{
	void* allocMem = malloc(size);
	if (allocMem == 0)
	{
		throw bad_alloc();
	}
	else
	{
		return allocMem;
	}
}

void Over::operator delete[](void* tmp)
{
	std::free(tmp);
}

void* Over::operator new(std::size_t size, const std::nothrow_t&) 
{
	return malloc(size);
}

void* Over::operator new[](std::size_t size, const std::nothrow_t&)
{
	return malloc(size);
}
