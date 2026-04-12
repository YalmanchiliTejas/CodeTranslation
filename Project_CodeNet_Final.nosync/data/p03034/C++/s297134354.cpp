#include <algorithm>
#include <bitset>
#include <cassert>
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
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

bool safe(int N, int C, int k) {
  // A + Ck = N - 1
  int A = N - 1 - C * k;
  if (A <= 0) return false;
  // C = A - B
  int B = A - C;
  if (B <= 0 || B > A) return false;
  if (A % C != 0) return true;
  return (A / C) > k;
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N;
  while (cin >> N) {
    vector<ll> S(N);
    for (ll& x : S) cin >> x;
    ll res = 0;
    for (int C = 1; C < N; C++) {
      ll sum = 0;
      for (int k = 1; k * C < N; k++) {
        sum += S[k * C] + S[N - 1 - k * C];
        if (safe(N, C, k)) {
          chmax(res, sum);
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
