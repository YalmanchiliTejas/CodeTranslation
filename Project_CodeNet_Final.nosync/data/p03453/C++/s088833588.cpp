#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;

const int N = 1e5 + 10, M = 2e5 + 10, B = 1e9 + 7;
const ll inf = (ll)1e18 + 10;

int n, m;
vector < pair <int, int> > e[N];
int U[M], V[M], D[M];
bool vis[N];
ll dis[2][N], ways[2][N];
int S, T;

void add(ll &x, ll y) {
  x = (x + y) % B;
  if (x < 0) x += B;
}

void dij(int s, ll dis[], ll ways[]) {
  priority_queue < pair <ll, int> > pq;
  fill_n(vis + 1, n, 0);
  fill_n(dis + 1, n, inf);
  fill_n(ways + 1, n, 0);
  dis[s] = 0;
  ways[s] = 1;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto t = pq.top();
    int u = t.second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      ll w = ed.second;
      int v = ed.first;
      if (dis[v] == dis[u] + w) {
        add(ways[v], ways[u]);
      } else if (dis[v] > dis[u] + w) {
        ways[v] = ways[u];
        dis[v] = dis[u] + w;
        pq.emplace(-dis[v], v);
      }
    }
  }
}

ll mul(ll x, ll y) {
  x = x * y % B;
  if (x < 0) x += B;
  return x;
}

void run() {
  cin >> n >> m;
  cin >> S >> T;
  for (int i = 1; i <= m; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    U[i] = u, V[i] = v, D[i] = d;
    e[u].emplace_back(v, d);
    e[v].emplace_back(u, d);
  }
  dij(S, dis[0], ways[0]);
  dij(T, dis[1], ways[1]);
  ll dd = dis[0][T];
  //pair <int, int> fenshu(dd, 2);
  ll ans = mul(ways[0][T], ways[1][S]);
  debug(ans);
  ll sub = 0;
  debug(dd);

  debug(e[2]);
  debug(e[3]);
  for (int j = 1; j <= n; ++j) {
    if (dis[0][j] * 2 == dd && dis[1][j] * 2 == dd) {
      ll tmp = mul(ways[0][j], ways[1][j]);
      add(sub, mul(tmp, tmp));
      debug(sub);
    debug(j);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int u = U[i], v = V[i];
    if (dis[0][u] > dis[0][v]) swap(u, v);
    if (dis[0][u] * 2 < dd && dis[0][v] * 2 > dd && dis[0][u] + D[i] == dis[0][v] && dis[0][u] + dis[1][u] == dd && dis[0][v] + dis[1][v] == dd) {
      ll tmp = mul(ways[0][u], ways[1][v]);
      add(sub, mul(tmp, tmp));
      debug(sub, dis[0][v], dis[0][u], u, v);
    }
  }
  add(ans, -sub);
  cout << ans << endl;
}

int main() {
  run();
  return 0;
}
