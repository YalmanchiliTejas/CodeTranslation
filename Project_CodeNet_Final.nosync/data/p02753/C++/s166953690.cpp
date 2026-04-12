#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	bool ha = 0, hb = 0;
	for (char c : s) {
		if (c == 'A') ha = 1;
		else hb = 1;
	}
	if (ha && hb) cout << "Yes\n";
	else cout << "No\n";
}
