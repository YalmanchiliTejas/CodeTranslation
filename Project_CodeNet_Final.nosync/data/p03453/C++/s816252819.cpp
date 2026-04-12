//atcoder arc090 c
#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef std::pair <ll, int> pr;
const ll P = 1e9 + 7;
const ll inf = 10000000000000000ll;
const int N = 1e5 + 54;

int n, m, x[N << 1], y[N << 1], z[N << 1];
ll all, disN;
struct graph {
	int start, head[N], vis[N], cnt;
	ll dp[N], dis[N];
	struct node { int u, v, w; } edge[N << 2];
	inline void init() { memset(head, -1, sizeof head); }
	inline void add(int x, int y, int z) {
		edge[cnt] = (node) {head[x], y, z}; head[x] = cnt++;
		edge[cnt] = (node) {head[y], x, z}; head[y] = cnt++;
	}
	std::priority_queue <pr, std::vector < pr >, std::greater < pr > > q;
	inline void walk() {
		for (int i = 1; i <= n; ++i) dis[i] = inf;
		dis[start] = 0, dp[start] = 1;
		q.push(std::make_pair(0, start));
		while (! q.empty()) {
			int x = q.top().se; ll d = q.top().fi; q.pop();
			if (vis[x] || dis[x] < d) continue;
			vis[x] = 1;
			for (int i = head[x]; ~i; i = edge[i].u) {
				int y = edge[i].v;
				if (dis[y] > d + edge[i].w) dis[y] = d + edge[i].w, dp[y] = dp[x], q.push(std::make_pair(dis[y], y));
				else if (dis[y] == d + edge[i].w) dp[y] = (dp[y] + dp[x]) % P; 
			}
		}
	}
	inline void print() { for (int i = 1; i <= n; ++i) std::cout << dis[i] << ' ' << dp[i] << '\n'; std::cout << "-------+" <<'\n'; }
} g0, g1;


inline void meet_point() {
	for (int i = 1; i <= n; ++i) 
		if (g0.dis[i] == g1.dis[i] && g0.dis[i] + g1.dis[i] == disN) 
			all = all - g0.dp[i] * g0.dp[i] % P * g1.dp[i] % P * g1.dp[i] % P, all = (all + P) % P;
}
inline void meet_edge() {
	for (int i = 1; i <= m; ++i) {
		int u = x[i], v = y[i];
		if (g0.dis[u] + g1.dis[v] + z[i] == disN && g0.dis[u] < disN / 2 && g1.dis[v] < disN / 2) 
			all = all - g0.dp[u] * g0.dp[u] % P * g1.dp[v] % P * g1.dp[v] % P, all = (all + P) % P;
		std::swap(u, v);
		if (g0.dis[u] + g1.dis[v] + z[i] == disN && g0.dis[u] < disN / 2 && g1.dis[v] < disN / 2) 
			all = all - g0.dp[u] * g0.dp[u] % P * g1.dp[v] % P * g1.dp[v] % P, all = (all + P) % P;
	}
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    std::cin >> n >> m >> g0.start >> g1.start;
    g0.init(), g1.init();
    for (int i = 1; i <= m; ++i) std::cin >> x[i] >> y[i] >> z[i], g0.add(x[i], y[i], z[i]), g1.add(x[i], y[i], z[i]);
    g0.walk(), g1.walk();
    all = g0.dp[g1.start] * g0.dp[g1.start] % P;
    disN = g0.dis[g1.start];
	meet_point(), meet_edge();
	std::cout << all << '\n';
	//g0.print(), g1.print();
	return 0;
}
