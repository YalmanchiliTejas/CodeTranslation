#include <bits/stdc++.h>

using namespace std;

int main() {
	char ch;
	string boin = "aiueo";
	cin >> ch;

	if (boin.find(ch) != string::npos) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}

	return 0;
}