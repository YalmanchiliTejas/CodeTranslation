#include <cstring>
#include <iostream>
#include <algorithm>

#pragma warning(disable : 4996)

#define mod 1000000007

using namespace std;

long long N, D, X, inv[2001]; long long dp[2001][2001];

int ncr(long long n, long long r)
{
	if (n < r) { return 0; }

	long long ret = 1;

	for (int i = 0; i < r; i++)
	{
		ret = n-- % mod * ret % mod;
	}
	
	for (int i = 1; i <= r; i++)
	{
		ret = ret * inv[i] % mod;
	}

	return ret;
}

int main()
{
	inv[1] = 1;

	for (int i = 2; i <= 2000; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	
	while (true)
	{
		scanf("%lld", &N);
		scanf("%lld", &D);
		scanf("%lld", &X);

		if (N == 0 && D == 0 && X == 0) { break; }

		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		for (int i = 1; i <= N; i++)
		{
			for (int j = i; j <= N; j++)
			{
				if (j < X)
				{
					dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
				}
				else
				{
					dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i - 1][j - 1] - dp[i - 1][j - X] + mod) % mod;
				}
			}
		}

		long long ret = 0;

		for (int i = 1; i <= N; i++)
		{
			ret = (ret + ncr(D, i) * dp[i][N]) % mod;
		}

		printf("%lld\n", ret);
	}

	return 0;
}