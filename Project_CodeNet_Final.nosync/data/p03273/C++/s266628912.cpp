#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	vector<bool> f1(n, true), f2(m, true);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				f1[i] = false;
				f2[j] = false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (f1[i]) continue;
		for (int j = 0; j < m; j++) {
			if (f2[j]) continue;
			cout << s[i][j];
		}
		cout << "\n";
	}
	return 0;
}
