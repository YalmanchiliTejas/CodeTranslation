#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << "\n"
#define COUTF(x) cout << setprecision(15) << (x) << "\n"
#define ENDL cout << "\n"
#define DF(x) x.erase(x.begin())
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll) x.size()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#define ANS cout << ans << "\n"
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define LINE cerr << "[debug] line: " << __LINE__ << "\n";
#define debug(x) cerr << "[debug] " << #x << ": " << x << "\n";
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(i, v.size()) cerr << " " << v[i]; \
  cerr << "\n";
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using mll = map<ll, ll>;
using qll = queue<ll>;
using P = pair<ll, ll>;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ld PI = 3.141592653589793238462643383279;
ll get_digit(ll x) {
  return to_string(x).size();
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

vector<P> factorize(ll n) {
  vector<P> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        result.back().second++;
      }
    }
  }
  if (n != 1) {
    result.pb({n, 1});
  }
  return result;
}

vll divisor(ll n) {
  vll ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  SORT(ret);
  return (ret);
}

const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {
  }
  mint operator-() const {
    return mint(-x);
  }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    return mint(*this) += a;
  }
  mint operator-(const mint a) const {
    return mint(*this) -= a;
  }
  mint operator*(const mint a) const {
    return mint(*this) *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod - 2);
  }
  mint& operator/=(const mint a) {
    return *this *= a.inv();
  }
  mint operator/(const mint a) const {
    return mint(*this) /= a;
  }
};
istream& operator>>(istream& is, const mint& a) {
  return is >> a.x;
}
ostream& operator<<(ostream& os, const mint& a) {
  return os << a.x;
}

struct combination {
  vector<mint> fact, ifact;
  combination(ll n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for (ll i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    ifact[n] = fact[n].inv();
    for (ll i = n; i >= 1; --i) {
      ifact[i - 1] = ifact[i] * i;
    }
  }
  mint operator()(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

struct AB {
  ll index;
  ll count;
  ll sum;
};
ll dp[200005][4];

signed main() {
  init();
  ll N;
  cin >> N;
  vll A(N);
  rep(i, N) cin >> A[i];

  ll k = 1 + N % 2;

  rep(i, N + 1) rep(j, k + 1) dp[i][j] = -INF;
  dp[0][0] = 0;

  rep(i, N) {
    rep(j, k + 1) {
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
      ll now = dp[i][j];
      if ((i + j) % 2 == 0) now += A[i];
      dp[i + 1][j] = max(dp[i + 1][j], now);
    }
  }
  ll ans = dp[N][k];
  ANS;
  return 0;
}