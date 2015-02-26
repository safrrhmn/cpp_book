/***************************************************
Page 849, #1
Write a program that prompts the user to input a string and outputs the
string in uppercase letters. (Use a character array to store the string.)

Author: Saifur Rahman
Purpose: Take user input as string and output
as uppercased string using char array

***************************************************/

#include <iostream>
#include <string>
#pragma warning(disable: 4996)

using namespace std;


int program1()
{
	int j = 0;
	string s;
	char *cstr = new char[j];

	cout << "Type any string needs to be uppercased and hit Enter: " << endl;
	cin >> s;
	j = s.size();

	strcpy(cstr, s.c_str());

	for (int i = 0; i < j; i++)
	{
		cout << static_cast<char>(toupper(cstr[i]));
	}

	return 0;
}