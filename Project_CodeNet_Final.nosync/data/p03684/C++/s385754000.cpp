/*
 * 17-06-21_ARC076_D.cpp
 *
 *  Created on: 2017/06/24
 *      Author: ryoma
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

struct UnionFind {
	vector<int> data;
	UnionFind(int size) :
			data(size, -1) {
	}
	bool unionSet(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) {
			if (data[y] < data[x])
				swap(x, y);
			data[x] += data[y];
			data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
			src(src), dst(dst), weight(weight) {
	}
};
bool operator <(const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
			e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
	int n = g.size();
	UnionFind uf(n);
	priority_queue<Edge> Q;
	REP(u, n)
		FOR(e, g[u])
			if (u < e->dst)
				Q.push(*e);

	Weight total = 0;
	Edges F;
	while (F.size() < n - 1 && !Q.empty()) {
		Edge e = Q.top();
		Q.pop();
		if (uf.unionSet(e.src, e.dst)) {
			F.push_back(e);
			total += e.weight;
		}
	}
	return pair<Weight, Edges>(total, F);
}

int N;
pair<int,int> x[100010], y[100010];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> y[i].first;
		x[i].second =y[i].second= i;

	}
	Graph g(N);
	sort(x,x+N);
	sort(y,y+N);
	for(int i=0;i<N-1;i++){
		g[x[i].second].push_back(Edge(x[i].second,x[i+1].second,x[i+1].first-x[i].first));
		g[x[i+1].second].push_back(Edge(x[i+1].second,x[i].second,x[i+1].first-x[i].first));
		g[y[i].second].push_back(Edge(y[i].second,y[i+1].second,y[i+1].first-y[i].first));
		g[y[i+1].second].push_back(Edge(y[i+1].second,y[i].second,y[i+1].first-y[i].first));
	}
	pair<Weight, Edges> ans = minimumSpanningForest(g);
	cout << ans.first << endl;
	return 0;
}
