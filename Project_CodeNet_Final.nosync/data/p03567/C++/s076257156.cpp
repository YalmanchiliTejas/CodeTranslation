#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool r = false;
	for (int i = 0; i < s.length(); i++) {
		r |= (s[i] == 'A' && s[i + 1] == 'C');
	}
	cout << (r ? "Yes" : "No") << endl;
	return 0;
}
