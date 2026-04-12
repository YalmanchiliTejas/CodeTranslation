// 2020-08-29 21:05:30
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
const int mod = 1000000007;
struct mint {
  ll val;
  constexpr mint(ll v = 0) noexcept : val(v % mod) {
    if (val < 0) val += mod;
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
    ll a = this->val, b = mod, u = 1, v = 0;
    while (b > 0) {
      ll t = a / b;
      a -= t * b;
      u -= t * v;
      ll c = a; a = b; b = c;
      ll w = u; u = v; v = w;
    }
    if (u < 0) u += mod;
    u %= mod;
    return u;
  }
  constexpr mint& operator += (const mint& rhs) noexcept {
    val += rhs.val;
    if (val >= mod) val -= mod;
    return *this;
  }
  constexpr mint& operator -= (const mint& rhs) noexcept {
    if (val < rhs.val) val += mod;
    val -= rhs.val;
    return *this;
  }
  constexpr mint& operator *= (const mint& rhs) noexcept {
    val = val * rhs.val % mod;
    return *this;
  }
  constexpr mint& operator /= (const mint& rhs) noexcept {
    val = val * (~(mint(rhs))).val % mod;
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

// clang-format on
void answer() {
  int n;
  cin >> n;
  vector<ll> a(n), sum(n);
  rep(i, n) {
    cin >> a[i];
    sum[i] = a[i];
    if (i) sum[i] += sum[i - 1];
  }
  mint ans = 0;
  REP(i, 1, n) { ans += mint(a[i]) * sum[i - 1]; }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}