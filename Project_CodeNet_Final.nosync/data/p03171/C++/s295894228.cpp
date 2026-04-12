#include<bits/stdc++.h>
#define ll long long
#define lld long long double
#define pb push_back
#define mp make_pair
#define M 1000000007
using namespace std;

ll dp[3001][3001][2];

ll f(ll a[], ll i, ll j, bool turn) {
	if (i > j) return 0;
	if (dp[i][j][turn] != -1) return dp[i][j][turn];
	if (turn == 1) {
		return dp[i][j][turn] = max(a[i] + f(a, i + 1, j, 0), a[j] + f(a, i, j - 1, 0));
	}
	else {
		return dp[i][j][turn] = min(f(a, i + 1, j, 1), f(a, i, j - 1, 1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll n; cin >> n;
	ll a[n];
	memset(dp, -1, sizeof(dp));
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll sum1 = f(a, 0, n - 1, 1);
	ll sum2 = sum - sum1;
	cout << sum1 - sum2;
	return 0;
}