#pragma once
#include <iostream>
using namespace std;
class myString {
private:
	char* str;
	int length;
	static int counterObject;
public:
	myString();//�	����������� �� ���������, ����������� ������� ������ ������ 80 ��������; 
	myString(int size);//�	�����������, ����������� ��������� ������ ������������� �������; 
	myString(const char* str);//�	�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������. 
	~myString();//�	����������;

	void Input();
	void PrintConsole();

	void SetStr(char* str);//����� �������������� ���� ������ �� ����������
	void SetLen(int userLenght);//����� �������������� ���� ����� �� ����������
	char* GetStr();//������ ���������� ������
	int GetLen();//������ ���������� �����

	myString(myString& otherObj);// ����������� �����
	void AskStrToCheck();
	bool MyStrStr(const char* str, const char* p);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(myString& b); // ��������� ����� 

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