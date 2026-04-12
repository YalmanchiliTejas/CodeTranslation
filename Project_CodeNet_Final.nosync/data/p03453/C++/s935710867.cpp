#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const ll INF = 1e16;
const double eps = 1e-6;
const ll MOD = 1000000007;

typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void shortestPath(const Graph &g, int s,
	vector<Weight> &dist, vector<int> &prev) {
	int n = g.size();
	dist.assign(n, INF); dist[s] = 0;
	prev.assign(n, -1);
	priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
	for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
		Edge e = Q.top(); Q.pop();
		if (prev[e.dst] != -1) continue;
		prev[e.dst] = e.src;
		for (auto f = g[e.dst].begin();f != g[e.dst].end();f++) {
			if (dist[f->dst] > e.weight + f->weight) {
				dist[f->dst] = e.weight + f->weight;
				Q.push(Edge(f->src, f->dst, e.weight + f->weight));
			}
		}
	}
}
vector<int> buildPath(const vector<int> &prev, int t) {
	vector<int> path;
	for (int u = t; u >= 0; u = prev[u])
		path.push_back(u);
	reverse(path.begin(), path.end());
	return path;
}



int main() {
	ll N, M;
	ll S, T;
	cin >> N >> M >> S >> T;
	S--; T--;
	Graph g(N);
	Edges es;
	for (int i = 0;i < M;i++) {
		ll U, V, D;
		cin >> U >> V >> D;
		U--; V--;
		es.push_back(Edge(U, V, D));
		g[U].push_back(Edge(U, V, D));
		g[V].push_back(Edge(V, U, D));
	}
	vector<ll> dists; vector<int> prev; vector<ll> distt;
	shortestPath(g, S, dists, prev);
	shortestPath(g, T, distt, prev);
	vector<int> oknode(N, false);
	ll leng = dists[T];
	for (int i = 0;i < N;i++) {
		if (dists[i] + distt[i] == leng)
			oknode[i] = true;
	}
	vector<ll> dp(N, 0);
	dp[S] = 1;
	map<P, ll> mp;
	vector<ll> ans;
	priority_queue<P> todo;
	vector<int> visited(N, false);
	todo.push(P(0, S));
	while (!todo.empty()) {
		ll now = todo.top().second;
		todo.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		for (int i = 0;i < g[now].size();i++) {
			Edge e = g[now][i];
			if (!oknode[e.dst] || dists[now] + e.weight != dists[e.dst])
				continue;
			dp[e.dst] += dp[now];
			dp[e.dst] %= MOD;
			if (dists[e.dst] * 2 == leng) {
				if (mp.find(P(e.dst, e.dst)) != mp.end()) {
					ans[mp[P(e.dst, e.dst)]] += dp[now];
					ans[mp[P(e.dst, e.dst)]] %= MOD;
				}
				else {
					mp[P(e.dst, e.dst)] = ans.size();
					ans.push_back(dp[now]);
				}
			}
			else if(dists[e.dst] * 2 > leng) {
				P ed(min(e.src, e.dst), max(e.src, e.dst));
				if (mp.find(ed) != mp.end()) {
					ans[mp[ed]] += dp[now];
					ans[mp[ed]] %= MOD;
				}
				else {
					mp[ed] = ans.size();
					ans.push_back(dp[now]);
				}
			}
			else  if (dists[e.dst] * 2 < leng) {
				todo.push(P(-dists[e.dst], e.dst));
			}
		}
	}
	dp.assign(N, 0);
	dp[T] = 1;
	vector<ll> ans2(ans.size(), 0);
	visited.assign(N, false);
	todo.push(P(0, T));
	while (!todo.empty()) {
		ll now = todo.top().second;
		todo.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		for (int i = 0;i < g[now].size();i++) {
			Edge e = g[now][i];
			if (!oknode[e.dst] || distt[now] + e.weight != distt[e.dst])
				continue;
			dp[e.dst] += dp[now];
			dp[e.dst] %= MOD;
			if (distt[e.dst] * 2 == leng) {
				if (mp.find(P(e.dst, e.dst)) != mp.end()) {
					ans2[mp[P(e.dst, e.dst)]] += dp[now];
					ans2[mp[P(e.dst, e.dst)]] %= MOD;
				}
				else {
					mp[P(e.dst, e.dst)] = ans2.size();
					ans2.push_back(dp[now]);
				}
			}
			else if (distt[e.dst] * 2 > leng) {
				P ed(min(e.src, e.dst), max(e.src, e.dst));
				if (mp.find(ed) != mp.end()) {
					ans2[mp[ed]] += dp[now];
					ans2[mp[ed]] %= MOD;
				}
				else {
					mp[ed] = ans2.size();
					ans2.push_back(dp[now]);
				}
			}
			else if(distt[e.dst] * 2 < leng){
				todo.push(P(-distt[e.dst], e.dst));
			}
		}
	}
	ll answer = 0;
	ll sum = 0;
	for (int i = 0;i < ans.size();i++) {
		sum += ans[i] * ans2[i];
		sum %= MOD;
	}
	answer = sum * sum;
	for (int i = 0;i < ans.size();i++) {
		ll now = (ans[i] * ans2[i]) % MOD;
		answer -= now * now % MOD;
		answer = (answer + MOD) % MOD;
	}
	cout << answer << endl;
	return 0;
}
/*
8 12
8 5
8 1 1
4 7 1
5 7 1
5 2 3
2 3 1
1 2 2
2 4 1
3 4 1
1 3 2
4 5 2
1 6 1
6 2 1
*/