#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include"string.h";
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

myString::myString()
{
	length = 80;
	str = new char[length + 1];
}

myString::myString(int size)
{
	length = size;
	str = new char[length + 1];
}

myString::myString(const char* user)
{
	length = strlen(user) + 1;
	str = new char[length];
	strcpy_s(str, strlen(user) + 1, user);
}

myString::~myString()
{
	delete[]str;
}

void myString::Input()
{
	char buffer[88];
	cout << "Input your string!!!" << endl;
	cin.getline(buffer, strlen(buffer));
	length = strlen(buffer);
	str = new char[strlen(buffer) + 1];
	strcpy_s(str, strlen(buffer) + 1, buffer);
}

void myString::PrintConsole()
{
	cout << str << endl;
}

void myString::SetStr(char* userStr)
{
	str = userStr;
}

void myString::SetLen(int userLenght)
{
	length = userLenght;
}

char* myString::GetStr()
{
	return str;
}

int myString::GetLen()
{
	return length;
}



myString::myString(myString& otherObj)
{
	length = otherObj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, otherObj.str);
}

void myString::AskStrToCheck()
{
	const char* p;
	char subs[50];
	cout << "Enter substring: ";
	cin >> subs;
	p = strstr(str, subs);
	MyStrStr(str, p);
}

bool myString::MyStrStr(const char* str, const char* p)
{

	if (p) {
		cout << "True" << endl;
		return true;
	}
	else {
		cout << "False" << endl;
		return false;
	}

}

int myString::MyChr(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			cout << "index= ";
			return i;

		}

	}
	return -1;
}

int myString::MyStrLen()
{
	return  strlen(str) + 1;
}

myString myString::operator+(myString& otherObj)
{
	myString b;
	int sizeobj1 = this->length - 1;
	int sizeobj2 = otherObj.length - 1;
	b.length = sizeobj1 + sizeobj2;
	b.str = new char[b.length + 1];
	strcpy(b.str, str);
	strcat(b.str, otherObj.str);
	return b;
}

myString myString::operator=(const myString& otherObj)
{
	if (&otherObj != this)
	{
		this->length = otherObj.length;

		this->str = new char[otherObj.length];

		for (int i = 0; i < otherObj.length; i++)
		{
			this->str[i] = otherObj.str[i];
		}

	}
	return *this;
}

void myString::MyDelChr(char c)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			counter++;
		}
	}
	int size = length - counter;

	char* temp = new char[size + 1];
	for (int i = 0, k = 0; i < size + 1; i++)
	{
		if (str[i] != c)
		{
			temp[k] = str[i];
			k++;
		}
	}
	delete[]str;
	length = size;
	str = new char[length + 1];
	str = temp;

}

int myString::MyStrCmp(myString& b)
{
	if (strcmp(str, b.str) == -1)
	{
		return -1;
	}
	else if (strcmp(str, b.str) == 1)
	{
		return 1;
	}
	else if (strcmp(str, b.str) == 0)
	{
		return 0;
	}

}

bool myString::operator>(myString& otherObj)
{
	if (strcmp(str, otherObj.str) == 1)
	{
		return true;
	}
	return false;
}

bool myString::operator<(myString& otherObj)
{
	if (strcmp(str, otherObj.str) == -1)
	{
		return true;
	}
	return false;
}

bool myString::operator==(myString& otherObj)
{
	if (strcmp(str, otherObj.str) == 0)
	{
		return true;
	}
	return false;
}

myString& myString::operator=(myString&& otherObj)
{
	if (this != &otherObj) {
		delete[] str;
		str = otherObj.str;
		length = otherObj.length;
		otherObj.str = nullptr;
		otherObj.length = 0;
	}
	return *this;
}

ostream& operator<<(ostream& os, myString& otherObj)
{
	os << "String: " << otherObj.GetStr() << endl;
	return os;

}

istream& operator>>(istream& is, myString& otherObj)
{
	char buff[100];
	is >> buff;
	char* ch = new char[strlen(buff) + 1];
	strcpy_s(ch, strlen(buff) + 1, buff);
	otherObj.SetLen(strlen(buff));
	otherObj.SetStr(ch);
	return is;
}
