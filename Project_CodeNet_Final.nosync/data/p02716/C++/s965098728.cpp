#include <cstdio>
#include <algorithm>

long long dp[200001][2][3];

int main()
{
	int n;
	scanf("%d", &n);
	int a[200000];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	dp[1][0][0] = -1e18;
	dp[1][0][1] = 0;
	dp[1][0][2] = -1e18;

	dp[1][1][0] = a[0];
	dp[1][1][1] = -1e18;
	dp[1][1][2] = -1e18;

	for (int i = 2; i <= n; ++i)
	{
		dp[i][0][0] = dp[i - 1][1][0];
		dp[i][0][1] = std::max(dp[i - 1][1][1], dp[i - 1][0][0]);
		dp[i][0][2] = std::max(dp[i - 1][1][2], dp[i - 1][0][1]);

		dp[i][1][0] = std::max(a[i - 1] + dp[i - 1][0][0], (long long)-1e18);
		dp[i][1][1] = std::max(a[i - 1] + dp[i - 1][0][1], (long long)-1e18);
		dp[i][1][2] = std::max(a[i - 1] + dp[i - 1][0][2], (long long)-1e18);
	}
	long long ans = -1e18;
	if (n % 2 == 0)
	{
		ans = std::max(dp[n][0][0], dp[n][1][1]);
	}
	else
	{
		ans = std::max(dp[n][0][1], dp[n][1][2]);
	}
	printf("%lld\n", ans);
	return 0;
}
