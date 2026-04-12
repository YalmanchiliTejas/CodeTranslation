#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define pii pair < ll, ll >
#define ok puts("ok");

const int N = (int)1e5 + 6;
const int inf = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

vector < pii > gr[N];
vector < pair < pii, ll > > edge;
ll shdist;
ll d1[N], d2[N], dp1[N], dp2[N], dp[N];
int n, m;
ll ans = 0;

void dijkstra(int s, int t, int id) {
  vector < ll > d(n + 1, linf);
  memset(dp, 0, sizeof(dp));
  set < pii > q;
  q.insert(mk(0, s));
  d[s] = 0;
  dp[s] = 1;
  while (!q.empty()) {
    pii v = *q.begin();
    q.erase(q.begin());
    for (auto to : gr[v.sc]) {
      if (d[v.sc] + to.sc < d[to.fr]) {
        q.erase(mk(d[to.fr], to.fr));
        d[to.fr] = d[v.sc] + to.sc;
        dp[to.fr] = dp[v.sc];
        q.insert(mk(d[to.fr], to.fr));
      } else if (d[v.sc] + to.sc == d[to.fr]) {
        dp[to.fr] += dp[v.sc];
        dp[to.fr] %= inf;
      }
    }
  }
  if (id == 1) {
    for (int i = 1; i <= n; i++) {
      d1[i] = d[i];
      dp1[i] = dp[i];
    }
  } else {
     for (int i = 1; i <= n; i++) {
      d2[i] = d[i];
      dp2[i] = dp[i];
     }
  }
}

ll sqr (ll x) {
  return x * x % inf;
}

ll sub (ll a, ll b) {
  return (a - b + inf) % inf;
}

main () {
  scanf("%d %d", &n, &m);
  int s, t; scanf("%d %d", &s, &t);
  for (int i = 1; i <= m; i++) {
    ll u, v, w; scanf("%lld %lld %lld", &u, &v, &w);
    gr[u].pb(mk(v, w));
    gr[v].pb(mk(u, w));
    edge.pb(mk(mk(u, v), w));
  }
  dijkstra(s, t, 1);
  shdist = d1[t];
  dijkstra(t, s, 2);
  ans = (dp1[t] * dp1[t]) % inf;
  for (int i = 1; i <= n; i++) {
    if (d1[i] == d2[i] && d1[i] + d2[i] == shdist) {
      ans -= (sqr(dp1[i]) * sqr(dp2[i])) % inf;
    }
  }
  for (auto ed : edge) {
    int x = ed.fr.fr, y = ed.fr.sc;
		ll c = ed.sc;
		if(d1[x] > d1[y])
			swap(x, y);
		if(d1[x] + d2[y] + c == d1[t] && ((d1[x] <= d2[y] && d1[x] + c > d2[y]) || (d1[x] > d2[y] && d2[y] + c > d1[x]))){
			ans = sub(ans, (sqr(dp1[x]) * sqr(dp2[y]) % inf));
		}
  }
  printf("%lld", ans % inf);
}
