#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, INF = 0x3f3f3f3f;

struct Edge {
	int to, res;
	Edge *next;
	Edge () {}
	Edge (int to, int res, Edge *next) : to(to), res(res), next(next) {}
}*head[N], pool[N << 2], *pis = pool, *cur[N];

void AddEdge (int u, int v, int c) {
	head[u] = new (pis++) Edge(v, c, head[u]);
	head[v] = new (pis++) Edge(u, c, head[v]);
}

int s, t, d[N];

int Dfs (int u, int f) {
	if (u == t || f == 0) return f;
	int fellow = 0, D;
	for (Edge *&now = cur[u]; now; now = now -> next) if (d[now -> to] == d[u] + 1 && (D = Dfs(now -> to, min(now -> res, f)))) {
		fellow += D; now -> res -= D;
		(pool + ((now - pool) ^ 1)) -> res += D; f -= D;
		if (!f) break;
	}
	return fellow;
}

queue<int>Q;
bool vis[N];

bool Bfs () {
	memset(vis, 0, sizeof vis);
	Q.push(s); d[s] = 0; vis[s] = 1; int u;
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		for (Edge *now = head[u]; now; now = now -> next) if (now -> res && !vis[now -> to]) {
			d[now -> to] = d[u] + 1;
			vis[now -> to] = 1;
			Q.push(now -> to);
		}
	}
	return vis[t];
}

int n;

void Dfs (int u, int fa, bool o) {
	if (o) AddEdge(s, u, 1); else AddEdge(u, t, 1);
	o ^= 1; for (Edge *now = head[u]; now; now = now -> next) if (now -> to != fa && now -> to != s && now -> to != t) Dfs(now -> to, u, o);
}

int main () {
	scanf("%d", &n); s = n + 1; t = s + 1;
	for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), AddEdge(u, v, 1);
	Dfs(1, 0, 0);
	int fellow = 0;
	while (Bfs()) {
		for (int i = 1; i <= t; ++i) cur[i] = head[i];
		fellow += Dfs(s, INF);
	}
//	printf("%d\n", fellow);
	puts((fellow << 1) == n ? "Second" : "First");
	return 0;
}