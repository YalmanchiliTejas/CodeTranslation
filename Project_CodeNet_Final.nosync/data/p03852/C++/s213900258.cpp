#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	char c;
	cin >> c;

	string v = "aiueo";
	for (int i = 0; i < 5; ++i) {
		if (v[i] == c) {
			cout << "vowel" << endl;
			return 0;
		}
	}

	cout << "consonant" << endl;

	return 0;
}
