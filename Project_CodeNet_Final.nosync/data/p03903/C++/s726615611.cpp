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

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

struct Edge {
	int a, b, cost;
	bool operator <(const Edge&e)const {
		return cost < e.cost;
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

	cin >> N >> M;
	vector<Edge>edge(M);
	for (auto &i : edge)cin >> i.a >> i.b >> i.cost;
	sort(edge.begin(), edge.end());
	UnionFind uf(N);
	vector<vector<Edge>>v(N + 1);
	long long int ans = 0;
	for (auto i : edge) {
		if (uf.Check_Same(i.a, i.b))continue;
		uf.Unite(i.a, i.b);
		v[i.a].push_back({ i.a,i.b,i.cost });
		v[i.b].push_back({ i.b,i.a,i.cost });
		ans += i.cost;
	}
	vector<vector<int>>minus(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		vector<int>used(N + 1);
		queue<int>Q;
		Q.push(i);
		used[i] = 1;
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto j : v[cn]) {
				if (used[j.b])continue;
				//if (minus[i][j.b] < max(minus[i][j.a], j.cost)) {
				minus[i][j.b] = max(minus[i][cn], j.cost);
				used[j.b] = 1;
				Q.push(j.b);
				//}
			}
		}
	}
	cin >> K;
	while (K--) {
		cin >> L >> R;
		cout << ans - minus[L][R] << endl;
	}

	return 0;
}