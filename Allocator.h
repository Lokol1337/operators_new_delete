#pragma once
#include <stdexcept>
using namespace std;

template <class T>
class Allocator
{
	public:
		Allocator(size_t size) :_size(size) {};
		T* allocate(size_t size)
		{
			if (size > _size)
			{
				throw bad_alloc();
			}
			else
			{
				return new T [size];
			}
		}
	
		void deallocate(T* ptr, size_t size)
		{
			delete[] ptr;
		}

		T* max_size() {
			return sizeof(T);
		}

		void destroy(T* tmp) const 
		{
			tmp->~T();
		}


		template < typename... moreArg>
		void construct(T* ptr,const moreArg&... arg)
		{
			new(ptr) T(arg...);
		}


	private:
		size_t _size;

};