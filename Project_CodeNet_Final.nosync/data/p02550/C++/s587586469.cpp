#include "bits/stdc++.h"

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define int long long
#define ll long long

ll INF = (1LL << 60);
int mod = 998244353;
using P = pair<int, int>;

signed main() {
	int n, x, m; cin >> n >> x >> m;
	vector<int>a(m);
	for (int i = 0; i < m; i++) {
		a[i] = (i*i) % m;
	}
	vector<vector<int>>next(45, vector<int>(m)), sum(45, vector<int>(m));
	for (int i = 0; i < m; i++) {
		next[0][i] = a[i];
	}
	for (int i = 1; i < 45; i++) {
		for (int j = 0; j < m; j++) {
			next[i][j] = next[i - 1][next[i - 1][j]];
		}
	}
	for (int i = 0; i < m; i++) {
		sum[0][i] = i;
	}
	for (int i = 1; i < 45; i++) {
		for (int j = 0; j < m; j++) {
			sum[i][j] = sum[i - 1][next[i - 1][j]] + sum[i - 1][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 45; i++) {
		if (n >> i & 1) {
			ans += sum[i][x];
			x = next[i][x];
		}
	}
	cout << ans << endl;
	return 0;
}
