// 2020-07-15 22:30:11
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
struct mint {
  ll divisor = 1000000007;
  ll val;
  constexpr mint(ll v = 0) noexcept : val(v % divisor) {
    if (val < 0) val += divisor;
  }
  constexpr mint operator + (const mint& rhs) const noexcept {
    return mint(*this) += rhs;
  }
  constexpr mint operator - (const mint& rhs) const noexcept {
    return mint(*this) -= rhs;
  }
  constexpr mint operator * (const mint& rhs) const noexcept {
    return mint(*this) *= rhs;
  }
  constexpr mint operator / (const mint& rhs) const noexcept {
    return mint(*this) /= rhs;
  }
  constexpr mint operator ~ () const noexcept {
    ll a = this->val, b = divisor, u = 1, v = 0;
    while (b > 0) {
      ll t = a / b;
      a -= t * b;
      u -= t * v;
      ll c = a; a = b; b = c;
      ll w = u; u = v; v = w;
    }
    if (u < 0) u += divisor;
    u %= divisor;
    return u;
  }
  constexpr mint& operator += (const mint& rhs) noexcept {
    val += rhs.val;
    if (val >= divisor) val -= divisor;
    return *this;
  }
  constexpr mint& operator -= (const mint& rhs) noexcept {
    if (val < rhs.val) val += divisor;
    val -= rhs.val;
    return *this;
  }
  constexpr mint& operator *= (const mint& rhs) noexcept {
    val = val * rhs.val % divisor;
    return *this;
  }
  constexpr mint& operator /= (const mint& rhs) noexcept {
    val = val * (~(mint(rhs))).val % divisor;
    return *this;
  }
  friend mint modpow (mint a, ll n) noexcept {
    auto res = mint(1);
    while(n > 0) {
      if(n&1) res *= a;
      a *= a;
      n >>= 1;
    }
    return res;
  }
  friend std::ostream& operator << (std::ostream& os, const mint& a) noexcept {
    return os << a.val;
  }
  friend std::string debug_s (mint a) noexcept {
    return std::to_string(a.val);
  }
};
namespace combinatorics {
  const int limit = 2000020;
  const int mod = 1000000007;
  bool initialized = false;
  long long fac_table[limit], inv_table[limit], finv_table[limit];
  void initialize() {
    fac_table[0] = fac_table[1] = 1;
    inv_table[1] = 1;
    finv_table[0] = finv_table[1] = 1;
    for (int i = 2; i < limit; i++) {
      fac_table[i] = fac_table[i - 1] * i % mod;
      inv_table[i] = mod - inv_table[mod % i] * (mod / i) % mod;
      finv_table[i] = finv_table[i - 1] * inv_table[i] % mod;
    }
    initialized = true;
  }
  long long com(int n, int k) {
    if (!initialized) initialize();
    if (n < k || n < 0 || k < 0) return 0;
    else return fac_table[n] * (finv_table[k] * finv_table[n - k] % mod) % mod;
  }
  long long perm(int n, int k) {
    if (!initialized) initialize();
    if (n < k || n < 0 || k < 0) return 0;
    else return fac_table[n] * finv_table[n - k] % mod;
  }
}
using combinatorics::com;
using combinatorics::perm;

void answer() {
  ll n, m, k;
  cin >> n >> m >> k;
  mint ans = 0, cur = 0;
  rep(i, m) {
    cur += mint(m-i-1) * (m-i) / 2;
  }
  ans += cur * n * n;
  cur = 0;
  rep(i, n) {
    cur += mint(n-i-1) * (n-i) / 2;
  }
  ans += cur * m * m;
  ans *= mint(com(n*m-2, k-2));
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}