#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;

struct Edge {
  int u, v, w;
  Edge() {};
  Edge(int _u, int v_, int w_) : u(_u), v(v_), w(w_) {};
  bool operator< (Edge b) {
    return w < b.w;
  }
};

struct cmp
{
    bool operator() (const Edge &a,const Edge &b)
    {
        return a.w > b.w;
    }
};

struct Point {
  int x, y, id;
} a[N];

int n, par[N];
priority_queue <Edge, vector <Edge>, cmp> q;

int findSet(int x) {
  if (par[x] < 0) return x;
  return (par[x] = findSet(par[x]));
}

void join(int x, int y) {
  if ((x = findSet(x)) == (y = findSet(y))) return;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y]; par[y] = x;
}

int main() {
  #ifdef GG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  memset(par, -1, sizeof(par));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].id = i;
  }
  sort(a, a + n, [](Point a, Point b) { return a.x < b.x; });
  for (int i = 0; i < n - 1; ++i) {
    q.push(Edge(a[i].id, a[i + 1].id, abs(a[i].x - a[i + 1].x)));
  }
  sort(a, a + n, [](Point a, Point b) { return a.y < b.y; });
  for (int i = 0; i < n - 1; ++i) {
    q.push(Edge(a[i].id, a[i + 1].id, abs(a[i].y - a[i + 1].y)));
  }
  long long ans = 0;
  while (! q.empty()) {
    Edge tmp = q.top(); q.pop();
    int x = findSet(tmp.u);
    int y = findSet(tmp.v);
    if (x != y) {
      ans = ans + 1LL * tmp.w;
      join(x, y);
    }
  }
  cout << ans;
  return 0;
}
