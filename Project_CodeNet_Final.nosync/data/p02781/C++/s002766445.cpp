#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string n;
  int k;
  std::cin >> n >> k;
  struct node {
    int s, r;
  };
  std::vector<node> dp(k + 1, {0, 0});
  dp[0].s = 1;
  for (const int d_ : n) {
    const int d = d_ - '0';
    std::vector<node> nx(k + 1, {0, 0});
    for (int i = 0; i != k + 1; i += 1) {
      for (int c = 0; c != 10; c += 1) {
        if (d < c)
          continue;
        const int ni = i + (c ? 1 : 0);
        if (ni > k)
          continue;
        (c == d ? nx[ni].s : nx[ni].r) += dp[i].s;
      }
      for (int c = 0; c != 10; c += 1) {
        const int ni = i + (c ? 1 : 0);
        if (ni > k)
          continue;
        nx[ni].r += dp[i].r;
      }
    }
    dp = std::move(nx);
  }
  std::cout << dp[k].s + dp[k].r << std::endl;
}