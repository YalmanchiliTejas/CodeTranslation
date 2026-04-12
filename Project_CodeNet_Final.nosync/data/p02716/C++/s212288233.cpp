#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<map<int, long long>> mp(n + 1);
  auto rec = [&](auto&& self, int i, int c) -> long long {
    if (c < 0 or c > (n - i + 1) / 2) {
      return -inf<long long>;
    }
    if (i == n) {
      return 0;
    }
    if (i == n - 1) {
      return c ? a.back() : 0;
    }
    if (mp[i].count(c)) {
      return mp[i][c];
    }
    return mp[i][c] = max(a[i] + self(self, i + 2, c - 1), self(self, i + 1, c));
  };
  cout << rec(rec, 0, n / 2) << '\n';
}
