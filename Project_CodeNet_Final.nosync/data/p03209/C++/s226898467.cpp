#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

int main() {
  int N;
  ll X;
  while (cin >> N >> X) {
    vector<ll> tot(N + 1), len(N + 1);
    tot[0] = len[0] = 1;
    for (int i = 1; i <= N; i++) {
      tot[i] = 2 * tot[i - 1] + 1;
      len[i] = 2 * len[i - 1] + 3;
    }
    function<ll(int, ll)> func = [&](int N, ll X) {
      if (N == 0) return X;
      if (X == 1) return 0ll;
      if (X == len[N]) return tot[N];
      if (X > len[N - 1] + 2) {
        return tot[N - 1] + 1 + func(N - 1, X - len[N - 1] - 2);
      }
      if (X == len[N - 1] + 2) {
        return tot[N - 1] + 1;
      }
      return func(N - 1, X - 1);
    };
    cout << func(N, X) << endl;
  }
  return 0;
}
