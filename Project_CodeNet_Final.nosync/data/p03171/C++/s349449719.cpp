#include <bits/stdc++.h>

const int N = 3005;
int n, a[N];
long long dp[N][N][2];
bool calc[N][N][2];

long long f(int l, int r, bool ply) {
  if (calc[l][r][ply])
    return dp[l][r][ply];

  calc[l][r][ply] = true;

  if (l == r)
    return dp[l][r][ply] = (ply ? -a[l] : a[l]);

  long long x = f(l+1, r, !ply) + (ply ? -a[l] : a[l]);
  long long y = f(l, r-1, !ply) + (ply ? -a[r] : a[r]);

  return dp[l][r][ply] = (ply ? std::min(x, y) : std::max(x, y));
}

int32_t main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", a+i);

  printf("%lld\n", f(0, n-1, 0));
  return 0;
}
