#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	string c;
	cin >> c;

	if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u")cout << "vowel\n";
	else cout << "consonant\n";
	

	return 0;
}