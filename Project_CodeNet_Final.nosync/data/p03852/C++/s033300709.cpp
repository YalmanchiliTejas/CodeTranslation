// ABC067_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << "vowel" << endl;
		return 0;
	}
	cout << "consonant" << endl;
	return 0;
}

