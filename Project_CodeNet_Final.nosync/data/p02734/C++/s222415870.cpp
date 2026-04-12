#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
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

template <std::uint_fast64_t Modulus>
class modint {
  using u64 = std::uint_fast64_t;

 public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept
      : a(x % Modulus) {
  }
  constexpr u64 &value() noexcept {
    return a;
  }
  constexpr const u64 &value() const noexcept {
    return a;
  }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(const modint rhs) noexcept {
    return *this *= ~rhs;
  }
  constexpr modint power(u64 exp) const noexcept {
    modint v = 1, x = *this;
    while (exp) {
      if (exp & 1) {
        v *= x;
      }
      x *= x;
      exp >>= 1;
    }
    return v;
  }
  constexpr modint operator~() const noexcept {
    return power(Modulus - 2);
  }
};

using mint = modint<998244353>;

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N, S;
  while (cin >> N >> S) {
    vector<int> A(N);
    for (auto& x : A) cin >> x;
    vector<mint> dp(S + 1, 0);
    mint res = 0;
    for (int i = 0; i < N; i++) {
      int x = A[i];
      if (S - x > 0) {
        res += dp[S - x] * (N - i);
      }
      for (int s = S; s >= x; s--) {
        dp[s] += dp[s - x];
      }
      if (x == S) {
        res += mint(i + 1) * mint(N - i);
      } else if (x < S) {
        dp[x] += i + 1;
      }
    }
    cout << res.value() << endl;
  }
  return 0;
}
