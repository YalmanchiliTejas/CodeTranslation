#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

template<typename T>
struct edge {
  int src, to;
  T cost;
  // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
  // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s) {
  const auto INF = numeric_limits<T>::max();
  vector<T> d(g.size(), INF);

  using Pi = pair<T, int>;
  priority_queue<Pi, vector<Pi>, greater<Pi>> que;
  d[s] = 0;
  que.emplace(d[s], s);
  while (!que.empty()) {
    T cost;
    int v;
    tie(cost, v) = que.top();
    que.pop();
    if (d[v] < cost) continue;
    for (auto &e : g[v]) {
      auto nxt = cost + e.cost;
      if (d[e.to] > nxt) {
        d[e.to] = nxt;
        que.emplace(nxt, e.to);
      }
    }
  }
  return d;
}

template<typename T>
void topological_sort(const Graph<T>& G, vector<int>& ord)
{
  int n = G.size();
  vector<int> num(n, 0);
  ord.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    for (auto u : G[i]) {
      ++num[u.to];
    }
  }
  stack<int> st;
  for(int i = 0; i < n; ++i) {
    if (num[i] == 0) {
      st.push(i);
    }
  }
  for (int k = 0; !st.empty(); ++k) {
    int i = st.top(); st.pop();
    ord[k] = i;
    for (auto u : G[i]) {
      if (--num[u.to] == 0) {
        st.push(u.to);
      }
    }
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m; cin >> n >> m;
  int s, t; cin >> s >> t;
  s--; t--;

  Graph<int> g(n);
  REP(i, m) {
    int u, v, d; cin >> u >> v >> d;
    u--; v--;
    g[u].push_back({u, v, d});
    g[v].push_back({v, u, d});
  }

  auto d1 = dijkstra(g, s);
  auto d2 = dijkstra(g, t);

  Graph<int> g1(n), g2(n);

  vector<P> v1(n), v2(n);
  REP(i, n) {
    v1[i] = {d1[i], i};
    v2[i] = {d2[i], i};
  }
  sort(ALL(v1));
  sort(ALL(v2));

  vector<ll> dp1(n), dp2(n);
  dp1[s] = 1;
  dp2[t] = 1;
  REP(i, n) {
    for(auto &e: g[v1[i].second]) {
      if(d1[e.src] + e.cost == d1[e.to]) {
        dp1[e.to] += dp1[e.src];
        dp1[e.to] %= MOD;
      }
    }
    for(auto &e: g[v2[i].second]) {
      if(d2[e.src] + e.cost == d2[e.to]) {
        dp2[e.to] += dp2[e.src];
        dp2[e.to] %= MOD;
      }
    }
  }
/*
  cout << endl;
  cout << d1 << endl;
  cout << d2 << endl;
  cout << dp1 << endl;
  cout << dp2 << endl;
  cout << v1 << endl;
  cout << v2 << endl;
  */

  ll ans = 0;
  REP(i, n) {
    if(d1[i] == d2[i]) {
      ans += dp1[i] * dp1[i] % MOD * dp2[i] % MOD * dp2[i] % MOD;
      ans %= MOD;
    }
  }

  REP(i, n) {
    for(auto &e: g[i]) {
      if(2 * d1[e.src] < d1[t] && 2 * d1[e.to] > d1[t] && d1[e.src] + e.cost + d2[e.to] == d1[t]) {
        ans += dp1[e.src] * dp1[e.src] % MOD * dp2[e.to] % MOD * dp2[e.to] % MOD;
        ans %= MOD;
      }
    }
  }

  cout << (dp1[t] * dp1[t] % MOD + MOD - ans) % MOD << endl;



}






















