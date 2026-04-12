#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll v[3004];
ll dp[3005][3005][2];

ll solve(ll i, ll j, int turn) {
	if (i > j)
		return 0;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if (turn == 1)
		return dp[i][j][turn] = max(v[i] + solve(i + 1, j, 0), v[j] + solve(i , j - 1, 0));
	else return dp[i][j][turn] = min(solve(i + 1, j, 1), solve(i, j - 1, 1));
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
	ll res = solve(0, n - 1, 1);
	ll dif = sum - res;
	cout << res - dif;

	return 0;
}

