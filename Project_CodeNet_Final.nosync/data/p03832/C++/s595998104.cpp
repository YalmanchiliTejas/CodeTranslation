#include <cstdio>

const int mod = 1e9 + 7;
const int maxn = 1e3 + 10;

long long fac[maxn];
long long inv[maxn];
long long facinv[maxn];
long long dp[maxn][maxn];
long long pwfacinv[maxn][maxn];

int main()
{
	int N, A, B, C, D;
	scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
	fac[0] = fac[1] = inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	dp[A - 1][0] = 1;
	for (int i = A; i <= B; ++i)
	{
		pwfacinv[i][0] = 1;
		for (int j = 1; j <= N; ++j)
			pwfacinv[i][j] = pwfacinv[i][j - 1] * facinv[i] % mod;
		for (int j = 0; j <= N; ++j)
		{
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			for (int k = C; k <= D && j + i * k <= N; ++k)
			{
				dp[i][j + i * k] = (dp[i][j + i * k] + dp[i - 1][j] * pwfacinv[i][k] % mod * facinv[k] % mod) % mod;
			}
		}
	}
	printf("%lld\n", dp[B][N] * fac[N] % mod);
	return 0;
}
