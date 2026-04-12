#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class UnionFind {
private:
	unsigned size_; std::vector<unsigned> par, rank;
public:
	UnionFind() : size_(0), par(std::vector<unsigned>()), rank(std::vector<unsigned>()) {};
	UnionFind(unsigned size__) : size_(size__) {
		par.resize(size_); rank.resize(size_);
		for (unsigned i = 0; i < size_; i++) par[i] = i, rank[i] = 0;
	}
	unsigned size() { return size_; }
	unsigned root(unsigned x) { return par[x] == x ? x : par[x] = root(par[x]); }
	bool same(unsigned x, unsigned y) { return root(x) == root(y); }
	void unite(unsigned x, unsigned y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const UnionFind &u) { return par == u.par; }
	bool operator!=(const UnionFind &u) { return par != u.par; }
};
int n, m, q, a[400000], b[400000], c[400000], dist[5000], D[5000][5000];
vector<pair<int, int>>vec; vector<pair<int, int>>x[5000];
void query(int r1) {
	fill(dist + 1, dist + n + 1, 1299999999);
	queue<int>Q; Q.push(r1); dist[r1] = 0;
	while (!Q.empty()) {
		int a1 = Q.front(); Q.pop();
		for (int i = 0; i < x[a1].size(); i++) {
			if (dist[x[a1][i].first] == 1299999999) {
				dist[x[a1][i].first] = max(dist[a1], x[a1][i].second);
				Q.push(x[a1][i].first);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i]; vec.push_back(make_pair(c[i], i));
	}
	sort(vec.begin(), vec.end());
	UnionFind UF(n + 1); long long sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		int to = vec[i].second;
		if (UF.same(a[to], b[to]) == false) {
			UF.unite(a[to], b[to]); sum += c[to];
			x[a[to]].push_back(make_pair(b[to], c[to]));
			x[b[to]].push_back(make_pair(a[to], c[to]));
		}
	}
	for (int i = 1; i <= n; i++) {
		query(i); for (int j = 1; j <= n; j++)D[i][j] = dist[j];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int p1, p2; cin >> p1 >> p2;
		cout << sum - D[p1][p2] << endl;
	}
	return 0;
}