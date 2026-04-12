#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[3003][3003];
ll n, k, arr[3003];

ll solve (int l, int r, int turn) {
	if (l > r) {
		return 0;
	}

	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	if (turn == 0)
		return dp[l][r] = max (arr[l] + solve (l + 1, r, !turn), arr[r] + solve (l, r - 1, !turn));

	return dp[l][r] = min (solve (l + 1, r, !turn), solve (l, r - 1, !turn));
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll sum = 0;
	memset (dp, -1, sizeof dp);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	ll x = solve (0, n - 1, 0);
	ll y = sum - x;
	ll ans = x - y;
	//cout << x << " " << y << " ";
	cout << ans;
	return 0;
}
