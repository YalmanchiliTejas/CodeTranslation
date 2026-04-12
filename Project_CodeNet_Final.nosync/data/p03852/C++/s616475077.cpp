
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;

int main()
{
	
	string s;

	cin >> s;

	if (s == "a" || s == "i" || s == "u" || s == "e" || s == "o")
	{
		cout << "vowel" << endl;
	}

	else
	{
		cout << "consonant" << endl;
	}

	
	return 0;
}
