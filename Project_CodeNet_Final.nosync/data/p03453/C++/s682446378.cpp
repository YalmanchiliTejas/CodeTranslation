#include <bits/stdc++.h>

using namespace std;

const int mod = 1'000'000'007;

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
}

int mul(int a, int b) {
  return (int)(1LL * a * b % mod);
}

const long long inf = 1e18;
const int N = 200010;

int n;
vector < pair <int, int> > g[N];

void work(int from, vector <long long> &d, vector <int> &ways) {
  set < pair <long long, int> > s;
  for (int i = 0; i < n; ++i) {
    d[i] = inf;
    ways[i] = 0;
  }
  d[from] = 0;
  ways[from] = 1;
  s.emplace(0, from);
  while (!s.empty()) {
    int x = (s.begin())->second;
    s.erase(s.begin());
    for (auto e : g[x]) {
      int y = e.first;
      int c = e.second;
      if (d[x] + c < d[y]) {
        if (d[y] != inf) {
          s.erase(s.find({d[y], y}));
        }
        d[y] = d[x] + c;
        ways[y] = ways[x];
        s.emplace(d[y], y);
      } else
      if (d[x] + c == d[y]) {
        add(ways[y], ways[x]);
      }
    }
  }
}

int x[N];
int y[N];
int v[N];
bool bad[N];

int main() {
  int m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  --s; --t;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", x + i, y + i, v + i);
    --x[i]; --y[i];
    g[x[i]].emplace_back(y[i], v[i]);
    g[y[i]].emplace_back(x[i], v[i]);
  }
  vector <long long> ds(n);
  vector <int> ws(n);
  work(s, ds, ws);
  vector <long long> dt(n);
  vector <int> wt(n);
  work(t, dt, wt);
  memset(bad, false, sizeof bad);
  int ans = mul(ws[t], ws[t]);
  for (int i = 0; i < n; ++i) {
    if (i == s || i == t) {
      continue;
    }
    if (ds[i] + dt[i] == ds[t] && ds[i] == dt[i]) {
      int z = mul(ws[i], wt[i]);
      sub(ans, mul(z, z));
      bad[i] = true;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (bad[x[i]] || bad[y[i]]) {
      continue;
    }
    if (ds[x[i]] + v[i] + dt[y[i]] == ds[t] && max(ds[x[i]], dt[y[i]]) - min(ds[x[i]], dt[y[i]]) <= v[i]) {
      int z = mul(ws[x[i]], wt[y[i]]);
      sub(ans, mul(z, z));
    } else
    if (ds[y[i]] + v[i] + dt[x[i]] == ds[t] && max(ds[y[i]], dt[x[i]]) - min(ds[y[i]], dt[x[i]]) <= v[i]) {
      int z = mul(ws[y[i]], wt[x[i]]);
      sub(ans, mul(z, z));
    }
  }
  printf("%d\n", ans);
}
