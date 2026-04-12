/* template.cpp {{{ */
#include <bits/stdc++.h>
using namespace std;

namespace solver {

#define GET_MACRO(a, b, c, d, NAME, ...) NAME
#define REP1(n) REP2(i_, n)
#define REP2(i, n) REP3(i, 0, n)
#define REP3(i, a, b) REP4(i, a, b, 1)
#define REP4(i, a, b, s) for (ll i = (a); i < (ll)(b); i += (ll)(s))
#define RREP1(n) RREP2(i_, n)
#define RREP2(i, n) RREP3(i, 0, n)
#define RREP3(i, a, b) RREP4(i, a, b, 1)
#define RREP4(i, a, b, s) for (ll i = (b) - 1; i >= (ll)(a); i -= (ll)(s))
#define rep(...) GET_MACRO(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, RREP4, RREP3, RREP2, RREP1)(__VA_ARGS__)
#define each(x, c) for (auto &&x : c)
#define all(c) std::begin(c), std::end(c)

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
template<typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using MaxPQ = priority_queue<T, vector<T>, less<T>>;
template<bool cond, typename T = void>
using enable_if_t = typename enable_if<cond, T>::type;

const int INF = 1e9 + 10;
const ll INF_LL = 1e18 + 10;
const double INF_D = 1e12;
const ld INF_LD = 1e24;
const ld EPS = 1e-8;
const ld PI = acos(-1.0l);
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

template<typename T>
inline T sq(const T &x){ return x * x; }
template<typename T, typename U>
inline T &chmin(T &x, const U &y){ if (x > y) x = y; return x; }
template<typename T, typename U>
inline T &chmax(T &x, const U &y){ if (x < y) x = y; return x; }

ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
tuple<ll, ll, ll> extgcd(ll a, ll b){
  if (b == 0) return make_tuple(a, 1, 0);
  ll g, x, y;
  tie(g, x, y) = extgcd(b, a % b);
  return make_tuple(g, y, x - a / b * y);
}
ll invmod(ll a, ll m = 1000000007){
  ll g, x;
  tie(g, x, ignore) = extgcd(a, m);
  return g == 1 ? (x + m) % m : 0;
}

void solve();

}

signed main(){
  auto begin = std::chrono::high_resolution_clock::now();
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(12);
  solver::solve();
  auto end = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
#ifdef DEBUG
  std::cerr << "time: " << time.count() << " [ms]" << std::endl;
#endif
}

namespace solver {
/* }}} */
/* modint.cpp {{{ */
template<uint MOD>
class ModInt {
public:
  ModInt(): x(0){}
  ModInt(ll x): x((x % MOD + MOD) % MOD){}
  operator uint() const { return x; }
  friend ostream& operator<<(ostream &os, const ModInt &m){ return os << m.x; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return x ? ModInt(MOD - x) : ModInt(0); }
  ModInt operator+=(const ModInt &o){ if ((x += o.x) >= MOD) x -= MOD; return *this; }
  ModInt operator-=(const ModInt &o){ if ((x += MOD - o.x) >= MOD) x -= MOD; return *this; }
  ModInt operator*=(const ModInt &o){ x = (ull)(x) * o.x % MOD; return *this; }
  ModInt operator/=(const ModInt &o){ return *this *= o.inv(); }
  ModInt operator+(const ModInt &o) const { return ModInt(*this) += o.x; }
  ModInt operator-(const ModInt &o) const { return ModInt(*this) -= o.x; }
  ModInt operator*(const ModInt &o) const { return ModInt(*this) *= o.x; }
  ModInt operator/(const ModInt &o) const { return ModInt(*this) /= o.x; }
  ModInt inv() const { return ModInt(invmod(x, MOD)); }
  ModInt pow(ll e) const {
    if (e < 0) return inv().pow(-e);
    ModInt s(1), t(x);
    while (e > 0){
      if (e & 1) s *= t;
      t *= t;
      e >>= 1;
    }
    return s;
  }
private:
  uint x;
};

using mod7 = ModInt<1000000007>;
using mod9 = ModInt<1000000009>;
/* }}} */

int n, x;
ll d;
mod7 dp[2010][2010];
mod7 s[2010][2010];

mod7 C(ll n, ll r){
  if (r < 0 || n < r) return 0;
  mod7 res{1};
  rep(i, r) res *= mod7(n - i) * mod7(i + 1).inv();
  return res;
}

void solve(){
  while (cin >> n >> d >> x, n){
    fill_n(*dp, 2010 * 2010, 0);
    fill_n(*s, 2010 * 2010, 0);
    dp[0][0] = 1;
    rep(i, n) s[0][i + 1] = s[0][i] + dp[0][i];
    rep(i, n) rep(j, 1, n + 1){
      dp[i + 1][j] = s[i][j] - s[i][max<int>(0, j - x + 1)];
      s[i + 1][j + 1] = s[i + 1][j] + dp[i + 1][j];
    }
    mod7 res{0};
    rep(i, 1, n + 1) res += C(d, i) * dp[i][n];
    cout << res << endl;
  }
}

} /* namespace solver */