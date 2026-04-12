#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3010;
int n;
ll a[N], pref[N];
ll dp[N][N][2];
bool vis[N][N][2];

ll solve(int l, int r, int t)
{
	if (l > r)
		return 0;
	ll &ret = dp[l][r][t];
	if (vis[l][r][t])
		return ret;
	vis[l][r][t] = true;
	if (t == 0)
	{
		ll val = max(a[l] + solve(l + 1, r, 1), a[r] + solve(l, r - 1, 1));
		ret = val;
	}
	else
	{
		ll val = min(-a[l] + solve(l + 1, r, 0), -a[r] + solve(l, r - 1, 0));
		ret = val;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	memset(dp, -1, sizeof(dp));
	memset(vis, false, sizeof(vis));
	ll ans = solve(1, n, 0);
	cout << ans;

	return 0;
}