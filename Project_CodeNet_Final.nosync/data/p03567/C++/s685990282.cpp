#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		bool f = true;
		for (int j = 0; j < 2; j++) {
			f &= s[i + j] == "AC"[j];
		}
		if (f) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}