// OperatorOverload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"

void Basic()
{
	String s = "Hello";
	s += " ";
	s += "World";
	s.Print();
}

void CheckInsert()
{
	String s = "Hello";
	const char* s2 = " says he";
	s.Insert(2, s2);
	s.Print();
}

int main()
{
	//Basic();
	CheckInsert();
    return 0;
}

