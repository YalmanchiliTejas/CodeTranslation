#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define MT make_tuple
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<PII> X(N), Y(N);
	int preX = -1, preY = -1;
	REP(i, N){
		int x, y;
		cin >> x >> y;
		X[i] = MP(x, i);
		Y[i] = MP(y, i);
	}

	SORT(X);
	SORT(Y);

	vector<pair<int, PII>> dX(N - 1), dY(N - 1);
	REP(i, N - 1){
		dX[i] = MP(X[i + 1].first - X[i].first, MP(X[i + 1].second, X[i].second));
		dY[i] = MP(Y[i + 1].first - Y[i].first, MP(Y[i + 1].second, Y[i].second));
	}

	SORT(dX);
	SORT(dY);

	UnionFind uf(N);
	LL ret = 0;

	int ix = 0, iy = 0;
	while(ix < N - 1 || iy < N - 1){
		int dx = 1e9 * 2, dy = 1e9 * 2;
		if(ix < N - 1) dx = dX[ix].first;
		if(iy < N - 1) dy = dY[iy].first;
//		cout << dx << " " << dy << endl;
		int d, a, b;
		if(dx < dy){
			d = dx;
			a = dX[ix].second.first;
			b = dX[ix].second.second;
			ix++;
		}
		else{
			d = dy;
			a = dY[iy].second.first;
			b = dY[iy].second.second;
			iy++;
		}
		if(uf.findSet(a, b)) continue;
		ret += d;
		uf.unionSet(a, b);
	}

	cout << ret << endl;


	return 0;
}
