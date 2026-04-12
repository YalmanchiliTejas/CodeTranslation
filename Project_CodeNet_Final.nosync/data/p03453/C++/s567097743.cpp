#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;

struct node {
	int u;
	ll c;
	node() { }
	node(int u, ll c):u(u), c(c) { }
	inline bool operator<(const node &e)const {
		return c > e.c;
	}
};
struct edge {
	int u, v, c;
	edge() { }
	edge(int u, int v, int c):u(u), v(v), c(c) { }
};
const int N = 2e5 + 10;
const int M = 1e9 + 7;
int n, m, vis[N], s, t;
ll cost[2][N], dp[2][N];
vector<node>adj[N];
vector<edge>e;
void dijkstra(int s, int bit) {
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; ++i)
		cost[bit][i] = 1e18;
	cost[bit][s] = 0;
	dp[bit][s] = 1;
	priority_queue<node>q;
	q.push(node(s, 0));
	node e;
	while(q.size()) {
		e = q.top();
		q.pop();
		if(vis[e.u])
			continue;
		vis[e.u] = 1;
		for(int i = 0; i < adj[e.u].size(); ++i) {
			int v = adj[e.u][i].u;
			ll c = adj[e.u][i].c + e.c;
			if(vis[v] || cost[bit][v] < c)
				continue;
			if(cost[bit][v] == c) {
				dp[bit][v] += dp[bit][e.u];
				if(dp[bit][v] >= M)
					dp[bit][v] -= M;
			}
			else {
				dp[bit][v] = dp[bit][e.u];
				q.push(node(v, c));
				cost[bit][v] = c;
			}
		}
	}
}

int main() {

	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	--s; --t;
	while(m--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u; --v;
		adj[u].push_back(node(v, c));
		adj[v].push_back(node(u, c));
		e.push_back(edge(u, v, c));
	}
	dijkstra(s, 0);
	dijkstra(t, 1);
	ll ans = dp[0][t] * dp[0][t] % M;
	ll D = cost[0][t];
	for(int i = 0; i < n; ++i)
		if(cost[0][i] + cost[1][i] == D && cost[0][i] == cost[1][i]) {
			ll x = dp[0][i] * dp[0][i] % M;
			ll y = dp[1][i] * dp[1][i] % M;
			ans -= x * y % M;
			if(ans < 0)
				ans += M;
		}
	for(int i = 0; i < e.size(); ++i) {
		int u = e[i].u;
		int v = e[i].v;
		int c = e[i].c;
		if(cost[0][u] > cost[0][v]) swap(u, v);
		if(cost[0][u] * 2 < D && cost[1][v] * 2 < D && cost[0][u] + c + cost[1][v] == D) {
			ll x = dp[0][u] * dp[0][u] % M;
			ll y = dp[1][v] * dp[1][v] % M;
			ans -= x * y % M;
			if(ans < 0)
				ans += M;
		}
	}
	printf("%lld\n", ans);


	return 0;
}
