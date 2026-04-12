#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define D(x) cerr << #x << " = " << (x) << '\n'
using ll = long long;

const int maxn = 200123;
ll dp[maxn][3], a[maxn], n;

ll solve(int idx, int skips) {
	if(idx >= n) {
		return skips <= 1 ? 0 : -1e18;
	}
	ll &res = dp[idx][skips];
	if(~res) return res;
	res = a[idx] + solve(idx + 2, skips);
	for(int i = 1; i <= skips; ++ i) res = max(res, solve(idx + i, skips - i));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++ i) cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << solve(0, 1 + n % 2) << '\n';
}
