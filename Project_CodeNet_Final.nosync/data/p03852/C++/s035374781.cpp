#include <iostream>
#include <string>

using namespace std;

int main() {
	// your code goes here
	string s;
	cin >> s;
	
	if(s == "a" || s == "i" || s == "u" || s == "e" || s == "o") cout << "vowel" << endl;
	else cout << "consonant" << endl;
	
	return 0;
}