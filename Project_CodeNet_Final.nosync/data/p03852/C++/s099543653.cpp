#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	if (("a" == S) || ("i" == S) || ("u" == S) || ("e" == S) || ("o" == S)) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}