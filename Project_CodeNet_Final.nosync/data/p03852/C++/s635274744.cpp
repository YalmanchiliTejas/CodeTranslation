#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	char s;
	cin >> s;
	if (s == 'a' || s == 'i' || s == 'e' || s == 'o' || s == 'u')
		cout << "vowel";
	else
		cout << "consonant";
}