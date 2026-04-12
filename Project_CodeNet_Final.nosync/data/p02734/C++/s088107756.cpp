#include <iostream>
#include <cstring>

const int MAXN = 3002;
const int P = 998244353;

int a[MAXN];
int64_t f[MAXN][MAXN];

int64_t solve(int n, int sum) {
  memset(f, 0, sizeof(f));
  int64_t ans = 0;
  for (int i = n; i > 0; --i) {
    if (sum > a[i]) ans += i * f[i + 1][sum - a[i]];
    else if (sum == a[i]) ans += i * (n + 1 - i);
    if (ans >= P) ans %= P;

    for (int j = 1; j <= sum; ++j) {
      f[i][j] = f[i + 1][j];
      if (j >= a[i]) f[i][j] += f[i + 1][j - a[i]];
      if (f[i][j] >= P) f[i][j] %= P;
    }
    f[i][a[i]] += n + 1 - i;
  }
  return ans;
}

int main() {
  int n, sum;
  std::cin >> n >> sum;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::cout << solve(n, sum) << std::endl;
  return 0;
}
