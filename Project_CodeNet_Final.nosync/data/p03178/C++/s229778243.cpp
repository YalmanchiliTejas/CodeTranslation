#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

// #define mod (ll)(1e9 + 7)

template <ll ModVal>
struct ModInt {
  ll x;

  ModInt(ll _x = 0) : x((_x % ModVal + ModVal) % ModVal) {
  }

  ModInt operator-() const {
    return ModInt(-x);
  }
  ModInt& operator+=(const ModInt a) {
    x += a.x;
    if (x >= ModVal)
      x -= ModVal;
    return *this;
  }
  ModInt& operator-=(const ModInt a) {
    x = x + ModVal - a.x;
    if (x >= ModVal)
      x -= ModVal;
    return *this;
  }
  ModInt& operator*=(const ModInt a) {
    x *= a.x;
    x %= ModVal;
    return *this;
  }

  ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    ll tmp = a / b;
    ll d = ext_gcd(b, a - b * tmp, y, x);
    y -= tmp * x;
    return d;
  }

  // 逆元
  ModInt inv() {
    ll u, v;
    ext_gcd(x, ModVal, u, v);
    return ModInt(u);
  }

  ModInt inv(const ModInt a) {
    ll u, v;
    ext_gcd(a.x, ModVal, u, v);
    return ModInt(u);
  }

  ModInt& operator/=(const ModInt a) {
    return (*this) *= inv(a);
  }

  ModInt operator+(const ModInt a) const {
    ModInt retval(*this);
    return retval += a;
  }
  ModInt operator-(const ModInt a) const {
    ModInt retval(*this);
    return retval -= a;
  }
  ModInt operator*(const ModInt a) const {
    ModInt retval(*this);
    return retval *= a;
  }
  ModInt operator/(const ModInt a) const {
    ModInt retval(*this);
    return retval /= a;
  }

  ModInt pow(ll n) {
    ModInt ans(1);
    while (n) {
      if (n & 1)
        ans = ans * x;
      *this = (*this) * (*this);
      n = n >> 1;
    }
    return ans;
  }

  constexpr const ll& value() {
    return this->x;
  }
};

template <ll ModVal>
ostream& operator<<(ostream& os, const ModInt<ModVal>& a) {
  os << a.x;
  return os;
}

using mint = ModInt<mod>;

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  string s;
  cin >> s;

  ll d;
  cin >> d;

  ll n = s.size();
  vvvm dp(n + 1, vvm(d, vm(2)));
  dp[0][0][0] = 1;

  rep(i, n) {
    ll v = s[i] - '0';
    rep(j, d) {
      rep(k, 10) {
        dp[i + 1][(j + k) % d][1] += dp[i][j][1];
        if (k < v) {
          dp[i + 1][(j + k) % d][1] += dp[i][j][0];
        } else if (k == v) {
          dp[i + 1][(j + k) % d][0] += dp[i][j][0];
        }
      }
    }
  }

  mint ans = dp[n][0][0] + dp[n][0][1] - 1;

  cout << ans << endl;

  return 0;
}
