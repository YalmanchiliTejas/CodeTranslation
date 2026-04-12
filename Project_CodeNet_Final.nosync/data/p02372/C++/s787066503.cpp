#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

using Weight = int;
struct Edge {
	int s; //source
	int d; //destination
	Weight w; //weight
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w) {};
	bool operator<(const Edge &e)const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

enum { WHITE, GRAY, BLACK };
vector<int> dijkstra(const Graph &g, int s, vector<Weight> &dist) {
	using State = tuple<Weight, int, int>; //?§?????????????????°?????????? ??? ???
	priority_queue<State, vector<State>, greater<State>> PQ;
	int n = g.size();
	vector<int> color(n, WHITE);
	vector<int> prev(n, -1);
	dist.assign(n, INF);
	dist[s] = 0; PQ.emplace(0, s, -1); color[s] = GRAY; //?§????
	while (PQ.size()) {
		Weight d; int v, u;
		tie(d, v, u) = PQ.top(); PQ.pop(); //dist???????°???¨??????State???????????????
		if (dist[v] < d)continue; //?????§???????????§???????????°??????
		color[v] = BLACK;
		prev[v] = u;
		for (auto &e : g[v]) { //??£??\????????????????????¨????????????		
			if (color[e.d] == BLACK)continue; //??¢?´¢????????????
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				PQ.emplace(dist[e.d], e.d, v);
				color[e.d] = GRAY;
			}
		}
	}
	return prev;
}

//??¨?????´???
Edge diameter(const Graph &g, int s = 0) {
	vector<Weight> dist;
	dijkstra(g, s, dist);
	int n = g.size(), u = -1, v = -1;
	for (int i = 0; i < n; i++) if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
	dijkstra(g, u, dist);
	for (int i = 0; i < n; i++) if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
	Weight d = dist[v];
	if (u > v) swap(u, v);
	return Edge(u, v, d);
}

signed main() {
	int n; cin >> n;
	Graph g(n);
	rep(i, 0, n-1) {
		int s, t, w; cin >> s >> t >> w;
		g[s].emplace_back(s, t, w);
		g[t].emplace_back(t, s, w);
	}
	Edge e = diameter(g);
	vector<Weight> dist1, dist2;
	dijkstra(g, e.s, dist1);
	dijkstra(g, e.d, dist2);
	rep(i, 0, n) {
		cout << max(dist1[i], dist2[i]) << endl;
	}
	return 0;
}