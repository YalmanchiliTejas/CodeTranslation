#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }



const int MAX_UF = 110000;
struct UnionFind {
	int size_uf;
	int par[MAX_UF];
	int rank[MAX_UF];
	int size_component[MAX_UF];

	UnionFind(int n = 0) { size_uf = n; for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, size_component[i] = 1; }
	void init(int n) { size_uf = n; for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, size_component[i] = 1; }
	int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
	bool issame(int x, int y) { return root(x) == root(y); }
	int size(int x) { return size_component[root(x)]; }

	void connect(int x, int y) {
		x = root(x), y = root(y);
		int sx = size_component[x], sy = size_component[y];
		if (x == y) return;
		int r;
		if (rank[x] < rank[y]) par[x] = y, r = y;
		else { par[y] = x, r = x; if (rank[x] == rank[y]) ++rank[x]; }
		size_component[r] = sx + sy;
	}

	friend ostream& operator << (ostream& s, UnionFind uf) {
		map<int, vector<int> > res;
		for (int i = 0; i < uf.size_uf; ++i) {
			int r = uf.root(i);
			res[r].push_back(i);
		}
		for (map<int, vector<int> >::iterator it = res.begin(); it != res.end(); ++it) {
			s << it->second << endl;
		}
		return s;
	}
} uf;

typedef pair<long long,int> pli;
typedef pair<int,int> pint;
typedef pair<long long, pint> P;

int N;
pli X[110000], Y[110000];
vector<P> D;

int main() {
  while (cin >> N) {
	for (int i = 0; i < N; ++i) {
	  long long x, y;
	  cin >> x >> y;
	  X[i] = pli(x, i);
	  Y[i] = pli(y, i);
	}
	sort(X, X+N);
	sort(Y, Y+N);
    D.clear();
	for (int i = 0; i < N-1; ++i) {
	  long long xdif = X[i+1].first - X[i].first;
	  long long ydif = Y[i+1].first - Y[i].first;
	  D.push_back(P(xdif, pint(X[i].second, X[i+1].second)));
	  D.push_back(P(ydif, pint(Y[i].second, Y[i+1].second)));
	}
	sort(D.begin(), D.end());

	long long res = 0;
	uf.init(N);
	for (int i = 0; i < D.size(); ++i) {
	  long long tmp = D[i].first;
	  int u = D[i].second.first;
	  int v = D[i].second.second;
	  if (uf.issame(u, v)) continue;
	  else {
		res += tmp;
		uf.connect(u, v);
	  }
	}
	cout << res << endl;
  }
}














