#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e3 + 10;
ll a[N], dp[N][N][2];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int t = 2; t <= n; t++)
	{
		for (int l = 1; l + t - 1 <= n; l++)
		{
			int r = l + t - 1;
			dp[l][r][0] = max(a[l] + dp[l + 1][r][1], a[r] + dp[l][r - 1][1]);
			dp[l][r][1] = min(-a[l] + dp[l + 1][r][0], -a[r] + dp[l][r - 1][0]);
		}
	}
	cout << dp[1][n][0];
}
