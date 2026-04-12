#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;


// todo: inf = 1e18
const ll N = 1e5 + 5, MOD = 1e9 + 7, inf = 1000000LL * 1000000LL * 100LL + 10;
int n, m, s, t, ans;
ll dis[2][N];
int cnt[2][N];
vector <pii> G[N];
priority_queue <pii, vector <pii>, greater <pii> > PQ;
bool mark[N];

int _sum (int a, int b) {
	int c = a + b;
	if (MOD <= c)
		c -= MOD;
	return c;
}

int _sub (int a, int b) {
	int c = a - b;
	if (c < 0)
		c += MOD;
	return c;
}

int _mul (int a, int b) {
	int c = 1LL * a * b % MOD;
	return c;
}

void input() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	s--, t--;

	for (int i = 0; i < m; i++) {
		int v, u, w;
		scanf("%d %d %d", &v, &u, &w);
		v--, u--;

		G[v].push_back({u, w});
		G[u].push_back({v, w});
	}
}

void dijkstra (int id, int v) {
	for (int i = 0; i < n; i++) {
		dis[id][i] = inf;
		mark[i] = false;
	}
	dis[id][v] = 0;
	cnt[id][v] = 1;
	PQ.push({0, v});

	while (PQ.size()) {
		int ver = PQ.top().second;
		PQ.pop();

		if (mark[ver])
			continue;
		mark[ver] = true;

		for (pii u: G[ver]) {
			if (dis[id][ver] + u.second < dis[id][u.first]) {
				dis[id][u.first] = dis[id][ver] + u.second;
				PQ.push({dis[id][u.first], u.first});
				cnt[id][u.first] = 0;
			}
			if (dis[id][ver] + u.second == dis[id][u.first])
				cnt[id][u.first] = _sum(cnt[id][u.first], cnt[id][ver]);	
		}
	}
}

int main() {
	input();
	dijkstra(0, s);
	dijkstra(1, t);
	ans = _mul(cnt[0][t], cnt[0][t]);
	for (int i = 0; i < n; i++)
		if (dis[0][i] + dis[1][i] == dis[0][t] && dis[0][i] == dis[1][i])
			ans = _sub(ans, _mul(_mul(cnt[0][i], cnt[1][i]), _mul(cnt[0][i], cnt[1][i])));
		
	for (int v = 0; v < n; v++)
		for (pii u: G[v])
			if (dis[0][v] + u.second + dis[1][u.first] == dis[0][t]) {
				if (dis[0][v] >= u.second + dis[1][u.first])
					continue;
				if (dis[0][v] + u.second <= dis[1][u.first])
					continue;
				ans = _sub(ans, _mul(_mul(cnt[0][v], cnt[1][u.first]), _mul(cnt[0][v], cnt[1][u.first])));
			}
	cout << ans << "\n";
	return 0;
}