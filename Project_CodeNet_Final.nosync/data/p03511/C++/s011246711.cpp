#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int L; cin >> L;
	string s, t; cin >> s >> t;
	if (cmp(t, s)) swap(s, t);

	int S = s.size(), T = t.size();
	for (int i = L / S; i >= 0; --i) {
		int j = (L - S * i);
		if (j % T) continue;
		j /= T;
		string ans = "";
		while(i--) ans += s;
		while(j--) ans += t;
		cout << ans << endl;
		return 0;
	}
}