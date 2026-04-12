#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int nt[N << 1], to[N << 1], head[N], w[N << 1], cnt = 1;

void add(int x, int y, int z) {
  to[++cnt] = y;
  w[cnt] = z;
  nt[cnt] = head[x];
  head[x] = cnt;
}

ll sub(ll x, ll y) {
  return (x -= y) < 0 ? x + mod :x;
}

void Sub(ll &x, ll y) {
  x = sub(x, y);
}

ll mul(ll x, ll y) {
  return x * y % mod;
}

ll add(ll x, ll y) {
  return (x += y) >= mod ? x - mod : x;
}

void Add(ll &x, ll y) {
  x = add(x, y);
}

ll js(ll x) {
  return mul(x, x - 1);
}

ll inf = 1e18;
typedef pair<ll, int> P;
priority_queue<P, vector<P>, greater<P> > q;

void dij(int S, int T, ll dis[], ll fg[]) {
  for(int i = 1; i < N; ++i) dis[i] = inf;
  dis[S] = 0, fg[S] = 1;
  q.push(P(0, S));
  while(!q.empty()) {
    P h = q.top(); q.pop();
    int u = h.second;
    ll d = h.first;
    if(dis[u] < d) continue;
    for(int i = head[u]; i; i = nt[i]) {
      if(dis[to[i]] > d + w[i]) {
        dis[to[i]] = d + w[i];
        fg[to[i]] = fg[u];
        q.push(P(dis[to[i]], to[i]));
      } else if(dis[to[i]] == d + w[i]) {
        Add(fg[to[i]], fg[u]);
      }
    }
  }
}

ll dis[2][N], fg[2][N];
int main() {
  int n, m, S, T;
  cin >> n >> m >> S >> T;
  for(int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z), add(y, x, z);
  }
  dij(S, T, dis[0], fg[0]), dij(T, S, dis[1], fg[1]);
  ll D = dis[0][T], ans = js(fg[0][T]);
  double gg = D / 2.0;
  for(int i = 1; i <= m; ++i) {
    int u = to[i * 2 + 1], v = to[i * 2], val = w[i * 2];
    if(dis[1][u] + val + dis[0][v] == D) {
      ll mn = dis[0][v], mx = mn + val;
      if(mx > gg && mn < gg) {
        Sub(ans, js(mul(fg[1][u], fg[0][v])));
      }
    } else if(dis[1][v] + val + dis[0][u] == D) {
      ll mn = dis[0][u], mx = mn + val;
      if(mx > gg && mn < gg) {
        Sub(ans, js(mul(fg[1][v], fg[0][u])));
      }
    }
  }
  if(D % 2 == 0) {
    for(int i = 1; i <= n; ++i) {
      if(dis[1][i] + dis[0][i] == D && dis[1][i] == D / 2) {
        Sub(ans, js(mul(fg[1][i], fg[0][i])));
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}