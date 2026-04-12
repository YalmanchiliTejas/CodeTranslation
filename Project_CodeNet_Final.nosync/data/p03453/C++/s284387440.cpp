//by bestFy 2018.1
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;

inline ll read() {
	char ch = getchar(); ll x = 0; int op = 1;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') op = -1;
	for(; isdigit(ch); ch = getchar()) x = x*10+ch-'0';
	return x*op;
}
inline void write(ll a) {
	if(a < 0) putchar('-'), a = -a;
	if(a >= 10) write(a/10); putchar('0'+a%10);
}

const int N = 100010, M = 200010;
const int mod = 1e9 + 7;
const ll inf = 1e18;
int n, m, s, t, cnt, cnt2, ans;
int head[N], head2[N], vis[N], f[2][N], in[N];
ll dis[2][N];
struct edge {
	int to, nxt, v;
	edge() {}
	edge(int x, int y, int z) { to = x, nxt = y, v = z; }
}e[M<<1], e2[M<<1];

inline void addedge(int x, int y, int z) { e[++ cnt] = edge(y, head[x], z); head[x] = cnt; }
inline void addedge2(int x, int y, int z) { e2[++ cnt2] = edge(y, head2[x], z); head2[x] = cnt2; }
inline void upd(int &x, int y) { x += y; if(x >= mod) x -= mod; }
inline int sqr(int x) { return (ll)x*x%mod; }
inline void spfa(int p, int s) {
	queue<int> q; q.push(s); for(int i = 1; i <= n; i ++) dis[p][i] = inf; dis[p][s] = 0;
	memset(vis, 0, sizeof vis); vis[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = 0;
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(dis[p][v] > dis[p][u]+e[i].v) {
				dis[p][v] = dis[p][u]+e[i].v;
				if(!vis[v]) {
					vis[v] = 1; q.push(v);
					if(dis[p][q.back()] < dis[p][q.front()]) swap(q.front(), q.back());
				}
			}
		}
	}
}
inline void tp(int p) {
	queue<int> q;
	for(int i = 1; i <= n; i ++) if(!in[i]) { q.push(i); f[p][i] = 1; }
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = head2[u]; i; i = e2[i].nxt) {
			int v = e2[i].to; in[v] --;
			upd(f[p][v], f[p][u]);
			if(!in[v]) q.push(v);
		}
	}
}
int main() {
	n = read(), m = read(), s = read(), t = read();
	for(int i = 1; i <= m; i ++) {
		int x = read(), y = read(), z = read();
		addedge(x, y, z); addedge(y, x, z);
	}
	spfa(0, s); spfa(1, t);//两边spfa分别以s,t为起点跑最短路
	for(int u = 1; u <= n; u ++)
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(dis[0][u]+dis[1][v]+e[i].v == dis[0][t]) { addedge2(u, v, e[i].v); in[v] ++; }
		}
	tp(0); memset(in, 0, sizeof in); cnt2 = 0; memset(head2, 0, sizeof head2);
	for(int u = 1; u <= n; u ++)
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(dis[1][u]+dis[0][v]+e[i].v == dis[0][t]) { addedge2(u, v, e[i].v); in[v] ++; }
		}
	tp(1);//跑拓扑，f[0/1][i]表示从s/t到i的最短路个数
	ans = sqr(f[0][t]);
	for(int u = 1; u <= n; u ++)
		if(dis[0][u]*2 == dis[0][t] && dis[1][u]*2 == dis[1][s]) upd(ans, mod-sqr((ll)f[0][u]*f[1][u]%mod));
	for(int u = 1; u <= n; u ++)
		for(int i = head2[u]; i; i = e2[i].nxt) {
			int v = e2[i].to;
			swap(u, v);
			if(dis[0][u]+dis[1][u] == dis[0][t] && dis[0][v]+dis[1][v] == dis[0][t] && dis[0][u]*2 < dis[0][t] && dis[1][v]*2 < dis[0][t])
				upd(ans, mod-sqr((ll)f[0][u]*f[1][v]%mod));
			swap(u, v);
		}
	write(ans); puts("");
	return 0;
}
/*
3 3
1 3
1 2 1
2 3 1
3 1 2
*/