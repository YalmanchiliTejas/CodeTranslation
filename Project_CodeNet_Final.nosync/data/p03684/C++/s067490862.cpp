#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)
#define all(a) (a).begin(), (a).end()
#define sz(a) (a).size()
#define pb(a) push_back(a)
#define eb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
using namespace std;
using pii = pair<int, int>;
constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr double EPS = 1e-10;

struct edge {
  int f, t, c;
  edge() {}
  edge(int f, int t, int c) : f(f), t(t), c(c) {}
  bool operator < (const edge& e) {
    return c < e.c;
  }
};

int N;
vector<pair<pii, int>> ps;
vector<edge> es;
int par[100010];

int find(int x) {
  return par[x] < 0 ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  rep(i, 0, N) {
    int x, y;
    cin >> x >> y;
    ps.eb(pii(x, y), i);
  }
  sort(all(ps));
  rep(i, 0, N-1) {
    auto p = ps[i];
    auto q = ps[i+1];
    es.eb(p.second, q.second, q.first.first-p.first.first);
  }
  rep(i, 0, N) {
    auto p = ps[i];
    swap(p.first.first, p.first.second);
    ps[i] = p;
  }
  sort(all(ps));
  rep(i, 0, N-1) {
    auto p = ps[i];
    auto q = ps[i+1];
    es.eb(p.second, q.second, q.first.first-p.first.first);
  }

  fill(par, par+N, -1);
  sort(all(es));

  int ans = 0;
  rep(i, 0, sz(es)) {
    int u = find(es[i].f);
    int v = find(es[i].t);
    if (u == v) continue;
    unite(u, v);
    ans += es[i].c;
  }
  cout << ans << endl;

  return 0;
}