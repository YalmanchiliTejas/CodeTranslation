#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	string c;

	cin >> c;
	if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}