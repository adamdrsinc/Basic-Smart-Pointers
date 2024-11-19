#pragma once
#include <iostream>

namespace usu
{
	template<typename T>
	class unique_ptr
	{
	public:
		//Default Constructor
		unique_ptr();
		//Overloaded Constructor
		unique_ptr(T* ptr);
		//Copy Constructor
		unique_ptr(const unique_ptr& other_unique_ptr) = delete;
		//Move Constructor
		unique_ptr(unique_ptr&& moved_unique_ptr);

		//Destructor
		~unique_ptr();

		void operator= (unique_ptr&& moved_unique_ptr);
		T* operator->();
		T	 operator* ();
		bool operator==(const unique_ptr& other_unique_ptr);
		bool operator!=(const unique_ptr& other_unique_ptr);

		T* get();
		T* release();

	private:
        T* m_ptr;

	};

	template <typename T, typename... Args>
	unique_ptr<T> make_unique(Args&&... args)
	{
		return unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}


