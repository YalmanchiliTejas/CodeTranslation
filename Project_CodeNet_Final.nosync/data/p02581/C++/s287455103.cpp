// #define NDEBUG

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt")
#endif

#include <bits/extc++.h>
#include <x86intrin.h>

#define ALL(c) begin(c), end(c)
#ifndef DUMP
#define DUMP(...) void(0)
#endif

using namespace std;

struct rep {
  struct iterator {
    int i;
    iterator& operator++() { return ++i, *this; }
    int operator*() const { return i; }
    friend bool operator!=(iterator a, iterator b) { return a.i != b.i; }
  };
  int l, r;
  rep(int _l, int _r) : l(min(_l, _r)), r(_r) {}
  rep(int n) : rep(0, n) {}
  iterator begin() const { return {l}; }
  iterator end() const { return {r}; }
};
struct per {
  struct iterator {
    int i;
    iterator& operator++() { return --i, *this; }
    int operator*() const { return i; }
    friend bool operator!=(iterator a, iterator b) { return a.i != b.i; }
  };
  int l, r;
  per(int _l, int _r) : l(min(_l, _r)), r(_r) {}
  per(int n) : per(0, n) {}
  iterator begin() const { return {r - 1}; }
  iterator end() const { return {l - 1}; }
};
auto sz = [](auto&& c) -> int { return size(forward<decltype(c)>(c)); };
auto chmin = [](auto&& a, auto b) { return b < a ? a = b, true : false; };
auto chmax = [](auto&& a, auto b) { return a < b ? a = b, true : false; };
template <class F>
struct y_combinator : F {
  y_combinator(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};
struct cint {
  using value_type = int;
  value_type v;
  cint() { cin >> v; }
  constexpr cint(value_type _v) : v(_v) {}
  cint operator++(int) { return v++; }
  cint operator--(int) { return v--; }
  cint& operator++() { return ++v, *this; }
  cint& operator--() { return --v, *this; }
  operator value_type() const { return v; }
  cint& operator*=(cint b) { return v *= b, *this; }
  cint& operator/=(cint b) { return v /= b, *this; }
  cint& operator%=(cint b) { return v %= b, *this; }
  cint& operator+=(cint b) { return v += b, *this; }
  cint& operator-=(cint b) { return v -= b, *this; }
  cint& operator<<=(int b) { return v <<= b, *this; }
  cint& operator>>=(int b) { return v >>= b, *this; }
  cint& operator&=(cint b) { return v &= b, *this; }
  cint& operator^=(cint b) { return v ^= b, *this; }
  cint& operator|=(cint b) { return v |= b, *this; }
};
constexpr cint inf = numeric_limits<cint::value_type>::max() / 2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  cint n;
  vector<cint> a(3 * n);
  for (auto&& e : a) --e;

  vector dp(n, vector(n, -inf));
  vector max_dp(n, -inf);
  cint offset = 0;

  vector<array<cint, 3>> v;
  auto lazy_update = [&](cint p, cint q, cint val) -> void {
    v.push_back({p, q, val});
  };
  auto push_all = [&]() -> void {
    while (sz(v)) {
      auto [p, q, val] = v.back();
      chmax(dp[p][q], val);
      chmax(dp[q][p], val);
      chmax(max_dp[p], val);
      chmax(max_dp[q], val);
      v.pop_back();
    }
  };

  lazy_update(a[0], a[1], 0);
  push_all();

  for (cint i : rep(n - 1)) {
    sort(begin(a) + (i * 3 + 2), begin(a) + (i * 3 + 5));
    cint x = a[i * 3 + 2];
    cint y = a[i * 3 + 3];
    cint z = a[i * 3 + 4];
    if (x == z) {
      ++offset;
      continue;
    }
    if (x == y) {
      for (cint p : rep(n)) lazy_update(z, p, dp[y][p] + 1);
    }
    if (y == z) {
      for (cint p : rep(n)) lazy_update(x, p, dp[y][p] + 1);
    }
    for (cint e : {x, y, z}) {
      for (cint p : rep(n)) lazy_update(e, p, max_dp[p]);
    }
    auto max_all = *max_element(ALL(max_dp));
    lazy_update(x, y, max_all);
    lazy_update(x, z, max_all);
    lazy_update(y, z, max_all);
    lazy_update(y, z, dp[x][x] + 1);
    lazy_update(x, z, dp[y][y] + 1);
    lazy_update(x, y, dp[z][z] + 1);
    push_all();
  }

  cint res = -inf;
  for (cint p : rep(n))
    for (cint q : rep(n))
      chmax(res, offset + dp[p][q] + (p == q and q == a.back()));
  cout << res << '\n';
}
