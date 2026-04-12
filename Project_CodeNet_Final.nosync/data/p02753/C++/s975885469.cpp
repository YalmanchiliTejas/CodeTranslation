#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	char x = s[0];
	bool ans = true;
	for (int i = 1; i < 3; i++) {
		if (s[i] != x) {
			ans = false;
		}
	}
	if (ans) {

	cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}
