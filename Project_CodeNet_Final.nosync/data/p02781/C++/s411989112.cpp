#include <cstdio>
#include <algorithm>
#include <cstring>

long long dp[110][2][4];
int main()
{
	char s[110];
	int k;
	scanf("%s%d", &s, &k);
	int n = strlen(s);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int less = 0; less < 2; ++less)
		{
			const int D = s[i] - '0';
			for (int j = 0; j < k; ++j)
			{
				for (int d = 0; d <= (less ? 9 : D); ++d)
				{
					dp[i + 1][(less || d < D)][j + (d == 0 ? 0 : 1)] += dp[i][less][j];
				}
			}
			dp[i + 1][less || 0 < D][k] += dp[i][less][k];
		}
	}
	printf("%lld\n", dp[n][0][k] + dp[n][1][k]);
}
