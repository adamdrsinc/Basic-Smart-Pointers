#pragma once
#include <iostream>
#include <cstdint>
#include <utility>

namespace usu 
{

	template<typename T>
	class shared_ptr
	{
	public:
		//Overloaded Constructor
		shared_ptr(T* ptr);
		//Copy Constructor
		shared_ptr(const shared_ptr& other_shared_ptr);
		//Move Constructor
		shared_ptr(shared_ptr&& moved_shared_ptr);

		//Destructor
		~shared_ptr();

		void operator=(const shared_ptr& other_shared_ptr);
		void operator=(shared_ptr&& moved_shared_ptr);
		T*	 operator->();
		T    operator*();

		T* get();
		std::uint32_t use_count();

		

	private:
		T* m_ptr;
		std::uint32_t* m_reference_count;
	};

	template <typename T, typename... Args>
	shared_ptr<T> make_shared(Args&&... args)
	{
		return shared_ptr<T>(new T(std::forward<Args>(args)...));
	}

	template<typename T>
	class shared_ptr<T[]>
	{
	public:
		//Overloaded Constructor
		shared_ptr(T* array_ptr, const std::uint32_t size_of_array);
		
		//Destructor
		~shared_ptr();

		T operator[](const std::uint32_t idx);

		std::uint32_t size();

		

	private:
		T* m_array_ptr;
		std::uint32_t m_array_size;
	};

	template <typename T, unsigned int N>
	shared_ptr<T[]> make_shared_array()
	{
		return shared_ptr<T[]>(new T[N], N);
	}
}

