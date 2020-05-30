#pragma once

#include "Allocator.h"

class Over
{
	public:
		void* operator new(size_t size);

		void operator delete(void* tmp);

		void* operator new[](size_t size);

		void operator delete[](void* tmp);

		void* operator new(std::size_t size, const std::nothrow_t&);

		void* operator new[](std::size_t size, const std::nothrow_t&);
};
