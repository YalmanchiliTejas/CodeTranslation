#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl;

constexpr long long mod = 1'000'000'007;

auto main (void) -> int {
  int n;
  cin >> n;

  std::vector<int> a (n);
  for (auto i = 0; i < n; i++) cin >> a[i];

  auto tmp_0 = 0LL;
  auto tmp_1 = 0LL;

  for (auto i : a) {
    auto c = static_cast<long long> (i);
    tmp_0 += c;
    tmp_1 += c * c;
    if (tmp_0 > mod) tmp_0 %= mod;
    if (tmp_1 > mod) tmp_1 %= mod;
  }
  tmp_0 = (tmp_0 * tmp_0) % mod;

  auto b = tmp_0 < tmp_1 ? tmp_0 - tmp_1 + mod : tmp_0 - tmp_1;

  // mod が奇数なので b が奇数だったり偶数だったりして / 2 で引っかかる
  // この時点でまあ mod 以下
  cout << (b + (b % 2) * mod) / 2 << endl;

  return 0;
}
