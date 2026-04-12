#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#define int long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用

using namespace std;
using namespace std;

std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

int a[200001];
int mapdata[200001];
int ans = 0;

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

struct uf_tree {
	std::vector<int> parent;
	int __size;
	uf_tree(int size_) : parent(size_, -1), __size(size_) {}
	void unite(int x, int y) {
		if ((x = find(x)) != (y = find(y))) {
			if (parent[y] < parent[x]) std::swap(x, y);
			parent[x] += parent[y];
			parent[y] = x;
			__size--;
		}
	}
	bool is_same(int x, int y) { return find(x) == find(y); }
	int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
	int size(int x) { return -parent[find(x)]; }
	int size() { return __size; }
};

std::pair<Weight, Edges> kruskal(Graph const &g) {
	uf_tree uf(g.size());
	Edges es;
	for (auto &adj : g)
		for (auto &e : adj) es.emplace_back(e);
	std::sort(es.begin(), es.end(),
		[](const Edge &e, const Edge &f) { return e.weight < f.weight; });
	Weight total = 0;
	Edges T;
	for (auto &e : es)
		if (!uf.is_same(e.src, e.dst)) {
			T.push_back(e);
			total += e.weight;
			uf.unite(e.src, e.dst);
		}
	return std::make_pair(total, T);
}

vector<pair<int, int>> xy, yx;
map<pair<int, int>, int> posToNum;

int cost(pair<int, int> one, pair<int, int> two) {
	return min(abs(one.first - two.first), abs(one.second - two.second));
}

signed main() {
	int N, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int inX, inY;
		cin >> inX >> inY;
		xy.push_back(make_pair(inX, inY));
		yx.push_back(make_pair(inY, inX));
		pair<int, int> p = make_pair(inX, inY);
		posToNum[p] = i;
	}
	sort(xy.begin(), xy.end());
	sort(yx.begin(), yx.end());
	Graph g(100001);
	for (int i = 0; i < N-1; i++) {
		add_edge(g, posToNum[xy[i]], posToNum[xy[i + 1]], cost(xy[i], xy[i + 1]));
		auto yx_xy1 = make_pair(yx[i].second, yx[i].first), yx_xy2 = make_pair(yx[i + 1].second, yx[i + 1].first);
		add_edge(g, posToNum[yx_xy1], posToNum[yx_xy2], cost(yx_xy1, yx_xy2));
	}
	cout << kruskal(g).first << "\n";


	return 0;
}