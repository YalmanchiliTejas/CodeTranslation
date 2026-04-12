#include <cstdio>

constexpr long long mod = 1000000007;
long long dp[10002][100][2];

int main()
{
  char s[100002];
  int D;
  scanf("%s%d", s, &D);

  dp[0][0][0] = 1;
  int i;
  for (i = 0; s[i]; ++i)
  {
    int d = s[i] - '0';
    for (int j = 0; j < 2; ++j)
    {
      for (int m = 0; m < D; ++m)
      {
        for (int k = 0; k <= (j ? 9 : d); ++k)
        {
          (dp[i + 1][(m + k) % D][j || k < d] += dp[i][m][j]) %= mod;
        }
      }
    }
  }
  printf("%lld\n", (dp[i][0][0] + dp[i][0][1] + mod - 1) % mod);
  return 0;
}