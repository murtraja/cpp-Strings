#pragma once
#include <cstring>
class String
{
	char *m_buffer{};
	int m_length{};

	void Allocate(const char* ptr);

public:
	String();
	String(const char* ptr);
	String(const String& other);
	String(String&& other);

	int GetLength() const			{ return m_length; };
	const char* GetString() const	{ return m_buffer; };

	void SetString(const char* str);
	void SetString(const String& other);

	void Insert(int index, const char*);
	void Insert(int index, const String& source);
	void Insert(int index, char ch, int count);

	void Remove(int index);
	void RemoveAll(char ch);

	void TrimLeft(int n);
	void TrimRight(int n);

	int Find(const char*, int index);
	int Find(const String&, int index);
	int FindWholeWord(const char* word);
	int FindWholeWord(const String& str);

	String& operator=(const char* str);
	
	String& operator=(const String& other);
	String& operator=(String&& other);
	
	String operator+(const char* str);
	
	String& operator+=(const String& other);
	String& operator+=(const char* str);
	String& operator+=(char ch);
		
	String operator+(const String& other);
	friend  String operator+(const char *lhs, const String &rhs);
		
	const char & operator[](int index)const;
	char & operator[](int index);
	
	bool operator==(const String &other);
	bool operator==(const char *str);
		
	~String();


	void Assign(const char* ptr);
	void Print();
	String Split(int index);
};

/*
String()
String(const String &)
String(const char *)
int GetLength()const
const char * GetString()const
void SetString(const char *)
void SetString(const String &)
void Insert(int index, const char *)
void Insert(int index, const String &source)
void Insert(int index, char ch, int count)
void Remove(int) (Remove a character through index)
void RemoveAll(char) (Remove all occurrences of a character)
void TrimLeft(int n) (Trim n characters from left)
void TrimRight(int n) Trim n characters from right)
int Find(const char *,int index)
int Find(const String &,int index)
int FindWholeWord(const char *)
int FindWholeWord(const String &)
String & operator =(const String &)
String & operator =(const char *)
String operator +(const String &)
String operator +(const char *)
String operator +=(const String &)
String &operator +=(const char *)
String &operator +=(char)
friend  String operator +(const char *, const String &)
const char & operator [](int)const
char & operator [](int)
bool String operator==(const String &)
bool String operator==(const char *)
*/