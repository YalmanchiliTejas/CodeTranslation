#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

template<uint32_t mod> class modulo_int {
  class dummy_type { };

  modulo_int &normalize2() {
    if (value >= mod) value -= mod;
    return *this;
  }

  modulo_int(const uint32_t value, const dummy_type &) : value(value) {}

public:
  explicit modulo_int(const int64_t value = 0) : value(value % mod + mod) { normalize2(); }

  uint32_t get() const { return value; }

  modulo_int operator+() const {
    return *this;
  }
  modulo_int operator-() const {
    return modulo_int(mod - this->value, {}).normalize2();
  }
  modulo_int operator+(const modulo_int &that) const {
    return modulo_int(this->value + that.value, {}).normalize2();
  }
  modulo_int operator-(const modulo_int &that) const {
    return modulo_int(this->value + (mod - that.value), {}).normalize2();
  }
  modulo_int operator*(const modulo_int &that) const {
    return modulo_int(((uint64_t)(this->value) * that.value) % mod, {});
  }
  // mod should be prime
  modulo_int operator/(const modulo_int &that) const {
    return *this * that.inv();
  }
  friend modulo_int pow(const modulo_int base, uint64_t e) {
    if (e == 0) return modulo_int(1, {});
    if (e == 1) return base;
    auto tmp = pow(base * base, e / 2);
    return (e&1) ? tmp * base : tmp;
  }

  modulo_int &operator+=(const modulo_int &that) { return *this = *this + that; }
  modulo_int &operator-=(const modulo_int &that) { return *this = *this - that; }
  modulo_int &operator*=(const modulo_int &that) { return *this = *this * that; }
  modulo_int &operator/=(const modulo_int &that) { return *this = *this / that; }

  modulo_int inv() const {
    pow(*this, mod - 2);
  }

private:
  uint32_t value;
};

using mod_t = modulo_int<1000000007>;

// pair(stripe case, non-stripe case)
pair<mod_t, mod_t> solve_rec(
    const vector<int> &h,
    const int l,
    const int r,
    const int current_h
)
{
  assert(r > l);
  const int new_h = *min_element(begin(h) + l, begin(h) + r);
  assert(new_h > current_h);
  if (new_h == *max_element(begin(h) + l, begin(h) + r)) {
    mod_t stripe_res = pow(mod_t(2), h[l] - current_h);
    mod_t nonstripe_res = pow(mod_t(2), r - l) - mod_t(2);    // -2 for stripe
    return make_pair(stripe_res, nonstripe_res);
  }
  vector<int> ls, rs;
  for (int i = l; i < r; ++i) {
    if (new_h == h[i]) continue;
    if (rs.empty() || rs.back() != i) {
      ls.push_back(i);
      rs.push_back(i+1);
    } else {
      ++rs.back();
    }
  }
  assert(ls.size() == rs.size());
  assert(!ls.empty());

  mod_t nonstripe_res(1);
  mod_t stripe_res(1);
  const int t = ls.size();
  vector<mod_t> stripe, nonstripe;
  for (int i = 0; i < t; ++i) {
    mod_t stripe, nonstripe;
    tie(stripe, nonstripe) = solve_rec(h, ls[i], rs[i], new_h);
    nonstripe_res *= nonstripe + (stripe * mod_t(2));
    stripe_res *= stripe;
  }
  for (int i = l; i < r; ++i) if (h[i] == new_h) nonstripe_res *= mod_t(2);
  nonstripe_res -= stripe_res * mod_t(2);
  stripe_res *= pow(mod_t(2), new_h - current_h);
  return make_pair(stripe_res, nonstripe_res);
}


int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &x : h) cin >> x;
  if (n == 1) {
    cout << pow(mod_t(2), h[0]).get() << endl;
    return 0;
  }
  mod_t precompute(1);
  for (int i = 0; i < n; ++i) {
    const int adj = max(i == 0 ? 0 : h[i-1], i == n-1 ? 0 : h[i+1]);
    if (adj < h[i]) {
      precompute *= pow(mod_t(2), h[i] - adj);
      h[i] = adj;
    }
  }
  mod_t stripe, nonstripe;
  tie(stripe, nonstripe) = solve_rec(h, 0, n, 0);

  cout << (precompute * (stripe + nonstripe)).get() << endl;
  return 0;
}
