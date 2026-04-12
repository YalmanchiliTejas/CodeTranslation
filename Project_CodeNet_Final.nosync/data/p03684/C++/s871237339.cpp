#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

struct edge {
  int to; ll cost;
  edge(int t, ll c): to(t), cost(c) {}
};

int n;
vector<edge> G[100001];
ll mincost[100001];
bool used[100001];

ll prim(void) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(mincost, mincost + n, 1e18);
  mincost[0] = 0;
  que.push(P(0, 0));

  ll res = 0;
  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (used[v] || mincost[v] < p.first) continue;

    used[v] = true;
    res += mincost[v];

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (!used[e.to] && mincost[e.to] > e.cost) {
        mincost[e.to] = e.cost;
        que.push(P(mincost[e.to], e.to));
      }
    }
  }
  return res;
}

int main(void) {
  cin >> n;

  vector<P> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i].first >> y[i].first;
    x[i].second = y[i].second = i;
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  for (int i = 0; i < n - 1; i++) {
    G[x[i].second].push_back(edge(x[i + 1].second, x[i + 1].first - x[i].first));
    G[x[i + 1].second].push_back(edge(x[i].second, x[i + 1].first - x[i].first));
    G[y[i].second].push_back(edge(y[i + 1].second, y[i + 1].first - y[i].first));
    G[y[i + 1].second].push_back(edge(y[i].second, y[i + 1].first - y[i].first));
  }

  cout << prim() << endl;
  
  return 0;
}