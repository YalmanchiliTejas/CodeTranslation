#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <climits>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

#define MOD (int64)1000000007

using int32 = std::int_fast64_t;
using int64 = std::int_fast64_t;
using uint32 = std::int_fast64_t;
using uint64 = std::int_fast64_t;
uint32 n, m, s, t;
#define SIZ 100003
struct edge {
	uint32 to;
	uint64 cost;
};
std::vector<edge> G[SIZ];

int64 minus(int64 a, int64 b) {
	return (a >= b) ? (a - b) : (a + MOD - b);
}

using P = std::pair<uint64, uint32>;
int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
#define INF UINT_FAST64_MAX/4
	std::cin >> n >> m >> s >> t;
	--s;--t;
	std::vector<uint32> u(m), v(m);
	std::vector<uint64> d(m);
	for (uint32 i = 0;i < m;++i) {
		std::cin >> u[i] >> v[i] >> d[i];
		--u[i];--v[i];
		G[u[i]].push_back({ v[i],d[i] });
		G[v[i]].push_back({ u[i],d[i] });
	}
	std::priority_queue<P, std::vector<P>, std::greater<P>> Q;
	std::vector<uint64> pas(n, 0),pat(n,0), ds(n, INF), dt(n, INF);
	ds[s] = 0;
	dt[t] = 0;
	pas[s] = 1;
	pat[t] = 1;
	Q.push(P(0, s));
	while (!Q.empty()) {
		P p = Q.top();Q.pop();
		uint32 vte = p.second;
		if (ds[vte] < p.first) continue;
		for (uint32 i = 0;i < G[vte].size();++i) {
			edge e = G[vte][i];
			if (ds[e.to] > ds[vte] + e.cost) {
				ds[e.to] = ds[vte] + e.cost;
				pas[e.to] = pas[vte];
				Q.push(P(ds[e.to], e.to));
			}
			else if (ds[e.to] == ds[vte] + e.cost) {
				pas[e.to] = (pas[e.to] + pas[vte]) % MOD;
			}
		}
	}
	Q.push(P(0, t));
	while (!Q.empty()) {
		P p = Q.top();Q.pop();
		uint32 vte = p.second;
		if (dt[vte] < p.first) continue;
		for (uint32 i = 0;i < G[vte].size();++i) {
			edge e = G[vte][i];
			if (dt[e.to] > dt[vte] + e.cost) {
				dt[e.to] = dt[vte] + e.cost;
				pat[e.to] = pat[vte];
				Q.push(P(dt[e.to], e.to));
			}
			else if (dt[e.to] == dt[vte] + e.cost) {
				pat[e.to] = (pat[e.to] + pat[vte]) % MOD;
			}
		}
	}
	int64 ans = pat[s] * pas[t] % MOD;
	uint64 len = ds[t];
	for (uint32 i = 0;i < n;++i) {
		if (ds[i] + dt[i] != len) continue;
		if (ds[i] == dt[i]) {
			int64 temp = pas[i] * pat[i] % MOD;
			temp = (temp*temp) % MOD;
			ans = minus(ans, temp);
		}
	}
	for (uint32 i = 0;i < m;++i) {
		if ((ds[u[i]] + dt[u[i]] != len) || (ds[v[i]] + dt[v[i]] != len)) continue;
		uint32 b = u[i], c = v[i];
		if (ds[b] > ds[c]) std::swap(b, c);
		if (ds[b] + d[i] != ds[c]) continue;
		if ((ds[b] * 2 < len)&&(dt[c] * 2 < len)) {
			int64 temp = pas[b] * pat[c] % MOD;
			temp = (temp*temp) % MOD;
			ans = minus(ans, temp);
		}
	}
	std::cout << ans << "\n";
	return 0;
}