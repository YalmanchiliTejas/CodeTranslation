#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<cmath>
#include<queue>
#include<tuple>
using namespace std;
class QuickUnionFind {
private:
	int size_; std::vector<int> g; std::vector<std::vector<int> > v;
public:
	QuickUnionFind() : size_(0), g(std::vector<int>()), v(std::vector<std::vector<int> >()) {};
	QuickUnionFind(int size__) : size_(size__) {
		g.resize(size_); v.resize(size_);
		for (int i = 0; i < size_; i++) g[i] = i, v[i] = { i };
	};
	int size() { return size_; }
	int root(int x) { return g[x]; }
	int size(int x) { return v[x].size(); }
	bool same(int x, int y) { return g[x] == g[y]; }
	void unite(int x, int y) {
		x = g[x], y = g[y];
		if (x == y) return;
		if (v[x].size() < v[y].size()) std::swap(x, y);
		v[x].insert(v[x].end(), v[y].begin(), v[y].end());
		for (auto &e : v[y]) g[e] = x;
		v[y].clear();
	}
	std::vector<int> connected(int x) { return v[g[x]]; }
	bool operator==(const QuickUnionFind& u) { return g == u.g; }
	bool operator!=(const QuickUnionFind& u) { return g != u.g; }
};
int n, x[100009], y[100009]; vector<pair<int, int>>X, Y; vector<tuple<int, int, int>>Z;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		X.push_back(make_pair(x[i], i));
		Y.push_back(make_pair(y[i], i));
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	for (int i = 1; i < X.size(); i++)Z.push_back(make_tuple(X[i].first - X[i - 1].first, X[i].second, X[i - 1].second));
	for (int i = 1; i < Y.size(); i++)Z.push_back(make_tuple(Y[i].first - Y[i - 1].first, Y[i].second, Y[i - 1].second));
	sort(Z.begin(), Z.end());
	QuickUnionFind UF(n); long long ret = 0;
	for (int i = 0; i < Z.size(); i++) {
		if (UF.same(get<1>(Z[i]), get<2>(Z[i])) == false) {
			ret += get<0>(Z[i]);
			UF.unite(get<1>(Z[i]), get<2>(Z[i]));
		}
	}
	cout << ret << endl;
	return 0;
}