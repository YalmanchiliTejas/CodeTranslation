#include <iostream>
using namespace std;

int main (void) {
	const string vowel = "aeiou";
	char input;

	cin >> input;
	string output = vowel.find(input)!= string::npos ? "vowel" : "consonant";
	cout << output << endl;
}