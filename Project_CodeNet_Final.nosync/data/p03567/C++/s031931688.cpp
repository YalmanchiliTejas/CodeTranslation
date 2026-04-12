#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;

	bool ok = false;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s.substr(i, 2) == "AC") { ok = true; }
	}

	if (ok) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }

	return 0;
}
