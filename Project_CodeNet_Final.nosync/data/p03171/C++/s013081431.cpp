#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define endl '\n'
#define MOD 1000000007
#define MOD2 998244353

using namespace std;
typedef long long int ll;

ll dp[3001][3001][2];
ll a[3001];
int n;

ll calc(int l, int r, int p)
{
	if (l == r) return a[l];
	ll &ret = dp[l][r][p];
	if (ret != -1) return ret;
	ret = max(a[l] - calc(l+1, r, p^1), a[r] - calc(l, r-1, p^1));
	return ret;
}

int main(void)
{
	fast;
	#ifndef ONLINE_JUDGE
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	#endif

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << calc(0, n-1, 0);
}