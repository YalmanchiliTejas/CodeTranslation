#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef complex<ld> Point;
typedef pair<int, int> P;

const ld eps = 1e-12, pi = acos(-1.0);

const int inf = 1e9;

namespace std {
	bool operator<(const Point& lhs, const Point& rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}

struct Line {
	Point a, b;
	Line() : a(Point(0,0)), b(Point(0,0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
};

struct Edge {
	int from, to, id;
};

int N;
map<P, int> tbl2;
map<int, int> tbl;
vector< vector<Edge> > G;
vector<Edge> edges;

int to_hash(vector<int> v) {
	int res = 0;
	for (int i = 0; i < N; ++i) {
		res = res * 5 + v[i];
	}
	return res;
}
vector<int> from_hash(int hash) {
	vector<int> res;
	for (int i = 0; i < N; ++i) {
		res.push_back(hash%5);
		hash /= 5;
	}
	reverse( res.begin(), res.end() );
	return res;
}

class UnionFind {
private:
	int sz;
	vector<int> par, h;

public:
	UnionFind(int size) : sz(size) {
		par.resize(sz);
		for (int i = 0; i < sz; ++i) {
			par[i] = i;
		}
		h = vector<int>(sz, 0);
	}
	int root(int n) {
		if (par[n] == n) return n;
		return par[n] = root(par[n]);
	}
	bool isUnited(int a, int b) {
		return root(a) == root(b);
	}
	void unite(int a, int b) {
		int ra = root(a), rb = root(b);
		if (ra == rb) return;
		if (h[ra] < h[rb]) {
			par[ra] = rb;
		}
		else if (h[ra] > h[rb]) {
			par[rb] = ra;
		}
		else {
			par[rb] = ra;
			++h[ra], ++h[rb];
		}
	}
	int hash() {
		vector<int> ids(sz);
		for (int i = 0; i < sz; ++i) {
			int id = root(i);
			if ( h[id] == 0 ) {
				id = 0;
			}
			else {
				++id;
			}
			ids[i] = id;
		}
		map<int, int> m; m[0] = 0;
		for (int i = 0, k = 1; i < ids.size(); ++i) {
			if (m.count(ids[i]) == 0) {
				m[ids[i]] = k++;
			}
		}

		for (int i = 0; i < ids.size(); ++i) {
			ids[i] = m[ids[i]];
		}

		assert( ids == from_hash(to_hash(ids)) );
		return to_hash(ids);
	}
};

int get_id(P p) {
	if ( tbl2.count(p) == 0 ) {
		int id = tbl2.size();
		tbl2[p] = id;
	}
	return tbl2[p];
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
void add_edge(int a, int b, int id) {
//	cout << "add_edge:" << a << " " << b << " " << id << endl;
	G[a].push_back( (Edge){a, b, id} );
	G[b].push_back( (Edge){b, a, id} );
	edges.push_back( (Edge){a, b, id} );
}
struct Data {
	Line l;
	int lid;
	int i, j;
};

ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}
bool isis_lp(Line l, Point p) {
	return (abs(cross(l.b-p, l.a-p)) < eps);
}
void input_and_make_graph() {
	cin >> N;
	G.resize(N);
	vector<Point> v;
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		v.push_back( Point(x, y) );
	}
	vector<Data> dt;
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N; ++j) {
			Point p1 = v[i], p2 = v[j];
			Point m = (p1 + p2) / Point(2, 0);
			Point a = (p2 - p1) * Point(0, 1);
			int vx = a.real(), vy = a.imag();
			int g = gcd(abs(vx), abs(vy)); vx /= g, vy /= g;
			if ((vx < 0) || (vx == 0 && vy < 0)) {
				vx *= -1, vy *= -1;
			}
			int id = get_id( P(vx, vy) );
			Line l(m, m+Point(vx, vy));
			dt.push_back( (Data){l, id, i, j} );
		}
	}
	UnionFind uf(dt.size());
	for (int i = 0; i < dt.size(); ++i) {
		for (int j = i+1; j < dt.size(); ++j) {
			if ( dt[i].lid == dt[j].lid && isis_lp(dt[j].l, dt[i].l.a) ) {
				uf.unite(i, j);
			}
		}
	}
	vector<int> ids(dt.size());
	for (int i = 0; i < dt.size(); ++i) {
		ids[i] = uf.root(i);
	}
	{
		vector<int> temp = ids;
		sort( temp.begin(), temp.end() );
		temp.erase( unique(temp.begin(), temp.end()), temp.end() );
		for (int i = 0; i < temp.size(); ++i) {
			tbl[temp[i]] = i;
//			cout << "-" << i << endl;
		}
	}
	for (int i = 0; i < dt.size(); ++i) {
		add_edge(dt[i].i, dt[i].j, tbl[ids[i]]);
	}
//			add_edge(i, j, edge_id);
}

int dp[2][400000];
vector< vector<int> > bucket(vector<int> v) {
	vector< vector<int> > res(N+1);
	for (int i = 0; i < v.size(); ++i) {
		res[v[i]].push_back(i);
	}
	return res;
}
int merge(int h1, int h2) {
//	cout << "merge" << endl;
/*
	{
		vector<int> v = from_hash(h1);
		cout << "v1:"; for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
	}
	{
		vector<int> v = from_hash(h2);
		cout << "v2:"; for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
		cout << endl;
	}
*/
	vector< vector<int> > v1 = bucket(from_hash(h1));
//	cout << "v1" << endl;
	vector< vector<int> > v2 = bucket(from_hash(h2));
	UnionFind uf(N);
//	cout << "bucket" << endl;
	for (int i = 1; i < v1.size(); ++i) {
		assert( v1[i].size() == 0 || v1[i].size() >= 2 );
		for (int j = 1; j < v1[i].size(); ++j) {
//			cout << v1[i][j-1] << v1[i][j] << endl;
			uf.unite(v1[i][j], v1[i][j-1]);
		}
	}
//	cout << "v2" << endl;
	for (int i = 1; i < v2.size(); ++i) {
		assert( v2[i].size() == 0 || v2[i].size() >= 2 );
		for (int j = 1; j < v2[i].size(); ++j) {
//			cout << v2[i][j-1] << v2[i][j] << endl;
			uf.unite(v2[i][j], v2[i][j-1]);
		}
	}
//	cout << "merge_r" << endl;
	return uf.hash();
}
int solve() {
	vector<int> h(tbl.size());
	{
		vector< vector<Edge> > v(tbl.size());
		for (int i = 0; i < edges.size(); ++i) {
			Edge& e = edges[i];
			v[e.id].push_back(e);
		}
		for (int i = 0; i < v.size(); ++i) {
			UnionFind uf(N);
			for (int j = 0; j < v[i].size(); ++j) {
				Edge& e = v[i][j];
				uf.unite(e.from, e.to);
			}
			h[i] = uf.hash();
		}
	}

	int maxJ = 1;
	for (int i = 0; i < N; ++i) maxJ *= 5;
	--maxJ;

	fill(dp[0], dp[2], inf); dp[0][0] = 0;
	for (int i = 0; i < h.size(); ++i) {
		fill(&dp[i+1&1][0], &dp[i+1&1][400000], inf);
		for (int j = 0; j <= maxJ; ++j) {
			if (dp[i&1][j] == inf) continue;
			dp[i+1&1][j] = min(dp[i+1&1][j], dp[i&1][j]);

//			cout << "!" << i << " " << j << " " << dp[i&1][j] << endl;

			int nj = merge(j, h[i]);
			dp[i+1&1][nj] = min(dp[i+1&1][nj], dp[i&1][j]+1);
//			cout << "h:" << j << " " << h[i] << " " << nj << endl;
		}
	}
	vector<int> a;
	for (int i = 0; i < N; ++i) a.push_back(1);
	return dp[((int)h.size())&1][to_hash(a)];
}
int main() {
	input_and_make_graph();
	cout << solve() << endl;
}