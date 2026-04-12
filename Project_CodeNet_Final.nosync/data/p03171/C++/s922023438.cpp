#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[2][3001][3001];

ll solve(ll a[], ll s, ll f, short chance) {

	if (s > f)
		return 0;

	if (dp[chance][s][f] != -1)
		return dp[chance][s][f];

	if (chance)
		return dp[chance][s][f] = max(a[s] + solve(a, s + 1, f, 0) , a[f] + solve(a, s, f - 1, 0));
	else
		return dp[chance][s][f] = min(solve(a, s + 1, f, 1) - a[s], solve(a, s, f - 1, 1) - a[f]);
}



int main() {

	memset(dp, -1, sizeof dp);

	ll n;
	cin >> n;

	ll a[n];
	for (ll i = 0; i < n; i++) cin >> a[i];

	cout << solve(a, 0, n - 1, 1) << endl;
	return 0;
}