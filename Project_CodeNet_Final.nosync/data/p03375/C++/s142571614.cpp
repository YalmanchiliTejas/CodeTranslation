#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, p;
  std::cin >> n >> p;
  std::vector<int> pwr(n + 1);
  std::vector<std::vector<int>> c(n + 1), s(n + 1); 
  for (int i = 0; i <= n; ++i) {
    c[i].resize(i + 1);
    c[i][0] = c[i][i] = 1;
    s[i].resize(i + 1);
    s[i][0] = s[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
      s[i][j] = (s[i - 1][j - 1] + 1ll * s[i - 1][j] * (j + 1)) % p; 
    }
  }
  pwr[0] = 1;
  for (int i = 1; i <= n; ++i)
    pwr[i] = 1ll * pwr[i - 1] * 2 % (p - 1);
  auto power = [&](int a, int b) {
    int res = 1;
    while (b) {
      if (b & 1)
        res = 1ll * res * a % p;
      a = 1ll * a * a % p;
      b >>= 1; 
    }
    return res;
  };
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    int res = 0;
    int par = power(2, n - i), cur = 1;
    for (int j = 0; j <= i; ++j) {
      res = (res + 1ll * s[i][j] * cur) % p;
      cur = 1ll * cur * par % p;
    }
    res = 1ll * res * power(2, pwr[n - i]) % p * c[n][i] % p;
    if (i & 1) 
      ans = (ans - res + p) % p;
    else
      ans = (ans + res) % p;
  }
  std::cout << ans << "\n";
  return 0;
}