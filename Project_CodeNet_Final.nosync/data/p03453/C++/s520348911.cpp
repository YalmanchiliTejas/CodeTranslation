#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int N = 1e5 + 5, P = 1e9 + 7;
struct edge {
	int nxt, to, w;
} e[N << 2];
int n, m, cnt = 1, s, t;
ll ans;
int h[N], vis[N];
ll ds[N], dt[N], ways[N], wayt[N];
void dj(int s, ll *d, ll *way) {
	for(int i = 1; i <= n; ++i) {
		d[i] = 1e18;
		vis[i] = 0;
	}
	d[s] = 0;
	way[s] = 1;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(make_pair(0, s));
	while(!q.empty()) {
		pii o = q.top();
		q.pop();
		int u = o.second;
		if(vis[u]) {
			continue;
		}
		vis[u] = 1;
		for(int i = h[u]; i; i = e[i].nxt) {
			ll tmp = d[u] + e[i].w;
			if(tmp < d[e[i].to]) {
				d[e[i].to] = tmp;
				way[e[i].to] = 0;
				q.push(make_pair(d[e[i].to], e[i].to));
			}
			if(tmp == d[e[i].to]) {
				way[e[i].to] = (way[u] + way[e[i].to]) % P;
			}
		}
	}
}
void link(int u, int v, int w) {
	e[++cnt].nxt = h[u];
	h[u] = cnt;
	e[cnt].to = v;
	e[cnt].w = w;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		link(u, v, w);
		link(v, u, w);
	}
	dj(s, ds, ways);
	dj(t, dt, wayt);
	ans = ways[t] * ways[t] % P;
	for(int i = 1; i <= n; ++i) {
		if(ds[i] * 2 == ds[t] && ds[i] + dt[i] == ds[t]) {
			ans = ((ans - ways[i] * ways[i] % P * wayt[i] % P * wayt[i] % P) % P + P) % P;
		}
	}  
	for(int i = 1; i <= n; ++i) {
		for(int j = h[i]; j; j = e[j].nxt) {
			if(ds[i] + dt[e[j].to] + e[j].w == ds[t]) {
				if(ds[i] * 2 < ds[t] && dt[e[j].to] * 2 < ds[t]) {
					ans = ((ans - ways[i] * ways[i] % P * wayt[e[j].to] % P * wayt[e[j].to] % P) % P + P) % P;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}