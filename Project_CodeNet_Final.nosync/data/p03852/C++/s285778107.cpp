#include "bits/stdc++.h"
using namespace std;

int main()
{
	char c;
	cin >> c;

	string res = "consonant";

	if (c == 'a') res = "vowel";
	if (c == 'i') res = "vowel";
	if (c == 'u') res = "vowel";
	if (c == 'e') res = "vowel";
	if (c == 'o') res = "vowel";

	cout << res << endl;
}