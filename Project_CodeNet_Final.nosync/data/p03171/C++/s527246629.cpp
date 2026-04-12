#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3+10;

typedef long long ll;

int num[maxn];

ll dp[maxn][maxn][2];

ll solve(int l, int r, bool q)
{
	if (l > r) return 0LL;
	if (dp[l][r][q] != -1) return dp[l][r][q];

	ll ans;

	if (q)
	{
		ans = 1LL*num[l]+solve(l+1, r, !q);
		ans = max(ans, 1LL*num[r]+solve(l, r-1, !q));
	}
	else
	{
		ans = solve(l+1, r, !q)-1LL*num[l];
		ans = min(ans, solve(l, r-1, !q)-1LL*num[r]);
	}

	return dp[l][r][q] = ans;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	memset(dp, -1, sizeof dp);

	cout << solve(1, n, 1) << "\n";
}