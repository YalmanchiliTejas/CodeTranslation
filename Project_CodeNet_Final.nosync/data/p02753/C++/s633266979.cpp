#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = (int)s.length();
	int a = 0, b = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') a++;
		else b++;
	}

	if (a == 0 || b == 0) cout << "No";
	else cout << "Yes";
}