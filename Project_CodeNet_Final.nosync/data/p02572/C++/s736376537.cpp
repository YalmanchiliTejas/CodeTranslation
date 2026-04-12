#define errOut(s) \
  { std::cerr << __LINE__ << ":" << #s << ":" << (s) << std::endl; }

#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
//#include <boost/multi_array.hpp>
//#include <boost/optional.hpp>
//#include <boost/range/adaptors.hpp>
//#include <boost/range/algorithm.hpp>
//#include <boost/range/irange.hpp>
#pragma clang diagnostic pop

using namespace std;

static constexpr int64_t MOD = 1000000007;

int64_t solve(int64_t  /*n*/, std::vector<int64_t> as) {
  int64_t s = 0;
  for (auto const a : as) {
    s += a;
    s %= MOD;
  }

  int64_t ret = 0;
  for (auto const a : as) {
    s += MOD;
    s -= a;
    s %= MOD;
    auto as = a * s;
    as %= MOD;
    ret += as;
    ret %= MOD;
  }
  return ret;
}

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> as(n);
  for (int i = 0; i < n; i++) {
    std::cin >> as[i];
  }
  auto const res = solve(n, std::move(as));
  std::cout << res << std::endl;
  return 0;
}
