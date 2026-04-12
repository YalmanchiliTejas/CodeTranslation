#include <iostream>
#include <cstring>

const int MAX_N = 3000;
long long f[MAX_N + 1][MAX_N + 1][2];
int a[MAX_N + 1];

long long dp(int l, int r, int d) {
  auto &ret = f[l][r][d];
  if (ret != -4485090715960753727ll) return ret;
  if (l == r) return ret = d ? a[l] : -a[l];
  if (d == 0) {
    ret = std::min(dp(l + 1, r, !d) - a[l], dp(l, r - 1, !d) - a[r]);
  } else {
    ret = std::max(dp(l + 1, r, !d) + a[l], dp(l, r - 1, !d) + a[r]);
  }
  return ret;
}

int main() {
  memset(f, -0x3f, sizeof(f));
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::cout << dp(1, n, 1);
  return 0;
}