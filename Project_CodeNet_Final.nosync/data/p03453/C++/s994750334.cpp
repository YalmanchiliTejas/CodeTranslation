#include <bits/stdc++.h>  // clang-format off
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)

#ifdef ONLINE_JUDGE
  #define rep(i,N) for(int i = 0; i < (int)(N); i++)
  #define repr(i,N) for(int i = (int)(N) - 1; i >= 0; i--)
  #define rep1(i,N) for(int i = 1; i <= (int)(N) ; i++)
  #define repr1(i,N) for(int i = (N) ; (int)(i) > 0 ; i--)
#else
  #define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
  #define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
  #define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
  #define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#endif

using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); for(int i=0;i<s;i++) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}

#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);} while(0)
  #define trcc(v) do { cerr << "name : " << #v << "\n"; int cnt = 0; each(x , v){cerr << (cnt++) << " : "; trc(x); } } while(0)
#else
  #define trc(...)
  #define trca(...)
  #define trcc(...)
  int main(){solve();}
#endif

#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define in2(s,t)     rep(i,sz(s)){in(s[i] , t[i]);}
#define in3(s,t,u)   rep(i,sz(s)){in(s[i] , t[i] , u[i]);}
#define in4(s,t,u,v) rep(i,sz(s)){in(s[i] , t[i] , u[i] , v[i]);}
using vd = V<double>; using vs = V<string>; using vvl = V< V<> >;
template<typename T,typename U>ll ceil(T a,U b){return (a + b - 1) / b;}

using P = pair<ll,ll>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
// clang-format on
/////////////////////////

template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnweightedGraph = vector<vector<int>>;

// グラフの入力
UnweightedGraph graph(int N, int M = -1, bool is_directed = false,
                      bool is_1origin = true) {
  UnweightedGraph g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    if (is_1origin) x--, y--;
    g[x].pb(y);
    if (!is_directed) g[y].pb(x);
  }
  return g;
}

// 重み付きグラフの入力
template <typename T>
WeightedGraph<T> wgraph(int N, int M = -1, bool is_directed = false,
                        bool is_1origin = true) {
  WeightedGraph<T> g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    cin >> c;
    if (is_1origin) x--, y--;
    g[x].eb(x, y, c);
    if (!is_directed) g[y].eb(y, x, c);
  }
  return g;
}

// dijkstra 到達不可能な場合はINFを返す
template <typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int start = 0) {
  using P = pair<T, int>;
  int N = (int)g.size();
  T INF = numeric_limits<T>::max() / 2;
  vector<T> d(N, INF);
  priority_queue<P, vector<P>, greater<P>> Q;
  d[start] = 0;
  Q.emplace(0, start);
  while (!Q.empty()) {
    P p = Q.top();
    Q.pop();
    int cur = p.second;
    if (d[cur] < p.first) continue;
    for (auto dst : g[cur]) {
      if (d[cur] + dst.cost < d[dst]) {
        d[dst] = d[cur] + dst.cost;
        Q.emplace(d[dst], dst);
      }
    }
  }
  return d;
}

template <int mod>
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt<MOD>;
using vm = vector<modint>;
using mint = modint;

void solve() {
  ini(N, M, S, T);
  S--, T--;
  auto g = wgraph<ll>(N, M);
  auto ds = dijkstra<ll>(g, S);
  auto dt = dijkstra<ll>(g, T);

  auto bfs = [&N, &g, &ds , &dt,&T](int start, vl &d) -> pair<vm, vi> {
    vm ret(N);
    vi used(N);
    priority_queue<P, vp, greater<P>> Q;
    Q.push(P(d[start] , start));
    ret[start] = 1 , used[start] = 1;
    while(!Q.empty()){
      int cur = Q.top().second; Q.pop();
      each(dst , g[cur]){
        if(d[cur] >= d[dst]) continue;
        if(ds[dst] + dt[dst] != ds[T]) continue;
        if(d[cur] + dst.cost != d[dst]) continue;
        ret[dst] += ret[cur];
        if(used[dst] == 0){
          used[dst] = 1;
          Q.emplace(d[dst] , dst);
        }
      }
    }
    trc(ret , used);
    return pair<vm, vi>(ret, used);
  };

  vm sc, tc;
  vi su, tu;
  tie(sc, su) = bfs(S, ds);
  tie(tc, tu) = bfs(T, dt);
  modint ans = sc[T] * tc[S];

  // 頂点上で重なる
  rep(i, N) {
    if (su[i] == 0 || tu[i] == 0) continue;
    if (dt[i] == ds[i]) {
      ans -= sc[i] * sc[i] * tc[i] * tc[i];
    }
  }

  // 辺上で重なる
  rep(i, N) each(e, g[i]) {
    int u = i, v = e.to;
    if (su[u] == 0 || tu[u] == 0) continue;
    if (su[v] == 0 || tu[v] == 0) continue;
    if (ds[u] == dt[u] || ds[v] == dt[v]) continue;
    if (ds[u] > ds[v]) continue;
    if(ds[u] + e.cost != ds[v]) continue;
    if ((dt[v] - ds[v] > 0) != (dt[u] - ds[u] > 0)) {
      ans -= sc[u] * sc[u] * tc[v] * tc[v];
    }
  }

  out(ans);
}