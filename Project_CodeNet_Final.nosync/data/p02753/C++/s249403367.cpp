#include <bits/stdc++.h>
using namespace std;

signed main () {
	string s;
	cin >> s;
	bool y = 0;
	for (int i = 0; i < int(s.size()) - 1; ++i) {
		if (s[i] != s[i + 1])
			y = 1;
	}
	if (y)
		cout << "Yes\n";
	else
		cout << "No\n";
}
