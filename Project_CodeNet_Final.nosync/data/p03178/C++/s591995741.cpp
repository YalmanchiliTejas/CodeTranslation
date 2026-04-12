// 2020-07-03 22:37:30
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

void answer() {
  string k;
  int d;
  cin >> k >> d;
  vector<vector<mint> > dp(2, vector<mint>(d, 0));
  dp[0][0] = 1;
  rep(i, k.size()) {
    vector<vector<mint> > p(2, vector<mint>(d, 0));
    swap(p, dp);
    int c = k[i] - '0';
    rep(smaller, 2) rep(x, d) rep(j, 10) {
      if(!smaller && j > c) continue;
      dp[smaller || j < c][(x + j) % d] += p[smaller][x];
    }
  }
  cout << dp[0][0] + dp[1][0] - 1 << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}