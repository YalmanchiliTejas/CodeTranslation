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
#define EPS (1e-10)
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
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<P> > vvP;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<P, vector<P>, greater<P> > pqlP;
typedef pair<int, pair<int, int> > Edge;
typedef vector<Edge> vE;
typedef priority_queue<Edge, vector<Edge>, greater<Edge> > pqlE;

// ??§?¨???§???
int compress(vector<int> &x, map<int, int> &zip, vi &unzip) {
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	for (int i = 0; i < x.size(); i++) {
		zip[x[i]] = i;
		unzip[i] = x[i];
	}
	return x.size();
}

class UnionFind {
public:
	vector<int> par, rank, _size;
	int num;

	UnionFind(int n) {
		par = vector<int>(n);
		rank = vector<int>(n);
		_size = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
			_size[i] = 1;
		}
		num = n;
	}

	// ??¨??????????±???????
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	// x??¨y????±??????????????????????
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
		num--;
	}

	// x??¨y???????????????????±????????????????
	bool same(int x, int y) {
		return find(x) == find(y);
	}

	int size(int x) {
		return _size[find(x)];
	}
};


int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0)break;

		vi x1(N), y1(N), x2(N), y2(N);
		vi x(2 * N), y(2 * N);
		rep(i, N) {
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			x[2 * i] = x1[i];
			x[2 * i + 1] = x2[i];
			y[2 * i] = y1[i];
			y[2 * i + 1] = y2[i];
		}
		x.push_back(-1);
		y.push_back(-1);
		map<int, int> xzip, yzip;
		vi xunzip(2 * N + 1), yunzip(2 * N + 1);
		int X = compress(x, xzip, xunzip);
		int Y = compress(y, yzip, yunzip);
		rep(i, N) {
			x1[i] = xzip[x1[i]];
			y1[i] = yzip[y1[i]];
			x2[i] = xzip[x2[i]];
			y2[i] = yzip[y2[i]];
		}
		/*
		rep(i, N) {
			cout << x1[i] << " " << y1[i] << " " << x2[i] << " " << y2[i] << " " << endl;
		}
		*/
		UnionFind uf(X*Y);
		rep(i, X) {
			rep(j, Y) {
				// (i,j)??¨(i-1,j)
				if (i != 0) {
					bool flag = true;
					rep(k, N) {
						if (y2[k] <= j && j < y1[k] && (x1[k] == i || x2[k] == i)) {
							flag = false;
							break;
						}
					}
					if (flag) {
						uf.unite(j*X + i, j*X + i - 1);
					}
				}
				// (i,j)??¨(i,j-1)
				if (j != 0) {
					bool flag = true;
					rep(k, N) {
						if (x1[k] <= i && i < x2[k] && (y1[k] == j || y2[k] == j)) {
							flag = false;
							break;
						}
					}
					if (flag) {
						uf.unite(j*X + i, (j - 1)*X + i);
					}
				}
			}
		}
		cout << uf.num << endl;
	}

	return 0;
}