#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define pb push_back
#define mp make_pair
#define x first
#define p second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;

const int maxn = 200009, MOD = 1e9 + 7;
priority_queue<pli, vector<pli>, greater<pli> > Q;
vector<pii> e[maxn]; LL dis[maxn], dis2[maxn];
int u[maxn], v[maxn], w[maxn], rk[maxn], rk2[maxn];
int vis[maxn], pre[maxn], suf[maxn];
int n, m, s, t, ans;

bool cmp(int a, int b) {
	return dis[a] < dis[b];
}

bool cmp2(int a, int b) {
	return dis2[a] < dis2[b];
}

void Dijkstra(int s, LL d[maxn]) {
	memset(d, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	int u = s; Q.push(mp(0, s)); d[s] = 0;
	while (!Q.empty()) {
		u = Q.top().second; Q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (auto k : e[u])
			if (d[u] + w[k.p] < d[k.x]) {
				d[k.x] = d[u] + w[k.p];
				Q.push(mp(d[k.x], k.x));
			}
	}
}

void solve(int s, LL d[maxn], int f[maxn], int rk[maxn]) {
	int u; f[s] = 1;
	rep (i, 1, n) {
		u = rk[i];
		for (auto k : e[u])
			if (d[u] + w[k.p] == d[k.x])
				f[k.x] = (f[k.x] + f[u]) % MOD;
	}
}

int calc(int x) {
	return 1LL * x * x % MOD;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	rep (i, 1, m) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		e[u[i]].pb(mp(v[i], i)); 
		e[v[i]].pb(mp(u[i], i));
	}
	Dijkstra(s, dis); 
	Dijkstra(t, dis2);
	
	rep (i, 1, n) rk[i] = rk2[i] = i;
	sort(rk+1, rk+n+1, cmp); 
	sort(rk2+1, rk2+n+1, cmp2);
	
	solve(s, dis, pre, rk); 
	solve(t, dis2, suf, rk2);
	
	ans = calc(pre[t]);
	
	//sovle point
	rep (i, 1, n)
		if (dis[i] == dis2[i] && dis[i] * 2 == dis[t])
			ans = (ans + MOD - 1LL * calc(pre[i]) * calc(suf[i]) % MOD) % MOD;
	
	//solve edge
	rep (i, 1, m) {
		if (dis[u[i]] + w[i] == dis[v[i]] && dis2[v[i]] + w[i] == dis2[u[i]] && dis[u[i]] + w[i] + dis2[v[i]] == dis[t]) {
			if (max(dis[u[i]], dis2[v[i]]) < min(dis[v[i]], dis2[u[i]]))
				ans = (ans + MOD - 1LL * calc(pre[u[i]]) * calc(suf[v[i]]) % MOD) % MOD;
		}
		if (dis[v[i]] + w[i] == dis[u[i]] && dis2[u[i]] + w[i] == dis2[v[i]] && dis[v[i]] + w[i] + dis2[u[i]] == dis[t]) {
			swap(u[i], v[i]);
			if (max(dis[u[i]], dis2[v[i]]) < min(dis[v[i]], dis2[u[i]]))
				ans = (ans + MOD - 1LL * calc(pre[u[i]]) * calc(suf[v[i]]) % MOD) % MOD;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}