#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll extgcd(ll a, ll b, ll &x, ll &y) { ll d; return b == 0 ? (x = 1, y = 0, a) : (d = extgcd(b, a % b, y, x), y -= a / b * x, d); }
ll modinv(ll a, ll mod = 1e9 + 7) { ll x = 0, y = 0; extgcd(a, mod, x, y); return (x + mod) % mod; }
ll modpow(ll a, ll b, ll mod = 1e9 + 7) { ll r = 1; a %= mod; while(b) { if(b & 1) r = r * a % mod; a = a * a % mod; b >>= 1; } return r; }


// require math library
/// ModInt Library {{{ ///
template<long long mod = (long long)1e9 + 7>
struct ModInt{
  long long val;
  ModInt() : val(0) {}
  ModInt(long long val) : val((val % mod + mod) % mod) {}
  operator int() const { return val; }
  operator long long() const { return val; }
  ModInt operator+(ModInt const &rhs) const {
    return ModInt(val + rhs.val);
  }
  ModInt operator-(ModInt const &rhs) const {
    return ModInt(val - rhs.val);
  }
  ModInt operator*(ModInt const &rhs) const {
    return ModInt(val * rhs.val);
  }
  ModInt operator/(ModInt const &rhs) const {
    return ModInt(val * rhs.inv().val);
  }
  ModInt &operator+=(ModInt const &rhs) {
    val = ((val + rhs.val) % mod + mod) % mod;
    return *this;
  }
  ModInt &operator-=(ModInt const &rhs) {
    val = ((val - rhs.val) % mod + mod) % mod;
    return *this;
  }
  ModInt &operator*=(ModInt const &rhs) {
    val = (val * rhs.val % mod + mod) % mod;
    return *this;
  }
  ModInt &operator/=(ModInt const &rhs) {
    val = (val * rhs.inv().val % mod + mod) % mod;
    return *this;
  }
  ModInt operator++(int) {
    ModInt tmp = *this;
    val = val + 1;
    if(val >= mod) val = 0;
    return tmp;
  }
  ModInt operator--(int) {
    ModInt tmp = *this;
    val = val == 0 ? mod - 1 : val - 1;
    return tmp;
  }
  ModInt &operator++() {
    val = val + 1;
    if(val >= mod) val = 0;
    return *this;
  }
  ModInt &operator--() {
    val = val == 0 ? mod - 1 : val - 1;
    return *this;
  }
  template<typename T> ModInt operator+(T const &rhs) const {
    return ModInt(val + rhs % mod);
  }
  template<typename T> ModInt operator-(T const &rhs) const {
    return ModInt(val - rhs % mod);
  }
  template<typename T> ModInt operator*(T const &rhs) const {
    return ModInt(val * (rhs % mod));
  }
  template<typename T> ModInt operator/(T const &rhs) const {
    return ModInt(val * modinv(rhs, mod));
  }
  template<typename T> ModInt &operator+=(T const &rhs) {
    val = ((val + rhs % mod) % mod + mod) % mod;
    return *this;
  }
  template<typename T> ModInt &operator-=(T const &rhs) {
    val = ((val - rhs % mod) % mod + mod) % mod;
    return *this;
  }
  template<typename T> ModInt &operator*=(T const &rhs) {
    val = (val * (rhs % mod) % mod + mod) % mod;
    return *this;
  }
  template<typename T> ModInt &operator/=(T const &rhs) {
    val = (val * modinv(rhs, mod) % mod + mod) % mod;
    return *this;
  }
  ModInt inv() const {
    return ModInt(modinv(val, mod));
  }
  friend ostream &operator<<(ostream &os, ModInt const &mv) { os << mv.val; return os; }
  friend constexpr ModInt operator+(long long a, ModInt const &mv) { return ModInt(a % mod + mv.val); }
  friend constexpr ModInt operator-(long long a, ModInt const &mv) { return ModInt(a % mod - mv.val); }
  friend constexpr ModInt operator*(long long a, ModInt const &mv) { return ModInt(a % mod * mv.val); }
  friend constexpr ModInt operator/(long long a, ModInt const &mv) { return ModInt(a % mod * mv.inv().val); }
};
/// }}}-- ///

// #undef DEBUG
// #define DEBUG
/// {{{ DEBUG --- ///
#ifdef DEBUG
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << "{"; for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? ", " : ""); o << "}"; return o; }
#ifdef USE_COUT
#define dump(...) [&](){auto __debug_tap=make_tuple(__VA_ARGS__);cout<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<__debug_tap<<"\n";}()
#else
#define dump(...) [&](){auto __debug_tap=make_tuple(__VA_ARGS__);cout<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<__debug_tap<<"\n";}()
#endif
template<class T> inline void dump2D(T &d, size_t sizey, size_t sizex) { ostream&o=
#ifdef USE_COUT
  cout;
#else
  cerr;
#endif
  for(size_t i = 0; i < sizey; i++) { for(size_t j = 0; j < sizex; j++) o << d[i][j] << " "; o << endl; }
}
#else
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? " " : ""); return o; }
#define dump(...) (42)
#define dump2D(...) (42)
#endif
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream &o, tuple<T...> const &t){ o << "("; _ot<0>(o, t); o << ")"; return o; }
template<class T, class U> ostream & operator<<(ostream &o, pair<T, U> const &p) { o << "(" << p.first << ", " << p.second << ")"; return o; }
/// }}}--- ///


using Int = ModInt<>;

const int N = 1e5;
using P = pair<int, ll>;
vector<P> g[N];
int n, m;
const int mod = 1e9 + 7;
ll dist[2][N];
Int dp[2][N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int s, t;
  cin >> n >> m >> s >> t;
  s--; t--;
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  {
    int k = 0;
    for(int f : {s, t}) {
      for(int j = 0; j < n; j++) dist[k][j] = 1e18;
      dist[k][f] = 0;
      dp[k][f] = 1;
      // dijkstra {{{
      using P = tuple<ll, int>;
      priority_queue< P, vector<P>, greater<P> > pq;
      pq.emplace(0, f);
      while(pq.size()) {
        ll di; int i;
        tie(di, i) = pq.top(); pq.pop();
        if(dist[k][i] < di) continue;
        for(auto to : g[i]) {
          int j = to.first;
          ll ndi = di + to.second;
          if(dist[k][j] > ndi) {
            dist[k][j] = ndi;
            pq.emplace(ndi, j);
          }
        }
      }
      // }}}
      // dijkstra {{{
      pq.emplace(0, f);
      int did[N] = {};
      while(pq.size()) {
        ll di; int i;
        tie(di, i) = pq.top(); pq.pop();
        if(did[i]) continue;
        did[i] = 1;
        for(auto to : g[i]) {
          int j = to.first;
          ll ndi = di + to.second;
          if(dist[k][j] == ndi) {
            dp[k][j] += dp[k][i];
            if(k == 1) dump(i, j, dp[k][j], dp[k][i]);
            pq.emplace(ndi, j);
          }
        }
      }
      // }}}
      k++;
    }
  }
  dump(dist[0][t]);
  dump(dist[1][s]);
  dump(dp[0][t]);
  dump(dp[1][s]);
  assert(dist[0][t] == dist[1][s]);
  assert(dp[0][t].val == dp[1][s].val);
  Int ans = (Int) dp[0][t] * dp[1][s];
  for(int i = 0; i < n; i++) {
    if(dist[0][i] * 2 == dist[0][t] &&
        dist[1][i] * 2 == dist[0][t]) {
      dump(dp[0][i] * dp[1][i], i);
      ans -= dp[0][i] * dp[1][i] * dp[0][i] * dp[1][i];
    }
    for(auto to : g[i]) {
      int j = to.first;
      ll c = to.second;
      if(
          dist[0][i] + dist[1][j] + c == dist[0][t] &&
          dist[0][i] * 2 < dist[0][t] &&
          (dist[0][i] + c) == dist[0][j] &&
          dist[1][j] * 2 < dist[0][t] &&
          (dist[1][j] + c) == dist[1][i]) {
        dump(dp[0][i] * dp[1][j], i, j);
        ans -= dp[0][i] * dp[1][j] * dp[1][j] * dp[0][i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}

