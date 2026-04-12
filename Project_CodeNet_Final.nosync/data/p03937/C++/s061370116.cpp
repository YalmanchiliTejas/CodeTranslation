#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<vector<char> > a(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '#') ++cnt;
		}
	}
	if (cnt != n + m - 1) { cout << "Impossible"; return 0; }
	pair<int, int> pr = { 0, 0 };
	while (pr.first != n - 1 && pr.second != m - 1) {
		if (a[pr.first][pr.second + 1] == '#') pr.second++;
		else if (a[pr.first + 1][pr.second] == '#') pr.first++;
		else {
			cout << "Impossible";
			return 0;
		}
	}
	cout << "Possible";
	return 0;
}