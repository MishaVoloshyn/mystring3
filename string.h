#pragma once
#include <iostream>
using namespace std;
class myString {
private:
	char* str;
	int length;
	static int counterObject;
public:
	myString();//Х	конструктор по умолчанию, позвол€ющий создать строку длиной 80 символов; 
	myString(int size);//Х	конструктор, позвол€ющий создавать строку произвольного размера; 
	myString(const char* str);//Х	конструктор, который создаЄт строку и инициализирует еЄ строкой, полученной от пользовател€. 
	~myString();//Х	деструктор;

	void Input();
	void PrintConsole();

	void SetStr(char* str);//—етер инициализируем поле строку из приватного
	void SetLen(int userLenght);//—етер инициализируем поле длину из приватного
	char* GetStr();//√еттер возвращаем строку
	int GetLen();//√еттер возвращаем длину

	myString(myString& otherObj);// копирование строк
	void AskStrToCheck();
	bool MyStrStr(const char* str, const char* p);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyDelChr(char c); // удал€ет указанный символ 
	int MyStrCmp(myString& b); // сравнение строк 

	myString operator+(myString& otherObj);
	myString operator=(const myString& otherObj);

	bool operator>(myString& otherObj);
	bool operator<(myString& otherObj);
	bool operator==(myString& otherObj);
	myString& operator=(const myString&& otherObj);
	myString& operator=(myString&& otherObj);


};

ostream& operator<<(ostream& os, myString& otherObj);
istream& operator>>(istream& is, myString& otherObj);