#include <bits/stdc++.h>
using std::cerr;
using std::endl;

const int N = 3005;
int n, P, ans, C[N][N], S[N][N];

inline int fpow(int x, int y, int mod) {
  int ret = 1;
  for ( ; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) ret = 1ll * ret * x % mod;
  return ret;
}

int main() {
  std::cin >> n >> P;
  S[0][0] = C[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
      S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % P;
    }
  }
  for (int i = 0; i <= n; ++i) {
    int sum = 0, pow = fpow(2, n - i, P);
    for (int j = 0, val = 1; j <= i; ++j) {
      sum = (sum + 1ll * S[i + 1][j + 1] * val) % P;
      val = 1ll * val * pow % P;
    }
    sum = 1ll * sum * fpow(2, fpow(2, n - i, P - 1), P) % P
      * C[n][i] % P * (i & 1 ? P - 1 : 1) % P;
    ans = (ans + sum) % P;
  }
  std::cout << ans << std::endl;
  return 0;
}