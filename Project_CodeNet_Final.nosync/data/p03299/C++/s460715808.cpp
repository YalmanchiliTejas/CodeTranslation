#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int add(int x, int y) {
  x += y;
  if (x >= md) x -= md;
  if (x < 0) x += md;
  return x;
}

inline int mul(int x, int y) {
  return 1ll * x * y % md;
}

inline int power(int x, int y) {
  int r = 1;
  while (y > 0) {
    if (y & 1) r = mul(r, x);
    x = mul(x, x);
    y >>= 1;
  }
  return r;
}

const int N = 105;

int dp[N][N];

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (a[j] > a[i]) continue;
      if (a[j] < a[i - 1]) {
        int bef = (a[i] < a[i - 1] ? i : i - 1);
        dp[i][j] = mul(add(dp[i - 1][j], dp[i - 1][bef]), power(2, a[i] - a[i - 1]));
      } else {
        dp[i][j] = mul(2 * dp[i - 1][i - 1], power(2, a[i] - a[j]));
      }
    }
  }
  cout << dp[n][0] << '\n';
}
