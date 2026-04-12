#include <bits/stdc++.h>

using namespace std;


int main() {

	char S[1];

	cin >> S;

	if((S[0] == 'a') || (S[0] == 'i') || (S[0] == 'u') || (S[0] == 'e') || (S[0] == 'o')) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}

	return 0;
}
