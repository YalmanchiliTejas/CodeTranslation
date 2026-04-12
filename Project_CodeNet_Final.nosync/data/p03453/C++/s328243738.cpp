#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep1(i,n) for (int i=1; i<(int)(n); ++i)
#define repeq(i,n) for (int i=0; i<=(int)(n); ++i)
#define rep1eq(i,n) for (int i=1; i<=(int)(n); ++i)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define rrep1(i,n) for (int i=(int)(n)-1; i>0; --i)
#define rrepeq(i,n) for (int i=(int)(n); i>=0; --i)
#define rrep1eq(i,n) for (int i=(int)(n); i>0; --i)
#define REP(i,a,b) for (int i=(int)(a); i<=(int)(b); ++i)
#define RREP(i,a,b) for (int i=(int)(a); i>=(int)(b); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
template<typename T> using Graph = vector<vector<T>>;
template<typename T> using Spacial = vector<vector<vector<T>>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9+7;
const int MOD2 = 998244353;
// const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string interval[2] = {" ", "\n"}; // {" ", "\n"}

template<typename T> struct is_plural : false_type{};
template<typename T1, typename T2> struct is_plural<pair<T1, T2>> : true_type{};
template<typename T> struct is_plural<vector<T>> : true_type{};
template<typename T> struct is_plural<complex<T>> : true_type{};
 
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << " " << p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto itr = vec.begin(); itr != vec.end(); ++itr) is >> *itr; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { if (vec.empty()) return os; bool pl = is_plural<T>(); os << vec.front(); for (auto itr = ++vec.begin(); itr != vec.end(); ++itr) os << interval[pl] << *itr; return os; }
 
bool CoutYN(bool a, string y = "Yes", string n = "No") { cout << (a ? y : n) << "\n"; return a; }

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

long long modpow(int a, long long n, int mod = MOD) { long long ret = 1; do { if (n & 1) ret = ret * a % mod; a = 1LL * a * a % mod; } while (n >>= 1); return ret; }

template<typename T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

template<typename T1, typename T2> bool CompareBySecond(pair<T1, T2> a, pair<T1, T2> b) { return a.second != b.second ? a.second < b.second : a.first < b.first; }
// counterclockwise from 12 o'clock direction
template<typename T> bool CompareBySlope(pair<T, T> a, pair<T, T> b) { if (a.first * b.first < 0) return a.first < b.first; if (a.first == 0) return a.second >= 0 || b.first > 0; if (b.first == 0) return b.second < 0 && a.first < 0; return a.second * b.first < a.first * b.second; }


/* -------- <templates end> -------- */


template<typename T>
struct edge {
  int from, to;
  T cost;

  edge(int to, T cost) : from(-1), to(to), cost(cost) {}

  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

  bool operator<(const edge<T> &e) const {
    return cost < e.cost;
  }
};

template<typename T> using Edges = vector<edge<T>>;
template<typename T> using WeightedGraph = vector<vector<edge<T>>>;

void solve() {
  int n, m; cin >> n >> m;
  int s, t; cin >> s >> t; --s, --t;
  WeightedGraph<ll> g(n);
  rep(i,m) {
    int u, v, d; cin >> u >> v >> d; --u, --v;
    g[u].emplace_back(v, d);
    g[v].emplace_back(u, d);
  }

  Graph<ll> dist(2, vl(n, 1LL<<60)), cnt(2, vl(n));

  rep(i,2) {
    dist[i][s] = 0, cnt[i][s] = 1;

    priority_queue<edge<ll>> pq;
    pq.emplace(s, 0);

    while (!pq.empty()) {
      auto e = pq.top(); pq.pop();

      if (dist[i][e.to] < -e.cost) continue;

      for (auto &ne : g[e.to]) {
        ll d = -e.cost + ne.cost;
        if (chmin(dist[i][ne.to], d)) {
          cnt[i][ne.to] = cnt[i][e.to];
          pq.emplace(ne.to, -d);
        } else if (dist[i][ne.to] == d) {
          (cnt[i][ne.to] += cnt[i][e.to]) %= MOD;
        }
      }
    }

    swap(s, t);
  }

  ll d = dist[0][t];
  ll sum = 0, encount = 0;

  rep(i,n) {
    if (dist[0][i] * 2 > d) continue;

    if (dist[0][i] * 2 == d && dist[1][i] * 2 == d) {
      ll tmp = cnt[0][i] * cnt[1][i] % MOD;
      sum += tmp;
      encount += tmp * tmp % MOD;
      continue;
    }

    for (auto &e : g[i]) {
      if (dist[1][e.to] * 2 >= d) continue;

      if (dist[0][i] + e.cost + dist[1][e.to] == d) {
        ll tmp = cnt[0][i] * cnt[1][e.to] % MOD;
        sum += tmp;
        encount += tmp * tmp % MOD;
      }
    }
  }

  sum %= MOD, encount %= MOD;
  ll ans = (sum * sum + MOD - encount) % MOD;
  cout << ans << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
