#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using i64 = int64_t;
#define rep(i, s, n) for (i64 i = (s); i < (n); ++i)

constexpr i64 kModulo{1000000007};

int main() {
  cin.tie(nullptr);

  i64 n;
  cin >> n;
  vector<i64> xs(n);
  for (i64 i = 0; i < n; ++i) {
    cin >> xs[i];
  }
  i64 cum{0};
  for (i64 i = 0; i < n; ++i) {
    cum += xs[i];
  }
  cum %= kModulo;
  i64 ret{0};
  rep(i, 0, size(xs) - 1) {
    cum -= xs[i];
    if (cum < 0) {
      cum = kModulo + cum;
    }
    ret += (xs[i] * cum) % kModulo;
  }
  cout << (ret % kModulo) << endl;

  return 0;
}
