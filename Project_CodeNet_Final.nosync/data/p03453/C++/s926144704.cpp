/**
 *     author: qodjf
 *     created: 07.11.2020 14:28:49
 */
#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
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
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

template <class T>
inline bool chmax(T &a, T b) {
  return a < b && (a = b, true);
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b && (a = b, true);
}

#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using ll = long long;
using P = pair<ll, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 1e9 + 7;

inline ll mul(ll a, ll b) { return a * b % MOD; }

inline ll add(ll a, ll b) { return (a + b) % MOD; }

inline ll sub(ll a, ll b) {
  int x = (a - b) % MOD;
  return x < 0 ? x + MOD : x;
}

struct edge {
  int to, cost;
};

int N, M, S, T;
vector<edge> g[100010];

vector<P> dijkstra(int s) {
  vector<P> d(N, {LLINF, 0});
  priority_queue<P, vector<P>, greater<P>> que;
  d[s] = {0, 1};
  que.emplace(0, s);

  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    int u = p.second;
    if (d[u].first < p.first) continue;
    for (const auto &e : g[u]) {
      int v = e.to;
      if (chmin(d[v].first, d[u].first + e.cost)) {
        d[v].second = d[u].second;
        que.emplace(d[v].first, v);
      } else if (d[v].first == d[u].first + e.cost) {
        d[v].second = add(d[v].second, d[u].second);
      }
    }
  }
  return d;
}

void solve() {
  vector<P> fromS = dijkstra(S);
  vector<P> fromT = dijkstra(T);

  ll dis = fromS[T].first;
  ll ans = mul(fromS[T].second, fromS[T].second);
  rep(i, 0, N) {
    if (fromS[i].first * 2 == dis) {
      int tmp = mul(fromS[i].second, fromT[i].second);
      ans = sub(ans, mul(tmp, tmp));
    }
  }

  rep(i, 0, N) {
    if (fromS[i].first + fromT[i].first != dis || fromS[i].first * 2 >= dis)
      continue;
    for (const auto &e : g[i]) {
      if (fromS[i].first + e.cost + fromT[e.to].first == dis &&
          fromS[e.to].first * 2 > dis) {
        ll tmp = mul(fromS[i].second, fromT[e.to].second);
        ans = sub(ans, mul(tmp, tmp));
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> S >> T;
  S--, T--;
  rep(i, 0, M) {
    int u, v, d;
    cin >> u >> v >> d;
    u--, v--;
    g[u].push_back(edge{v, d});
    g[v].push_back(edge{u, d});
  }
  solve();
}
