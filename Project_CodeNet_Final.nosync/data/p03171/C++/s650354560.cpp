#include <cstdio>
#include <algorithm>

long long dp[3000][3000];
long long a[3000];

long long solve(int l, int r)
{
  if (dp[l][r] != 1e18) return dp[l][r];
  if (l == r)
  {
    dp[l][r] = a[l];
  }
  else
  {
    dp[l][r] = std::max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
  }  
  return dp[l][r];
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld", a + i);
  }
  std::fill((long long*)dp, (long long*)dp + 3000 * 3000, 1e18);
  printf("%lld\n", solve(0, n - 1));
  return 0;
}
