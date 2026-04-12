#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	string str1 = "AAA";
	string str2 = "BBB";

	cin >> str;

	if (str==str2 || str==str1)
	{
		cout << "No" << endl;
		return 0;
	}
	else
	{
		cout << "Yes" << endl;
	}
	return 0;
}
