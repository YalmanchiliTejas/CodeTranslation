#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 3010, P = 998244353;
int n, m, a[maxn], dp[2][maxn];

int main() {
  cin >> n >> m;
  rep(i, 1, n) a[i] = read();
  int sel = 1, res = 0;
  rep(i, 1, n) {
    memset(dp[sel], 0, sizeof dp[sel]);
    if (a[i] <= m) dp[sel][a[i]] = i;
    rep(j, 0, m) {
      dp[sel][j] = (dp[sel][j] + dp[sel ^ 1][j]) % P;
      if (j >= a[i]) dp[sel][j] = (dp[sel][j] + dp[sel ^ 1][j - a[i]]) % P;
    }
    if (a[i] <= m) {
      res = (res + 1ll * (n - i + 1) * (dp[sel ^ 1][m - a[i]] + (m == a[i]) * i)) % P;
    }
    sel ^= 1;
  }
  cout << res;
  return 0;
}