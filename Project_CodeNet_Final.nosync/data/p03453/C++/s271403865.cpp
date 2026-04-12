#include <bits/stdc++.h>
#define maxn 102333
#define maxm 406666
#define mod 1000000007
using namespace std;

typedef pair<long long, int> pli;

struct Graph {
	
	int n, m;
	int head[maxn], nxt[maxm], to[maxm], len[maxm], ec;
	
	inline void add (int u, int v, int d) {
		nxt[++ec] = head[u], head[u] = ec, to[ec] = v, len[ec] = d;
	}

} G;

void Dijkstra (const Graph &G, int S, long long dist[], bool done[], long long ans[]) {
	const long long INF = 0x3F3F3F3F3F3F3F3F;
	const int N = G.n;
	priority_queue< pli, vector<pli>, greater<pli> > Heap;
	fill(dist + 1, dist + N + 1, INF);
	fill(done + 1, done + N + 1, false);
	fill(ans + 1, ans + N + 1, 0);
	dist[S] = 0;
	ans[S] = 1;
	Heap.push(make_pair(0, S));
	while (!Heap.empty()) {
		int x;
		long long d;
		tie(d, x) = Heap.top();
		Heap.pop();
		if(done[x]) continue;
		done[x] = true;
		for (int e = G.head[x]; e; e = G.nxt[e]) {
			long long dd = d + G.len[e];
			if (dd <= dist[G.to[e]]) {
				if (dd != dist[G.to[e]]) {
					ans[G.to[e]] = 0;
					dist[G.to[e]] = dd;
					Heap.push(make_pair(dd, G.to[e]));
				}
				ans[G.to[e]] += ans[x];
				ans[G.to[e]] %= mod;
			}
		}
	} 
}

bool done[maxn];
long long d1[maxn], d2[maxn];
long long a1[maxn], a2[maxn];

int main () {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	G.n = n, G.m = m;
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		G.add(u, v, d);
		G.add(v, u, d);
	}
	Dijkstra(G, s, d1, done, a1);
	Dijkstra(G, t, d2, done, a2);
	long long ans = a1[t] * a1[t] % mod, L = d1[t];
	for (int i = 1; i <= n; ++i) {
		if (d1[i] * 2 == L && d2[i] * 2 == L) {
			ans += (mod - a1[i] * a2[i] % mod * a1[i] % mod * a2[i] % mod);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int e = G.head[i]; e; e = G.nxt[e]) {
			if (d1[i] * 2 < L && d2[G.to[e]] * 2 < L && d1[i] + G.len[e] + d2[G.to[e]] == L) {
				ans += (mod - a1[i] * a2[G.to[e]] % mod * a1[i] % mod * a2[G.to[e]] % mod);
			}
		}
	}
	ans %= mod;
	printf("%lld", ans);
	return 0;
}