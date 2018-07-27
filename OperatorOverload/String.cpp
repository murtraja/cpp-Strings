#include "stdafx.h"
#include "String.h"
#include <iostream>
#include <cassert>

void String::Allocate(const char * ptr)
{
	int length = strlen(ptr);
	m_buffer = new char[length + 1];
	strcpy(m_buffer, ptr);
	m_length = length;
}

String::String()
{
	m_buffer = new char[1];
	*m_buffer = '\0';
}

String::String(const char * ptr)
{
	Allocate(ptr);
}

String::String(const String & other)
{
	Allocate(other.m_buffer);
}

String::String(String && other)
{
	m_buffer = other.m_buffer;
	m_length = other.m_length;
	other.m_buffer = nullptr;
	other.m_length = 0;
}

void String::SetString(const char * str)
{
	Assign(str);
}

void String::SetString(const String & other)
{
	Assign(other.m_buffer);
}

void String::Insert(int index, const char *source)
{
	String rhs = Split(index);
	(*this) += source;
	(*this) += rhs;
}

void String::Insert(int index, const String & source)
{
}

void String::Insert(int index, char ch, int count)
{
}

void String::Remove(int index)
{
}

void String::RemoveAll(char ch)
{
}

void String::TrimLeft(int n)
{
	assert(n>=1 && n<m_length);
	
	char *newBuffer = new char[m_length - n + 1];
	strcpy(newBuffer, m_buffer + n);
	newBuffer[m_length - n] = 0;
	m_length -= n;
	delete[] m_buffer;
	m_buffer = newBuffer;
}

void String::TrimRight(int n)
{
	assert(n >= 1 && n<m_length);

	char *newBuffer = new char[m_length - n + 1];
	strncpy(newBuffer, m_buffer, m_length - n);
	newBuffer[m_length - n] = 0;
	m_length -= n;
	delete[] m_buffer;
	m_buffer = newBuffer;
}

int String::Find(const char *str, int index)
{
	for (int i = index; i < m_length; i++)
	{
		if (strcmp(m_buffer + i, str) == 0)
		{
			return i;
		}
	}
	return -1;
}

int String::Find(const String &str, int index)
{
	return Find(str.m_buffer, index);
}

int String::FindWholeWord(const char * word)
{
	return 0;
}

int String::FindWholeWord(const String & str)
{
	return 0;
}

String & String::operator=(const char * str)
{
	// TODO: insert return statement here
	return (*this);
}

String & String::operator=(const String & other)
{
	char* old = m_buffer;
	Allocate(other.m_buffer);
	delete[] old;
	return *this;
}

String & String::operator=(String && other)
{
	m_buffer = other.m_buffer;
	m_length = other.m_length;
	other.m_buffer = nullptr;
	other.m_length = 0;

	return *this;
}

String String::operator+(const char * str)
{
	return String();
}


String::~String()
{
	delete[] m_buffer;
}

String & String::operator+=(const String & other)
{
	int newLength = m_length + other.m_length;
	char* newString = new char[newLength + 1];
	strcpy(newString, m_buffer);
	strcat(newString, other.m_buffer);
	delete[] m_buffer;
	m_buffer = newString;
	m_length = newLength;
	return *this;
}

String & String::operator+=(const char * str)
{
	int newLength = m_length + strlen(str);
	char* newString = new char[newLength + 1];
	strcpy(newString, m_buffer);
	strcat(newString, str);
	delete[] m_buffer;
	m_buffer = newString;
	m_length = newLength;
	return (*this);
}

String & String::operator+=(char ch)
{
	// TODO: insert return statement here
	return (*this);
}

String String::operator+(const String & other)
{
	String result{ m_buffer };
	result += other;
	return result;
}

const char & String::operator[](int index) const
{
	return m_buffer[index];
}

char & String::operator[](int index)
{
	return m_buffer[index];
}

bool String::operator==(const String & other)
{
	return false;
}

bool String::operator==(const char * str)
{
	return false;
}

void String::Assign(const char * ptr)
{
	char* old = m_buffer;
	Allocate(ptr);
	delete[] old;
}

void String::Print()
{
	std::cout << m_buffer << std::endl;
}

String String::Split(int index)
{
	int lengthOfRhs = m_length - index;
	char* rhsBuffer = new char[lengthOfRhs + 1];
	String rhs{ m_buffer + index };
	TrimRight(lengthOfRhs);
	return rhs;
}

String operator+(const char * lhs, const String & rhs)
{
	return String();
}
