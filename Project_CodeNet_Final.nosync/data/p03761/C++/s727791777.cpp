#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n;
  cin >> n;

  constexpr auto K = 'z' - 'a' + 1L;

  array<int64_t, K> a{};
  for (auto i : irange(0L, n)) {
    string s;
    cin >> s;

    array<int64_t, K> t{};
    for (auto c : s) {
      ++t[c - 'a'];
    }
    for (auto j : irange(0L, K)) {
      if (i == 0 || t[j] < a[j]) {
        a[j] = t[j];
      }
    }
  }

  for (auto i : irange(0L, K)) {
    for (auto j : irange(0L, a[i])) {
      cout << char('a' + i);
    }
  }
  cout << endl;
}