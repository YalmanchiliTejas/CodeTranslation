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
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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

class Lowest_Common_Ancestor {
	vector<vector<int>>parent;
	int height = 0;
	int node;
public:
	vector<int>depth;
	vector<vector<int>>edge;
	Lowest_Common_Ancestor(int num) {
		num++;
		node = num;
		while (num) {
			height++;
			num /= 2;
		}
		parent.resize(height);
		edge.resize(node);
		depth.resize(node);
		for (int i = 0; i < height; i++)parent[i].resize(node);
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Update(int rtnode) {
		queue<int>QQ;
		for (int i = 0; i < node; i++) depth[i] = INT_MAX;
		depth[rtnode] = 0;
		QQ.push(rtnode);
		while (!QQ.empty()) {
			int c = QQ.front();
			for (auto i : edge[c]) {
				if (depth[i] > depth[c] + 1) {
					depth[i] = depth[c] + 1;
					QQ.push(i);
				}
			}
			QQ.pop();
		}
		parent[0][rtnode] = -1;
		for (int i = 0; i < node; i++) {
			for (auto j : edge[i]) {
				if (depth[i] - 1 == depth[j]) {
					parent[0][i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < height - 1; i++) {
			for (int j = 0; j < node; j++) {
				if (parent[i][j] < 0)parent[i + 1][j] = -1;
				else parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
		return;
	}
	int LCA(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 0; i < height; i++) {
			if ((depth[v] - depth[u]) >> i & 1) {
				v = parent[i][v];
			}
		}
		if (u == v)return u;
		for (int i = height - 1; i >= 0; i--) {
			if (parent[i][v] != parent[i][u]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
	int Dist(int u, int v) {
		return depth[u] + depth[v] - depth[LCA(u, v)] * 2;
	}
};

struct Edge {
	int from, to, cost, index;
	bool operator<(const Edge&e)const {
		return make_pair(cost,index) < make_pair(e.cost,e.index);
	}
};

void func(vector<vector<int>>&edge, vector<int>&depth, vector<set<Edge>>&vs, vector<int>&check, vector<long long int>&add, int node = 0) {
	for (auto i : edge[node]) {
		if (depth[i] < depth[node])continue;
		func(edge, depth, vs, check, add, i);
		if (vs[check[node]].size() < vs[check[i]].size()) {
			swap(check[node], check[i]);
		}
		for (auto j : vs[check[i]]) {
			if (vs[check[node]].find(j) == vs[check[node]].end()) {
				vs[check[node]].insert(j);
			}
			else {
				vs[check[node]].erase(j);
			}
		}
	}
	if (vs[check[node]].empty())return;
	add[node] = vs[check[node]].begin()->cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<Edge>edge(M);
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		L--, R--;
		edge[i].from = L, edge[i].to = R, edge[i].cost = K, edge[i].index = i;
	}
	sort(edge.begin(), edge.end());
	UnionFind uf(N);
	Lowest_Common_Ancestor lca(N);
	int sz = N;
	long long int sum = 0;
	for (auto i : edge) {
		if (uf.Check_Same(i.from, i.to))continue;
		sz--;
		sum += i.cost;
		uf.Unite(i.from, i.to);
		lca.Add_Edge(i.from, i.to);
	}
	if (sz > 1) {
		for (int i = 0; i < M; i++) {
			cout << -1 << endl;
		}
		return 0;
	}
	lca.Update(0);
	vector<int>check(N);
	for (int i = 0; i < N; i++) {
		check[i] = i;
	}
	vector<set<Edge>>vs(N);
	vector<long long int>ans(M, -1);
	vector<long long int>add(N, MOD*MOD);
	vector<Edge>t_edge;
	for (auto i : edge) {
		if (lca.Dist(i.from, i.to) == 1) {
			t_edge.push_back(i);
			continue;
		}
		ans[i.index] = sum;
		vs[i.from].insert(i);
		vs[i.to].insert(i);
	}
	func(lca.edge, lca.depth, vs, check, add);
	for (auto i : t_edge) {
		if (lca.depth[i.from] > lca.depth[i.to]) {
			if (add[i.from] != MOD * MOD)add[i.from] -= i.cost;
		}
		else {
			if (add[i.to] != MOD * MOD)add[i.to] -= i.cost;
		}
	}
	for (auto i : t_edge) {
		if (lca.depth[i.from] > lca.depth[i.to]) {
			if (add[i.from] != MOD * MOD)ans[i.index] = sum + add[i.from];
		}
		else {
			if (add[i.to] != MOD * MOD)ans[i.index] = sum + add[i.to];
		}
	}
	for (auto i : ans)cout << i << endl;
}
