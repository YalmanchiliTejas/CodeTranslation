#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll v[3004];
ll dp[3005][3005];

ll solve(ll i, ll j) {
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = max(v[i] + min(solve(i + 2, j), solve(i + 1, j - 1)), v[j] + min(solve(i + 1, j - 1), solve(i, j - 2)));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	ll n;
	cin >> n;
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		cin >> v[i], sum += v[i];
	ll res = solve(0, n - 1);
	ll dif = sum - res;
	cout << res - dif;

	return 0;
}

