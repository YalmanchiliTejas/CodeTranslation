#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	bool ok = false;
	for (int i = 1; i < s.length(); i++) if (s[i - 1] == 'A' && s[i] == 'C') ok = true;
	if (ok) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}