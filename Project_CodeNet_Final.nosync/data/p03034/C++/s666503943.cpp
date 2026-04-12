#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>

template<class T>
void chmax(T &l, const T &r) {
  l = std::max(l, r);
}

int main() {
  using i64 = std::int_fast64_t;

  int n;
  std::cin >> n;
  std::vector<i64> s(n);
  for (auto &e : s) std::cin >> e;
  n -= 1;

  i64 ans = 0;
  
  for (int d = 1; d != n; d += 1) {
    i64 pre = 0;
    i64 suf = 0;
    for (int i = 0;; i += 1) {
      if (i * d > n || n - i * d <= d) break;
      if (n % d == 0 && i * d >= n - i * d) break;
      pre += s[i * d];
      suf += s[n - i * d];
      chmax(ans, pre + suf);
    }
  }

  std::cout << ans << "\n";
}
