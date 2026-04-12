#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	char s;
	cin >> s;
	cout << (s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o' ? "vowel" : "consonant") << endl;
}