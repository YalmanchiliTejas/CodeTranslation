#include <bits/stdc++.h>

using namespace std;

const int D = 105;
const int K = 10005;
const int MOD = 1e9 + 7;

char s[K];
int n, d, f[K][D];

inline int get (int x) {
  x %= d; if (x < 0) x += d; return x;
}

int main() {
  scanf("%s %d", s + 1, &d);
  n = strlen(s + 1), f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < d; ++j) {
      for (int k = 0; k < 10; ++k) {
        f[i][j] += f[i - 1][get(j - k)];
        if (f[i][j] >= MOD) f[i][j] -= MOD;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < 10; ++j) {
      ans += f[i - 1][get(-j)];
      if (ans >= MOD) ans -= MOD;
    }
  }
  int soFar = 0;
  for (int i = 1; i <= n; ++i) {
    int cur = s[i] - '0';
    for (int st = i == 1; st < cur; ++st) {
      ans += f[n - i][get(-soFar - st)];
      if (ans >= MOD) ans -= MOD;
    }
    soFar += cur, soFar %= d;
  }
  if (soFar == 0) ++ans, ans %= MOD;
  cout << ans << endl;
  return 0;
}

