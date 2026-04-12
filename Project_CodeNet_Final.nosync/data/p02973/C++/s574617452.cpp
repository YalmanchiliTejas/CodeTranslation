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

int64_t solve(int64_t n, std::vector<int64_t> as) {
  std::multiset<int64_t> ss;
  ss.insert(as.back());
  for (int i = n - 2; i >= 0; --i) {
    auto const a = as[i];
    auto const back = *(ss.rbegin());
    if (a >= back) {
      ss.insert(a);
      continue;
    }
    auto const it = ss.lower_bound(a + 1);
    ss.erase(it);
    ss.insert(a);
  }
  return ss.size();
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
