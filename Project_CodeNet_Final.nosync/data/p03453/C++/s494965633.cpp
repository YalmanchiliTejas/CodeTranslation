#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long i64;
const i64 inf = (i64)1.05e17;
const i64 mod = (i64)1e9 + 7;

typedef pair<int, i64> edge;
typedef vector<edge> vertex;
typedef vector<vertex> graph;

vector<i64> compute_dist(int s, graph& g)
{
	vector<i64> dist(g.size(), inf);

	priority_queue<pair<i64,int>> q;
	q.push({-0, s});

	while(!q.empty()) {

		i64 d = -q.top().first;
		int v = q.top().second;
		q.pop();

		if(dist[v] < inf)
			continue;
		dist[v] = d;

		for(auto& e : g[v]) {
			int w = e.first;
			i64 wd = d + e.second;
			if(dist[w] == inf)
				q.push({-wd, w});
		}
	}

	return dist;
}

vector<i64> count_comb(int s, vector<i64>& dist, graph& g)
{
	vector<i64> comb(g.size(), -1);
	comb[s] = 1;

	priority_queue<pair<i64,int>> q;
	q.push({-dist[s], s});

	while(!q.empty()) {

		int v = q.top().second;
		q.pop();

		if(comb[v] > -1 && v != s)
			continue;
		if(v != s)
			comb[v] = 0;

		for(auto& e : g[v]) {

			int w = e.first;
			i64 d = e.second;

			if(comb[w] == -1)
				q.push({-dist[w], w});

			if(dist[w] + d == dist[v])
				comb[v] += comb[w];
		}

		comb[v] = comb[v] % mod;
	}

	return comb;
}

int main()
{
	int n, m;
	int s, t;

	scanf("%d%d%d%d", &n, &m, &s, &t);
	s -= 1;
	t -= 1;

	graph g(n);

	for(int i = 0; i < m; ++i) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u -= 1;
		v -= 1;
		i64 d2 = d * 2;
		g[u].push_back({v, d2});
		g[v].push_back({u, d2});
	}

	vector<i64> s_dist = compute_dist(s, g);
	vector<i64> t_dist = compute_dist(t, g);
	vector<i64> s_comb = count_comb(s, s_dist, g);
	vector<i64> t_comb = count_comb(t, t_dist, g);

	i64 col = 0;
	i64 half = s_dist[t] / 2;
	i64 full = s_dist[t];

	for(int v = 0; v < n; ++v) {


		if(s_dist[v] == half && t_dist[v] == half) {

			// col at vertex v

			i64 sx = s_comb[v];
			i64 tx = t_comb[v];
			i64 x = sx * tx % mod;
			i64 x2 = x * x % mod;
			col = (col + x2) % mod;

			//printf("col at vertex %d: %lld\n", v, x2);
		}

		for(auto& e : g[v]) {

			int w = e.first;
			i64 d = e.second;

			if(s_dist[v] + d + t_dist[w] != full)
				continue;
			if(s_dist[v] >= half || t_dist[w] >= half)
				continue;

			// col at s -> v -> w -> t

			i64 sx = s_comb[v];
			i64 tx = t_comb[w];
			i64 x = sx * tx % mod;
			i64 x2 = x * x % mod;
			col = (col + x2) % mod;

			//printf("col at edge %d -> %d: %lld\n", v, w, x2);
		}
	}

	i64 total = s_comb[t] * s_comb[t] % mod;
	i64 ans = (total + mod - col) % mod;

	printf("%lld\n", ans);

	/*for(int v = 0; v < n; ++v) {
		printf("%d: %lld %lld | %lld %lld\n", v, s_dist[v], t_dist[v], s_comb[v], t_comb[v]);
	}*/

	return 0;
}

/* waffle */
