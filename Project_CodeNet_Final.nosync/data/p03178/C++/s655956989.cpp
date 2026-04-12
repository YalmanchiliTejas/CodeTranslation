#include <bits/stdc++.h>

const int N = 1e4+5, MOD = 1e9+7, D = 105;
char str[N];
int n, d, dp[N][2][D];

void add_self(int& a, int b, int mod) {
  a += b;
  if (a >= mod)
    a -= mod;
}

void sub_self(int& a, int b, int mod) {
  a -= b;
  if (a < 0)
    a += mod;
}

int add(int a, int b, int mod) {
  return (a + b) % mod;
}

int f(int pos, bool limited, int cur_sum) {
  assert(cur_sum < d);

  if (pos >= n)
    return (cur_sum == 0);

  if (dp[pos][limited][cur_sum] != -1)
    return dp[pos][limited][cur_sum];

  int ans = 0;
  int max_digit = limited ? str[pos] : 9;

  for (int i = 0; i <= max_digit; i++) {
    if (i == max_digit && limited) {
      int tmp = f(pos + 1, 1, add(cur_sum, i, d));
      add_self(ans, tmp, MOD);
    } else {
      int tmp = f(pos + 1, 0, add(cur_sum, i, d));
      add_self(ans, tmp, MOD);
    }
  }

  return dp[pos][limited][cur_sum] = ans;
}

int32_t main() {
  scanf("%s%d", str, &d);

  n = strlen(str);
  for (int i = 0; i < n; i++)
    str[i] -= '0';

  memset(dp, -1, sizeof dp);
  int ans = f(0, 1, 0);
  sub_self(ans, 1, MOD);
  printf("%d\n", ans);
  return 0;
}
