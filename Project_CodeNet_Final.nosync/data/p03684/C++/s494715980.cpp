#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010
#define int long long

typedef pair<int, int> P;

int par[MAX * 2];
int rk[MAX * 2];

struct edge{ int u, v, cost; };

edge es[MAX * 2];
int n;

void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rk[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rk[x] < rk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

int kruskal() {
  int m = 2 * n - 2;
  sort(es, es + m, comp);
  init(m);
  int res = 0;
  for (int i = 0; i < m; i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

signed main() {
  cin >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  P xres[n], yres[n];
  for (int i = 0; i < n; i++) {
    xres[i] = P(x[i], i);
    yres[i] = P(y[i], i);
  }
  sort(xres, xres + n);
  sort(yres, yres + n);
  for (int i = 0; i < n - 1; i++) {
    edge tmp;
    tmp.u = xres[i].second;
    tmp.v = xres[i + 1].second;
    tmp.cost = abs(xres[i + 1].first - xres[i].first);
    es[i] = tmp;
  }
  for (int i = n - 1; i < 2 * n - 2; i++) {
    edge tmp;
    tmp.u = yres[i - n + 1].second;
    tmp.v = yres[i - n + 2].second;
    tmp.cost = abs(yres[i - n + 1].first - yres[i - n + 2].first);
    es[i] = tmp;
  }
  /*
  for (int i = 0; i < 2 * n - 2; i++) {
    cout << es[i].u << " " << es[i].v << " " << es[i].cost << endl;
  }
  */
  cout << kruskal() << endl;
  return 0;
}
