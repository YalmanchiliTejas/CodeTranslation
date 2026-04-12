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
#define INF (ll)(1e17)

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

template <typename T>
class SegTree {
  int n;
  vector<T> data;
  T initial_value;
  function<T(T a, T b)> operation;
  function<T(T prev_val, T new_val)> _update;

  // [a,b)
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return initial_value;
    }

    if (a <= l && r <= b) {
      return data[k];
    } else {
      T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
      T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
      return operation(vl, vr);
    }
  }

 public:
  SegTree(size_t _n, T _initial_value, function<T(T a, T b)> _operation,
          function<T(T prev_val, T new_val)> update_function)
    : initial_value(_initial_value), operation(_operation), _update(update_function) {
    n = 1;
    while (n < _n) {
      n <<= 1;
    }
    data = vector<T>(2 * n - 1, initial_value);
  }

  // update i-th value (0-indexed)
  void update(int i, T x) {
    i += n - 1;
    data[i] = _update(data[i], x);
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // execute query of section [a, b)
  T query(int a, int b) {
    if (a >= b) {
      return 0;
    }
    return query(a, b, 0, 0, n);
  }

  // get i-th value
  T operator[](int i) {
    return data[i + n - 1];
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;

  vll a(n + 1);
  REP(i, n + 1) {
    cin >> a[i];
  }

  vvll dp(2, vll(n / 2 + 20, -INF));
  dp[0][0] = 0;
  dp[1][0] = 0;

  vll next = vll(n / 2 + 20, -INF);

  for (int i = 1; i <= n + 1; i++) {
    int prev_index = (i + 1) % 2;

    int l = max(0, i / 2 - 10);

    for (int j = l; j < i / 2 + 10; j++) {
      next[j] = dp[i % 2][j];
    }
    for (int j = l; j < i / 2 + 10; j++) {
      chmax(next[j + 1], dp[i % 2][j] + a[i]);
    }
    for (int j = l; j < i / 2 + 10; j++) {
      chmax(next[j], dp[prev_index][j]);
    }
    for (int j = l; j < i / 2 + 10; j++) {
      dp[i % 2][j] = next[j];
    }
  }
  cout << dp[n % 2][n / 2] << endl;

  return 0;
}
