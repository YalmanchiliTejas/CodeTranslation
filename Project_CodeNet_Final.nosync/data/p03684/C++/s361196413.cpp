#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

struct point {
  ll x, y;
  int id;
  point () {}
  point (ll _x, ll _y, int _id) {
    x = _x, y = _y, id = _id;
  }
  bool operator < (const point &other) const {
    return x == other.x ? y < other.y : x < other.x;
  }
};

struct edge {
  int u, v;
  ll cost;
  edge () {}
  edge (int _u, int _v, ll _w) {
    u = _u, v = _v, cost = _w;
  }
  bool operator < (const edge &other) const {
    return cost < other.cost;
  }
};

const int N = 100010;

point p[N];
int n, par[N];
vector <edge> e;

bool cmp (point a, point b) {
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}

int find (int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

ll ans = 0;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    p[i].id = i;
    scanf("%lld %lld", &p[i].x, &p[i].y);
  }
  sort(p + 1, p + n + 1);
  for (int i = 2; i <= n; ++i) {
    e.push_back(edge(p[i - 1].id, p[i].id, p[i].x - p[i - 1].x));
  }
  sort(p + 1, p + n + 1, cmp);
  for (int i = 2; i <= n; ++i) {
    e.push_back(edge(p[i - 1].id, p[i].id, p[i].y - p[i - 1].y));
  }
  sort(e.begin(), e.end());
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  for (int i = 0; i < int(e.size()); ++i) {
    int u = e[i].u, v = e[i].v;
    ll cost = e[i].cost;
    u = find(u), v = find(v);
    if (u == v) continue;
    par[u] = v, ans += cost;
  }
  printf("%lld\n", ans);
  return 0;
}

