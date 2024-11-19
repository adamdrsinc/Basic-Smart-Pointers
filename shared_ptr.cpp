#include "shared_ptr.hpp"


// Template T shared_ptr

template <typename T>
usu::shared_ptr<T>::shared_ptr(T* ptr):
	m_ptr(ptr), 
	m_reference_count(new std::uint32_t(1))
{

}

template <typename T>
usu::shared_ptr<T>::shared_ptr(const shared_ptr& other_shared_ptr) :
	m_ptr(other_shared_ptr.m_ptr), 
	m_reference_count(other_shared_ptr.m_reference_count)
{
    (*m_reference_count)++;
}

template <typename T>
usu::shared_ptr<T>::shared_ptr(shared_ptr&& moved_shared_ptr) :
	m_ptr(moved_shared_ptr.m_ptr),
	m_reference_count(moved_shared_ptr.m_reference_count)
{
	moved_shared_ptr.m_ptr = nullptr;
	moved_shared_ptr.m_reference_count = nullptr;
}

template <typename T>
usu::shared_ptr<T>::~shared_ptr()
{
	(*m_reference_count)--;

	if (m_reference_count == 0)
	{
		delete m_ptr;
        delete m_reference_count;

		m_ptr = nullptr;
        m_reference_count = nullptr;
	}
}

template <typename T>
void usu::shared_ptr<T>::operator=(const shared_ptr& other_shared_ptr)
{
	if (this->m_ptr == other_shared_ptr.m_ptr
		&&
		this->m_reference_count == other_shared_ptr.m_reference_count
		)
	{
        return;
	}

	m_ptr = other_shared_ptr.m_ptr;
    m_reference_count = other_shared_ptr.m_reference_count;
    (*m_reference_count)++;
}

template <typename T>
void usu::shared_ptr<T>::operator=(shared_ptr&& moved_shared_ptr)
{
    if (this->m_ptr == moved_shared_ptr.m_ptr &&
        this->m_reference_count == moved_shared_ptr.m_reference_count)
    {
        return;
    }

	m_ptr = moved_shared_ptr.m_ptr;

	moved_shared_ptr.m_ptr = nullptr;
    moved_shared_ptr.m_reference_count = nullptr;
}

template <typename T>
T* usu::shared_ptr<T>::operator->()
{
	return m_ptr;
}

template <typename T>
T usu::shared_ptr<T>::operator*()
{
	return *m_ptr;
}

template <typename T>
T* usu::shared_ptr<T>::get()
{
	return m_ptr;
}

template <typename T>
std::uint32_t usu::shared_ptr<T>::use_count()
{
    return (*m_reference_count);
}


//Template T[] shared_ptr

template <typename T>
usu::shared_ptr<T[]>::shared_ptr(T* array_ptr, const std::uint32_t size_of_array):
	m_array_ptr(array_ptr),
	m_array_size(size_of_array)
{
}

template <typename T> 
usu::shared_ptr<T[]>::~shared_ptr()
{
	delete[]m_array_ptr;
	m_array_ptr = nullptr;
	m_array_size = 0;
}

template <typename T>
T usu::shared_ptr<T[]>::operator[](const std::uint32_t idx)
{
	return m_array_ptr[idx];
}

template <typename T>
std::uint32_t usu::shared_ptr<T[]>::size()
{
	return m_array_size;
}