#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define SZ 200005
#define INF 100000000000000LL
typedef long long ll;
typedef pair<ll, int> P;

struct edge
{
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};

int N, M;
vector<ll> dist(SZ), path(SZ);
vector<edge> E[SZ];

void dijkstra(int s)
{
  rep(i, N)
  {
    dist[i] = INF;
    path[i] = 0;
  }
  dist[s] = 0;
  path[s] = 1;

  priority_queue<P, vector<P>, greater<P>> Q;
  Q.push(P(0, s));

  while (!Q.empty())
  {
    P p = Q.top();
    Q.pop();

    int u = p.second;
    if (dist[u] < p.first)
      continue;

    rep(i, E[u].size())
    {
      edge e = E[u][i];
      if (dist[e.to] > dist[u] + e.cost)
      {
        dist[e.to] = dist[u] + e.cost;
        Q.push(P(dist[e.to], e.to));
        path[e.to] = path[u];
      }
      else if (dist[e.to] == dist[u] + e.cost)
      {
        path[e.to] += path[u];
        if (path[e.to] >= MOD)
          path[e.to] -= MOD;
      }
    }
  }
}

int main()
{
  int S, T;
  scanf("%d%d%d%d", &N, &M, &S, &T);
  S--, T--;
  rep(i, M)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    E[a].push_back(edge(b, c));
    E[b].push_back(edge(a, c));
  }

  dijkstra(S);
  vector<ll> ds(dist);
  vector<ll> ps(path);
  dijkstra(T);
  vector<ll> dt(dist);
  vector<ll> pt(path);

  ll ans = ps[T] * pt[S] % MOD;
  ll len = ds[T];

  rep(i, N)
  {
    if (ds[i] + dt[i] == len && ds[i] == dt[i])
    {
      ll ex = ps[i] * pt[i] % MOD;
      ex = ex * ex % MOD;
      ans -= ex;
      if (ans < 0)
        ans += MOD;
    }
  }

  rep(i, N)
  {
    for (auto p : E[i])
    {
      int j = p.to;
      if (ds[i] + dt[j] + p.cost == len)
      {
        if (ds[i] * 2 < len && dt[j] * 2 < len)
        {
          ll ex = ps[i] * pt[j] % MOD;
          ex = ex * ex % MOD;
          ans -= ex;
          if (ans < 0)
            ans += MOD;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
