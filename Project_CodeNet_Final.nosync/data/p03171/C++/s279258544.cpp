#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll v[3000];
ll dp[3000][3000][2];

ll f(int a, int b, int t) {
	if (a == b) return !t * v[a];
	if (dp[a][b][t]) return dp[a][b][t];

	ll r = 0;
	if (t == 0) r = max(f(a+1, b, 1) + v[a], f(a, b-1, 1) + v[b]);
	else r = min(f(a+1, b, 0), f(a, b-1, 0));

	dp[a][b][t] = r;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> v[i];
	ll s = 0;
	for (int i = 0; i < n; ++i) s += v[i];
	cout << 2 * f(0, n-1, 0) - s << '\n';
}
