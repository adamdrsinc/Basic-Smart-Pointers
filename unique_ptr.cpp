#include "unique_ptr.hpp"
#include <exception>

template <typename T>
usu::unique_ptr<T>::unique_ptr()
{
}

template <typename T>
usu::unique_ptr<T>::unique_ptr(T* ptr) :
    m_ptr(ptr)
{
}

template <typename T>
usu::unique_ptr<T>::unique_ptr(unique_ptr&& moved_unique_ptr):
    m_ptr(moved_unique_ptr.m_ptr)
{
    delete moved_unique_ptr;
    moved_unique_ptr = nullptr;
}

template <typename T>
usu::unique_ptr<T>::~unique_ptr()
{
    delete m_ptr;
    m_ptr = nullptr;
}

template <typename T>
void usu::unique_ptr<T>::operator=(unique_ptr&& moved_unique_ptr)
{
    m_ptr = moved_unique_ptr.m_ptr;

	delete moved_unique_ptr;
    moved_unique_ptr.m_ptr = nullptr;
}

template <typename T>
T* usu::unique_ptr<T>::operator->()
{
    return m_ptr;
}

template <typename T>
T usu::unique_ptr<T>::operator*()
{
    return *m_ptr;
}

template <typename T>
bool usu::unique_ptr<T>::operator==(const unique_ptr& other_unique_ptr)
{

}

template <typename T>
bool usu::unique_ptr<T>::operator!=(const unique_ptr& other_unique_ptr)
{
	std::terminate();
	return false;
}

template <typename T>
T* usu::unique_ptr<T>::get()
{
	std::terminate();
	return nullptr;
}

template <typename T>
T* usu::unique_ptr<T>::release()
{
	std::terminate();
	return nullptr;
}