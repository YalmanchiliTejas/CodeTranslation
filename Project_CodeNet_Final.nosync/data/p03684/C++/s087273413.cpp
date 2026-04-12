#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mt make_tuple
#define INF 2000000000
#define INFL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<P> vP;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<double> > vvd;
typedef vector<vector<P> > vvP;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<P, vector<P>, greater<P> > pqlP;
typedef pair<int, pair<int, int> > Edge;
typedef vector<Edge> vE;
typedef priority_queue<Edge, vector<Edge>, greater<Edge> > pqlE;

template<typename T>
using v = vector<T>;


class UnionFind {
public:
	vector<int> par, rank, _size;

	UnionFind(int n) {
		par = vector<int>(n);
		rank = vector<int>(n);
		_size = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
			_size[i] = 1;
		}
	}

	// 木の根を求める
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;

		if (rank[x] < rank[y]) {
			par[x] = y;
			_size[y] += _size[x];
		}
		else {
			par[y] = x;
			_size[x] += _size[y];
			if (rank[x] == rank[y])rank[x]++;
		}
	}

	// xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return find(x) == find(y);
	}

	int size(int x) {
		return _size[find(x)];
	}
};

int main() {
	int N;
	cin >> N;
	vP x(N), y(N);
	rep(i, N) {
		int a, b;
		cin >> a >> b;
		x[i] = mp(a, i);
		y[i] = mp(b, i);
	}
	sort(all(x));
	sort(all(y));

	vE xx(N - 1), yy(N - 1);

	rep(i, N - 1) {
		xx[i] = mp(x[i + 1].first - x[i].first, mp(x[i + 1].second, x[i].second));
		yy[i] = mp(y[i + 1].first - y[i].first, mp(y[i + 1].second, y[i].second));
	}
	sort(all(xx));
	sort(all(yy));

	/*
	rep(i, N - 1) {
		cout << xx[i].first << " ";
	}
	cout << endl;
	rep(i, N - 1) {
		cout << yy[i].first << " ";
	}
	cout << endl;
	*/

	ll ans = 0;
	int num = 0, curx = 0, cury = 0;
	UnionFind uf(N);
	while (true) {
		if (curx >= N - 1) {
			if (!uf.same(yy[cury].second.first, yy[cury].second.second)) {
				ans += yy[cury].first;
				uf.unite(yy[cury].second.first, yy[cury].second.second);
				cury++;
				num++;
			}
		}
		else if (cury >= N - 1) {
			if (!uf.same(xx[curx].second.first, xx[curx].second.second)) {
				ans += xx[curx].first;
				uf.unite(xx[curx].second.first, xx[curx].second.second);
				curx++;
				num++;
			}
		}
		else {
			if (xx[curx].first < yy[cury].first) {
				if (!uf.same(xx[curx].second.first, xx[curx].second.second)) {
					ans += xx[curx].first;
					uf.unite(xx[curx].second.first, xx[curx].second.second);
					num++;
				}
				curx++;
			}
			else {
				if (!uf.same(yy[cury].second.first, yy[cury].second.second)) {
					ans += yy[cury].first;
					uf.unite(yy[cury].second.first, yy[cury].second.second);
					num++;
				}
				cury++;
			}
		}
		if (num >= N - 1)break;
	}

	cout << ans << endl;

	return 0;
}