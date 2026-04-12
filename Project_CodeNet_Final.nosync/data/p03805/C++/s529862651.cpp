#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);
	long long ans = 0;
	do {
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			bool found = false;
			for (int &nbr : g[perm[i]]) {
				if (nbr == perm[i + 1]) found = true;
			}
			ok &= found;
		}
		ans += ok;
	} while (next_permutation(perm.begin() + 1, perm.end()));
	cout << ans << endl;
	return 0;
}
