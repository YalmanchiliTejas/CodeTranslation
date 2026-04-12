#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <bitset>
#include <cmath>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 const ll mod =  998244353 ;
//const ll mod = 1000000007;
const ll inf = 1e18;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define REP_REV(i, n) for (ll i = n-1; i >= 0; --i)
#define REP_FROM_REV(i, j, n) for (ll i = n-1; i >= j; --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) ll(x.size())

template<typename T>
inline T chmax(T &a, const T b) { return a = (a < b) ? b : a; }

template<typename T>
inline T chmin(T &a, const T b) { return a = (a > b) ? b : a; }

ll power(ll base, ll exponent) {
  if (exponent % 2) {
    return power(base, exponent - 1) * base % mod;
  } else if (exponent) {
    ll root_ans = power(base, exponent / 2);
    return root_ans * root_ans % mod;
  } else { return 1; }
}

ll inverse(ll x) { return power(x, mod - 2); }

ll gcd(ll a, ll b) {
  if (a < b) gcd(b, a);
  ll r;
  while (r = a % b) {
    a = b;
    b = r;
  }
  return b;
}

template<typename T>
ll sum(T begin, T end) { return accumulate(begin, end, 0ll); }

struct combination {
    vector<ll> fact, inv;

    combination(int sz) : fact(sz + 1), inv(sz + 1) {
      fact[0] = 1;
      for (int i = 1; i <= sz; i++) { fact[i] = fact[i - 1] * i % mod; }
      inv[sz] = power(fact[sz], mod - 2);
      for (int i = sz - 1; i >= 0; i--) { inv[i] = inv[i + 1] * (i + 1) % mod; }
    }

    ll C(int p, int q) const {
      if (q < 0 || p < q) return 0;
      return (fact[p] * inv[q] % mod * inv[p - q] % mod);
    }
};

using Pair = pair<ll, ll>;

template<ll Modulus>
struct ModInt {
    ll a;

    constexpr ModInt(const ll x = 0) noexcept: a((x % mod + mod) % mod) {}

    constexpr ll &value() noexcept { return a; }

    constexpr const ll &value() const noexcept { return a; }

    constexpr ModInt operator+(const ModInt x) const noexcept {
      return ModInt(*this) += x;
    }

    constexpr ModInt operator-(const ModInt x) const noexcept {
      return ModInt(*this) -= x;
    }

    constexpr ModInt operator*(const ModInt x) const noexcept {
      return ModInt(*this) *= x;
    }

    constexpr ModInt operator/(const ModInt x) const noexcept {
      return ModInt(*this) /= x;
    }

    constexpr ModInt &operator+=(const ModInt x) noexcept {
      a += x.a;
      if (a >= Modulus) {
        a -= Modulus;
      }
      return *this;
    }

    constexpr ModInt &operator-=(const ModInt x) noexcept {
      if (a < x.a) {
        a += Modulus;
      }
      a -= x.a;
      return *this;
    }

    constexpr ModInt &operator*=(const ModInt x) noexcept {
      a = a * x.a % Modulus;
      return *this;
    }

    constexpr ModInt &operator/=(ModInt x) noexcept {
      ll exp = Modulus - 2;
      while (exp) {
        if (exp % 2) {
          *this *= x;
        }
        x *= x;
        exp /= 2;
      }
      return *this;
    }

    constexpr ModInt operator-() noexcept {
      return ModInt(-a);
    }

    friend ostream &operator<<(ostream &os, const ModInt &m) {
      os << m.a;
      return os;
    }
};

using mint = ModInt<mod>;
template<typename T> struct BIT {
    vector<T> bit;
    int n;

    BIT(const int size) : bit(size+1), n(size) {}

    void add(int index, T value) noexcept {
      index++;  // to 1-indexed
      for (int x = index; x <= n; x += x & -x) bit[x] += value;
    }

    constexpr T sum(int lft, int rgt) noexcept {
      return sum(rgt) - sum(lft);
    }

    constexpr T sum(int rgt) noexcept {
      //rgt++;rgt--;// to 1-indexed and open section
      T ret = 0;
      for (int x = rgt; x > 0; x -= x & -x) ret += bit[x];
      return ret;
    }
};


signed main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  vector<vector<mint>> dp(n+1, vector<mint>(s+3001));
  dp[0][0] = 1;
  REP(i, n) {
    REP(j, s+1){
      dp[i+1][j] = dp[i][j];
    }
    REP(j, s) {
      dp[i+1][j+a[i]] += dp[i][j];
    }
    dp[i+1][a[i]] += i;
  }
  mint ans = 0;
  REP(i, n) ans += dp[i+1][s];
  cout << ans << endl;
  return 0;
}
