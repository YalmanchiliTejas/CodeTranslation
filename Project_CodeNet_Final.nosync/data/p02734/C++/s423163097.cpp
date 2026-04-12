// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
/*
const int N = 3001;
bitset <N> dp;
int n, S;

int main() {
  n = read(), S = read();
  for (rint i = 1; i <= n; i++) a[i] = read();
  for (rint i = 1; i <= n; i++) {
    dp.reset();
    dp.set(0);
    for (rint j = 1; j <= n; j++) {
      dp |= dp << a[j];
    }
  }
}
*/

const int N = 3001;
const ll mod = 998244353;
int dp[N][N][2];
int a[N], n, S;

int main() {
  scanf("%d%d", &n, &S);
  for (rint i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (rint i = 1; i <= n; i++) {
    dp[i][a[i]][1] = i;
  }
  for (rint i = 1; i <= n; i++) {
    for (rint j = S; j >= 0; j--) {
      dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
      if (j >= a[i]) dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - a[i]][0] + dp[i - 1][j - a[i]][1]) % mod;
      //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
    }
  }
  long long ans = 0ll;
  for (rint i = 1; i <= n; i++) {
    ans = (ans + 1ll * dp[i][S][1] * (n + 1 - i) % mod) % mod;
  }
  ans = (ans % mod + mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
