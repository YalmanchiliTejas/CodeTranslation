#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) void(0)
#endif

using namespace std;

template <class T, class Op = multiplies<>>
constexpr T power(T a, uint64_t n, T init = 1, Op op = Op{}) {
  while (n) {
    if (n & 1) init = op(init, a);
    if (n >>= 1) a = op(a, a);
  }
  return init;
}

template <uint32_t Mod>
struct modular {
  using T = modular;
  static constexpr uint32_t mod = Mod;
  uint32_t v;
  modular(int64_t x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  T operator-() const { return T() - *this; }
  T& operator+=(T b) { return v += int(v += b.v - mod) < 0 ? mod : 0, *this; }
  T& operator-=(T b) { return v += int(v -= b.v) < 0 ? mod : 0, *this; }
  T& operator*=(T b) { return v = uint64_t(v) * b.v % mod, *this; }
  T& operator/=(T b) { return *this *= power(b, mod - 2); }
  friend T operator+(T a, T b) { return a += b; }
  friend T operator-(T a, T b) { return a -= b; }
  friend T operator*(T a, T b) { return a *= b; }
  friend T operator/(T a, T b) { return a /= b; }
  friend bool operator==(T a, T b) { return a.v == b.v; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  using mint = modular<power(10, 9) + 7>;
  int n;
  cin >> n;
  mint res, sum;
  while (n--) {
    int a;
    cin >> a;
    res += sum * a;
    sum += a;
  }
  cout << res.v << '\n';
}
