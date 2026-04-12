#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

typedef long long ll;

bool debug = false;
const int NIL = -1;
const int INF = 1000000000;
const int NUM = 100010;
clock_t START, END;

int V;

struct HeapNode {
	int d, u;
	bool operator < (const HeapNode& rhs) const {
		return d > rhs.d;
	}
};

struct Edge {
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[NUM];
	
	int up[NUM], down_1[NUM], child[NUM], down_2[NUM];

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dfs1(int u, int fa) {
		down_1[u] = down_2[u] = 0;
		for (int i = 0; i < G[u].size(); i++) {
			int v = edges[G[u][i]].to;
			if (v != fa) {
				dfs1(v, u);
				if (down_1[v] + edges[G[u][i]].dist > down_1[u]) {
					down_2[u] = down_1[u];
					down_1[u] = down_1[v] + edges[G[u][i]].dist;
					child[u] = v;
				}
				else if (down_1[v] + edges[G[u][i]].dist > down_2[u])
					down_2[u] = down_1[v] + edges[G[u][i]].dist;
			}
		}
	}

	void dfs2(int u, int fa) {
		for (int i = 0; i < G[u].size(); i++) {
			int v = edges[G[u][i]].to;
			if (v == fa)
				continue;
			if (child[u] != v)
				up[v] = max(up[u] + edges[G[u][i]].dist, down_1[u] + edges[G[u][i]].dist);
			else
				up[v] = max(up[u] + edges[G[u][i]].dist, down_2[u] + edges[G[u][i]].dist);
			dfs2(v, u);
		}
	}
};

Dijkstra solve;

int main(void)
{
	if (debug) {
		START = clock();
		freopen("in29.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int s, t, d;
	cin >> V;
	solve.init(V);
	for (int i = 0; i < V - 1; i++) {
		scanf("%d%d%d", &s, &t, &d);
		solve.AddEdge(s, t, d);
		solve.AddEdge(t, s, d);
	}
	solve.dfs1(0, -1);
	solve.dfs2(0, -1);
	for (int i = 0; i < V; i++)
		cout << max(solve.up[i], solve.down_1[i]) << endl;
	if (debug) {
		END = clock();
		double endtime = (double)(END - START) / 1000;
		printf("total time = %lf s", endtime);
	}
	return 0;
}
