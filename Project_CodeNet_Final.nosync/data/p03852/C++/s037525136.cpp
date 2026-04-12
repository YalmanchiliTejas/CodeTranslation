#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;

	if (a == "a" || a == "i" || a == "u" || a == "e" || a == "o") {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}