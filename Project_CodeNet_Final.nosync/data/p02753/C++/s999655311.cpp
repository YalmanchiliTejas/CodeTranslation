#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	if ((s.at(0) == s.at(1)) && (s.at(1) == s.at(2)))
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}

	return 0;
}