
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;


struct edge {
	int to;
	long long cost;
	edge(int to_, long long cost_) :
		to(to_), cost(cost_) {}
};
const long long INF = 123456789012345;
using P = pair<long long, int>;
void dijkstra(vector<edge>graph_[], long long dist[], int n_, int s_) {
	priority_queue<P, vector<P>, greater<P>>que;
	que.push({ 0,s_ });
	fill(dist, dist + n_, INF);
	dist[s_] = 0ll;
	while (!que.empty()) {
		auto q = que.top();
		que.pop();
		long long thd = q.first;
		int thv = q.second;
		if (thd > dist[thv])
			continue;
		for (auto ed : graph_[thv]) {
			if (dist[ed.to] > ed.cost + thd) {
				dist[ed.to] = ed.cost + thd;
				que.push({ dist[ed.to],ed.to });
			}
		}
	}
}

vector<edge>graph[123456];
vector<edge>newgr[123456];
int N, M;
int S, T;

LL distS[123456];
LL distT[123456];

const LL MOD = 1000000007;

LL memoS[123456];
LL dpS(int v) {
	if (memoS[v] >= 0)return memoS[v];
	LL res = 0;
	for (auto e : newgr[v]) {
		int u = e.to;
		if (distS[u] < distS[v]) {
			res += dpS(u);
			res %= MOD;
		}
	}
	return memoS[v] = res;
}
LL memoT[123456];
LL dpT(int v) {
	if (memoT[v] >= 0)return memoT[v];
	LL res = 0;
	for (auto e : newgr[v]) {
		int u = e.to;
		if (distT[u] < distT[v]) {
			res += dpT(u);
			res %= MOD;
		}
	}
	return memoT[v] = res;
}

set<int>isall[123456];

int main(void)
{
	cin >> N >> M;
	cin >> S >> T;
	--S; --T;
	for (int i = 0; i < M; ++i) {
		int u, v; LL d;
		cin >> u >> v >> d;
		--u; --v;
		graph[u].push_back({ v,d });
		graph[v].push_back({ u,d });
	}
	dijkstra(graph, distS, N, S);
	dijkstra(graph, distT, N, T);
	LL betw = distS[T];
	for (int v = 0; v < N; ++v) {
		//if (distS[v] + distT[v] == betw && distS[v] * 2 == betw) {
		//	cnt++;
		//}
		for (auto e : graph[v]) {
			int u = e.to;
			if (distS[v] + distT[v] == betw && distS[u] + distT[u] == betw) {
				//if (distS[v] * 2 < betw && distT[u] * 2 < betw) {
				//	++cnt;
				//}
				if (distS[v] + e.cost == distS[u]) {
					if (!isall[v].count(u)) {
						newgr[v].push_back({ u,e.cost });
						newgr[u].push_back({ v,e.cost });
						isall[v].insert(u);
						isall[u].insert(v);
					}
				}
			}
		}
	}
	fill(memoS, memoS + N, -1);
	fill(memoT, memoT + N, -1);
	memoS[S] = 1;
	memoT[T] = 1;
	vector<LL>tame;
	for (int v = 0; v < N; ++v) {
		if (distS[v] + distT[v] == betw && distS[v] * 2 == betw) {
			LL ss = dpS(v);
			LL tt = dpT(v);
			tame.push_back(ss * tt);
			tame.back() %= MOD;
		}
		for (auto e : newgr[v]) {
			int u = e.to;
			if (distS[v] + distT[v] == betw && distS[u] + distT[u] == betw) {
				if (distS[v] * 2 < betw && distT[u] * 2 < betw) {
					LL ss = dpS(v);
					LL tt = dpT(u);
					tame.push_back(ss * tt);
					tame.back() %= MOD;
				}
			}
		}
	}
	LL total = 0;
	LL twosum = 0;
	int M = tame.size();
	for (int i = 0; i < M; ++i) {
		total += tame[i];
		total %= MOD;
		twosum += (tame[i] * tame[i]) % MOD;
		twosum %= MOD;
	}
	LL ans = total * total;
	ans %= MOD;
	ans -= twosum;
	ans += MOD * 3;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}
