#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
using pint = pair<int, int>;
using tint = tuple<int, int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef int64_t lint;
constexpr double PI=3.14159265358979323846;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return d[x] = find(d[x]);
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x,y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return find(x) == find(y);}
	int size(int x) { return -d[find(x)];}
};

template<typename T>
struct edge {
	int from, to;
	T cost;
};

template<typename T>
T kruskal(vector<edge<T>> &edges, int V) {
	sort(edges.begin(), edges.end(), [](const edge<T> &a, const edge<T> &b) {
		return a.cost < b.cost;
	});
	UnionFind unionFind(V);
	T res = 0;
	for (edge<T> &e: edges) {
		if (unionFind.unite(e.to, e.from)) {
			res += e.cost;
		}
	}
	return res;
}


int main() {
	int N;
	cin >> N;
	vector<tint> v, r;
	int a=0, b=0, c=0, x, y, z;
	rep(i, N) {
		cin >> x >> y;
		v.push_back(make_tuple(x, y, i));
		r.push_back(make_tuple(y, x, i));
	}
	sort(all(v));
	sort(all(r));
	vector<edge<lint>> e(N*2-2);
	rep(i, N-1) {
		x = get<0>(v.at(i+1)) - get<0>(v.at(i));
		e.at(i).from = get<2>(v.at(i));
		e.at(i).to   = get<2>(v.at(i+1));
		e.at(i).cost = x;
	}
	rep(i, N-1) {
		y = get<0>(r.at(i+1)) - get<0>(r.at(i));
		e.at(i+N-1).from = get<2>(r.at(i));
		e.at(i+N-1).to   = get<2>(r.at(i+1));
		e.at(i+N-1).cost = y;
	}
	cout << kruskal(e, N) << '\n';
}
