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
const long long INF = 1LL << 60;

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

template <typename T>
class Combination {
 public:
  Combination(ll _max_n) : max_n(_max_n), factional(max_n + 1), inv(max_n + 1) {
    factional[0] = 1;
    inv[0] = 1;
    for (ll i = 0; i < max_n; i++) {
      factional[i + 1] = factional[i] * (i + 1); // n!(mod M)
      inv[i + 1] = inv[i] / (i + 1);             // k!^(M-2) (mod M)
    }
  }

  // nCk
  T choose(ll n, ll k) {
    if (n == 0 && k == 0)
      return 1;
    if (n < k || n < 0)
      return 0;
    T tmp = inv[n - k] * inv[k];
    return tmp * factional[n];
  }

  T permutation(ll n, ll k) {
    if (n - k < 0) {
      return 0;
    }
    return factional[n] / factional[n - k];
  }

 private:
  const ll max_n;
  std::vector<T> factional;
  std::vector<T> inv;
};

using Comb = Combination<mint>;

ll n;
string s;
string ans;

bool check(int idx) {
  if (ans[idx] == 'S') {
    if (ans[(idx + n - 1) % n] == ans[(idx + 1) % n]) {
      return (s[idx] == 'o' ? true : false);
    } else {
      return (s[idx] == 'x' ? true : false);
    }
  } else {
    if (ans[(idx + n - 1) % n] == ans[(idx + 1) % n]) {
      return (s[idx] == 'o' ? false : true);
    } else {
      return (s[idx] == 'x' ? false : true);
    }
  }
}

int dfs(int idx) {
  if (idx == n) {
    if (check(0) && check(n - 1)) {
      return 0;
    }
    return -1;
  }
  ans[idx] = 'S';
  if (check(idx - 1)) {
    if (dfs(idx + 1) == 0) {
      return 0;
    }
  }

  ans[idx] = 'W';
  if (check(idx - 1)) {
    if (dfs(idx + 1) == 0) {
      return 0;
    }
  }
  return -1;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  cin >> n >> s;
  ans.resize(n);

  ans[0] = 'S';
  ans[1] = 'S';
  if (dfs(2) == 0) {
    cout << ans << endl;
    return 0;
  }

  ans[0] = 'S';
  ans[1] = 'W';
  if (dfs(2) == 0) {
    cout << ans << endl;
    return 0;
  }

  ans[0] = 'W';
  ans[1] = 'S';
  if (dfs(2) == 0) {
    cout << ans << endl;
    return 0;
  }

  ans[0] = 'W';
  ans[1] = 'W';
  if (dfs(2) == 0) {
    cout << ans << endl;
    return 0;
  }

  cout << -1 << endl;

  return 0;
}
