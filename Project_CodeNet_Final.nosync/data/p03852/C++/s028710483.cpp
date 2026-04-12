#include<iostream>
using namespace std;

int main(void) {
	int flag = 0;
	char letter;
	// char Vowels[5] = { "a","b", "c","d","e" };
	string Vowel = "aiueo";
	cin >> letter;

	for (int i = 0; i <= 4; i++) {
		if (letter == Vowel[i]) {
			cout << "vowel" << endl;
			flag = 1;
			break;
		}
	}

	if (flag==0) cout << "consonant" << endl;

	return 0;
}