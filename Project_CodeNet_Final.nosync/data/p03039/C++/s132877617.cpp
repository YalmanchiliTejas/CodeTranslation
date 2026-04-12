#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 60;

struct mint {
  ll x;
  mint(ll x = 0) : x(x % MOD) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

class combination {
 private:
  vector<mint> fact, finv;

 public:
  combination(int N) {
    fact = finv = vector<mint>(N + 1);
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    for (ll i = 2; i <= N; i++) {
      fact[i] = fact[i - 1] * i;
      finv[i] = fact[i].inv();
    }
  }
  mint f(int i) { return fact[i]; }
  mint comb(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * finv[k] * finv[n - k];
  }
  mint hcomb(int n, int k) {
    if (n == 0 && k == 0) return 1;
    return comb(n + k - 1, k);
  }
};

int main() {
  //
  ll n, m, k;
  cin >> n >> m >> k;
  mint ans(0);
  combination comb(n * m);
  REP(d, 1, n) {
    mint tmp(1);
    tmp *= d;
    tmp *= (n - d);
    tmp *= (m * m);
    tmp *= comb.comb(n * m - 2, k - 2);
    ans += tmp;
  }
  REP(d, 1, m) {
    mint tmp(1);
    tmp *= d;
    tmp *= (m - d);
    tmp *= (n * n);
    tmp *= comb.comb(n * m - 2, k - 2);
    ans += tmp;
  }
  cout << ans.x << endl;
  return 0;
}
