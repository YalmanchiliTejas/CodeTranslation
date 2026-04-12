#include <iostream>
using namespace std;

int main() {
	char word;
	cin >> word;

	if (word == 'a' || word == 'i' || word == 'u' || word == 'e' || word == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}

	return 0;
}
