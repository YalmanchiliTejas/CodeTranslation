#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var << endl;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

string s[56];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	map<char, int> ans;
	for (char c: s[0]) {
		++ans[c];
	}
	for (int i = 1; i < n; ++i) {
		map<char, int> cur;
		for (char c: s[i]) {
			++cur[c];
		}
		for (const auto &e: ans) {
			ans[e.first] = min(ans[e.first], cur[e.first]);
		}
	}
	for (const auto &e: ans) {
		if (e.second) {
			for (int i = 0; i < e.second; ++i) cout << e.first;
		}
	}
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
