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

int main()
{
	Basic();
    return 0;
}

