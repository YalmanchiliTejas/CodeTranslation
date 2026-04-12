#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

class xplace {
public:
	int x;
	int y;
	int node;
	bool operator <(const xplace& xp)const {
		return x < xp.x;
	}
	bool operator >(const xplace& xp)const {
		return x > xp.x;
	}
};

class yplace {
public:
	int x;
	int y;
	int node;
	bool operator <(const yplace& yp)const {
		return y < yp.y;
	}
	bool operator >(const yplace& yp)const {
		return y > yp.y;
	}
};

class Edge {
public:
	int l;
	int r;
	int cost;
	bool operator <(const Edge& e)const {
		return cost < e.cost;
	}
	bool operator >(const Edge& e)const {
		return cost > e.cost;
	}
};

class UnionFind {
	vector<int>parent;
	vector<int>rank;
public:
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return parent[node] = Find(parent[node]);
	}
	void Unite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (rank[u] < rank[v])parent[u] = v;
		else {
			parent[v] = u;
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<xplace>xp;
	vector<yplace>yp;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		xplace x;
		x.node = i;
		x.x = L;
		x.y = R;
		yplace y;
		y.node = i;
		y.x = L;
		y.y = R;
		xp.push_back(x);
		yp.push_back(y);
	}
	sort(xp.begin(), xp.end());
	sort(yp.begin(), yp.end());
	vector<Edge>edge;
	for (int i = 0; i < N - 1; i++) {
		Edge e;
		e.l = xp[i].node;
		e.r = xp[i + 1].node;
		e.cost = min(abs(xp[i].x - xp[i + 1].x), abs(xp[i].y - xp[i + 1].y));
		edge.push_back(e);
		e.l = yp[i].node;
		e.r = yp[i + 1].node;
		e.cost = min(abs(yp[i].x - yp[i + 1].x), abs(yp[i].y - yp[i + 1].y));
		edge.push_back(e);
	}
	sort(edge.begin(), edge.end());
	UnionFind uf(N);
	long long int ans = 0;
	for (auto i : edge) {
		if (uf.Check_Same(i.l, i.r)) {
			continue;
		}
		uf.Unite(i.l, i.r);
		ans += i.cost;
	}
	cout << ans << endl;
	return 0;
}