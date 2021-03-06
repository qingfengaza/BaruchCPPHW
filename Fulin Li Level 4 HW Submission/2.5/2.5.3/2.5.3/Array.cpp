// Array.cpp
//
// Header file for Array class.
//
// @author Fulin Li
// @version 1.0 11/9/14

#include "Point.hpp"
#include "Array.hpp"
using namespace std;

Array::Array() : m_data(new Point[10]), m_size(10)
{
}

Array::Array(int size) : m_data(new Point[size]), m_size(size)
{
}

Array::Array(const Array& pp)
{
	m_data = new Point[pp.m_size];
	m_size = pp.m_size;

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = pp.m_data[i];
	}
}

Array::~Array()
{
	delete[] m_data;
}

Array& Array::operator = (const Array& source)
{
	if (this == &source)
	{
		return *this;
	}

	delete[] m_data;

	m_data = new Point[source.m_size];
	m_size = source.m_size;

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i];
	}

	return *this;
}

Point& Array::operator [] (int index)
{
	if (index >= m_size)
	{
		return m_data[0];
	}

	return m_data[index];
}

const Point& Array::operator [] (int index) const
{
	// Const version of the square bracket operator.
	// Purpose: 
	// 1) Allow the user to read, but not to write.
	// 2) Allow Array objects declared as const to work.

	if (index >= m_size)
	{
		return m_data[0];
	}

	return m_data[index];
}

int Array::Size() const
{
	return m_size;
}

Point& Array::GetElement(int index) const
{
	if (index >= m_size)
	{
		return m_data[0];
	}

	return m_data[index];
}

void Array::SetElement(int index, const Point& newPoint)
{
	if (index >= m_size)
	{
		return;
	}

	m_data[index] = newPoint;
}
