#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cctype>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ll long long

int main()
{
	string s;
	cin >> s;

	bool result = false;
	if (s == "AAA" || s == "BBB")
	{
		result = true;
	}

	cout << (result ? "No" : "Yes") << endl;
    return 0;
}