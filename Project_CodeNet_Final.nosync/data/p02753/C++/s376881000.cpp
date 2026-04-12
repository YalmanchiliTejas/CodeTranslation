#include "bits/stdc++.h"
using namespace std;


string s;


int main() {
	cin >> s;

	bool ok = false;
	for (int i = 0; i < s.length() - 1; i++) {
		if ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'A')) {
			ok = true;
		}
	}

	if (ok) cout << "Yes\n";
	else cout << "No\n";
}