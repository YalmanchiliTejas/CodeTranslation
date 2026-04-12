/* template.cpp {{{ */
#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define GET_MACRO(a, b, c, d, NAME, ...) NAME
#define REP1(n) REP2(i_, n)
#define REP2(i, n) REP3(i, 0, n)
#define REP3(i, a, b) REP4(i, a, b, 1)
#define REP4(i, a, b, s) for (long long i = (a); i < (long long)(b); i += (long long)(s))
#define RREP1(n) RREP2(i_, n)
#define RREP2(i, n) RREP3(i, 0, n)
#define RREP3(i, a, b) RREP4(i, a, b, 1)
#define RREP4(i, a, b, s) for (long long i = (b) - 1; i >= (long long)(a);  i -= (long long)(s))
#define rep(...) GET_MACRO(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, RREP4, RREP3, RREP2, RREP1)(__VA_ARGS__)
#define fs first
#define sc second
#define all(c) std::begin(c), std::end(c)
#define pcnt(x) __builtin_popcountll(x)
#define each(x, c) for (auto &&x : c)
#define endl "\n"
#define y0 y0_
#define y1 y1_
#define yn yn_
 
#define TMP_T template<typename T>
#define TMP_TU template<typename T, typename U>
#define TMP_Ts template<typename ...T>
#define TMP_NTs template<size_t N, typename ...T>
#define TMP_CT template<bool C, typename T = void>
 
#ifndef DEBUG
#define cerr no_output
struct NoOutput : ostream {
  TMP_T ostream &operator<<(const T &){ return *this; }
} no_output;
#endif
 
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
TMP_T using PQL = priority_queue<T, vector<T>, greater<T>>;
TMP_T using PQG = priority_queue<T>;
TMP_CT using enable_if_t = typename enable_if<C, T>::type;
 
const ll LLINF = 1e18 + 10;
#ifndef int
const int INF = 1e9 + 10;
#else
const int INF = LLINF;
#endif
 
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
 
TMP_T inline constexpr T sq(T x){ return x * x; }
TMP_TU inline T& chmin(T &x, U y){ if (x > y) x = y; return x; }
TMP_TU inline T& chmax(T &x, U y){ if (x < y) x = y; return x; }
 
TMP_NTs enable_if_t<(N >= sizeof...(T))> input_tuple(istream &, tuple<T...> &){}
TMP_NTs enable_if_t<(N < sizeof...(T))> input_tuple(istream &is, tuple<T...> &x){ is >> get<N>(x); input_tuple<N + 1, T...>(is, x); }
TMP_Ts ostream &operator>>(istream &is, tuple<T...> &x){ input_tuple<0, T...>(is, x); return is; }
TMP_TU ostream &operator>>(istream &is, pair<T, U> &x){ return is >> x.first >> x.second; }
TMP_NTs enable_if_t<(N >= sizeof...(T))> print_tuple(ostream &, const tuple<T...> &){}
TMP_NTs enable_if_t<(N < sizeof...(T))> print_tuple(ostream &os, const tuple<T...> &x){ os << (N > 0 ? " " : "") << get<N>(x); print_tuple<N + 1, T...>(os, x); }
TMP_Ts ostream &operator<<(ostream &os, const tuple<T...> &x){ print_tuple<0, T...>(os, x); return os; }
TMP_TU ostream &operator<<(ostream &os, const pair<T, U> &x){ return os << x.first << " " << x.second; }
 
#undef TMP_T
#undef TMP_TU
#undef TMP_Ts
#undef TMP_NTs
#undef TMP_CT

ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
tuple<ll, ll, ll> extgcd(ll a, ll b){
  if (b){
    ll g, x, y;
    tie(g, x, y) = extgcd(b, a % b);
    return make_tuple(g, y, x - a / b * y);
  }
  return make_tuple(a, 1, 0);
}
ll invmod(ll a, ll m = 1000000007){
  ll g, x;
  tie(g, x, ignore) = extgcd(a, m);
  return g == 1 ? (x + m) % m : 0;
}

inline ll in(){ ll x; cin >> x; return x; }
 
struct prepare {
  prepare(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(12);
  }
} prepare_;
/* }}} */

int n;
int a, d;
int m;
int x[200000], y[200000], z[200000];
int k;

signed main()
{
  cin >> n >> a >> d >> m;
  rep(i, m) cin >> x[i] >> y[i] >> z[i];
  cin >> k;
  rrep(i, m){
    if (x[i] == 0){
      if (y[i] <= k && k <= z[i]){
        k = y[i] + z[i] - k;
      }
    }
  }
  int v = a + (k - 1) * d;
  rep(i, m){
    if (x[i] == 0){
      if (y[i] <= k && k <= z[i]){
        k = y[i] + z[i] - k;
      }
    }
    else if (x[i] == 1){
      if (y[i] <= k && k <= z[i]){
        v++;
      }
    }
    else if (x[i] == 2){
      if (y[i] <= k && k <= z[i]){
        v /= 2;
      }
    }
  }
  cout << v << endl;
}