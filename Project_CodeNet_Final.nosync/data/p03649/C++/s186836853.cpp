#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

static const long long mod = 1000000007;

struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

class modutils {
  vector<mint> fact, invfact;

 public:
  modutils(int n = 200005) : fact(n + 1), invfact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    invfact[n] = fact[n].inv();
    for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i;
  }
  mint pow(mint x, ll n) { return x.pow(n); }
  mint comb(ll n, ll k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * invfact[k] * invfact[n - k];
  }
  mint perm(ll n, ll k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * invfact[n - k];
  }
  mint fac(ll n) { return fact[n]; }
};

ll n;
ll sim(vll &as) {
  ll ret = 0;
  while (true) {
    bool term = true;
    rep(i, n) {
      if (as[i] >= n) {
        term = false;
        break;
      }
    }
    if (term) break;
    ll m = 0;
    ll midx = -1;
    rep(i, n) {
      if (m < as[i]) {
        midx = i;
        m = as[i];
      }
    }
    rep(i, n) {
      if (i == midx) {
        as[i] -= n;
      } else {
        as[i]++;
      }
    }
    ret++;
  }
  return ret;
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  cin >> n;
  vll as(n);
  ll sum = 0;
  ll M = 0;
  rep(i, n) {
    cin >> as[i];
    sum += as[i];
    chmax(M, as[i]);
  }

  if (sum <= n * n) {
    ll ans = sim(as);
    cout << ans << endl;
    return 0;
  }
  
  ll x = sum - n * n;

  ll l = 0, r = M;  // l: ng, r: ok
  ll sig = 0;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    sig = 0;
    rep(i, n) { sig += max((as[i] + x - m) / (n + 1), 0LL); }
    if (sig <= x) {
      r = m;
    } else {
      l = m;
    }
  }

  sig = 0;
  rep(i, n) { sig += max((as[i] + x - r) / (n + 1), 0LL); }  

  rep(i, n) {
    as[i] = as[i] + x - (n + 1) * max((as[i] + x - r) / (n + 1), 0LL);
  }

  rep(_, x - sig){
    ll M = 0, Midx;
    rep(i, n){
      if(M < as[i]) {
        Midx = i;
        M = as[i];
      }
    }
    as[Midx] -= n + 1;
  }

  ll ans = x + sim(as);
  cout << ans << endl;

  return 0;
}
