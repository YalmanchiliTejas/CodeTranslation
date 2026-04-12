#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0;}
template<class T>bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0;}

using ll = long long;
using R = long double;
const R EPS = 1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r) {return (r > EPS) - (r < -EPS);}
inline R sq(R x) {return sqrt(max(x, 0.0L));}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

// Problem Specific Parameter:

int a, b;
int d[11][11];
int val[11][11];

using edge = tuple<int, int, int>;
vector<edge> graph;

using edge2 = tuple<int, int, char>;
vector<edge2> graph2;

void trial(int alimit, int blimit) {
	graph.clear();
	graph2.clear();
	rep(i, a)rep(j, b) val[i][j] = 1010;

	const int n = alimit * blimit + 1;
	const int s = 0, t = n - 1;

	rep(ca, alimit)rep(cb, blimit) {
		int tmp[11][11];
		rep(x, a)rep(y, b) tmp[x][y] = ca * (x + 1) + cb * (y + 1);
		int cmax = 0;
		rep(x, a)rep(y, b) chmax(cmax, d[x][y] - tmp[x][y]);
		if (cmax > 100) continue;

		rep(x, a)rep(y, b) chmin(val[x][y], tmp[x][y] +  cmax);
		const int idx = blimit * ca + cb;
		graph.push_back(edge(idx, t, cmax));
	}

	rep(ca, alimit - 1) {
		graph2.push_back(edge(blimit * ca, blimit * (ca + 1), 'X'));
	}

	rep(ca, alimit)rep(cb, blimit - 1) {
		graph2.push_back(edge(blimit * ca + cb , blimit * ca + cb + 1, 'Y'));
	}

	rep(x, a)rep(y, b) if (val[x][y] != d[x][y]) return;

	puts("Possible");
	const int m = graph.size() + graph2.size();
	cout << n << " " << m << endl;
	for (auto &it : graph) {
		int a, b, c;
		tie(a, b, c) = it;
		cout << a + 1 << " " << b + 1 << " " << c << endl;
	}

	for (auto &it : graph2) {
		int a, b;
		char  c;
		tie(a, b, c) = it;
		cout << a + 1 << " " << b + 1 << " " << c << endl;
	}

	cout << s + 1 << " " << t + 1 << endl;
	exit(0);
}


int main(void) {
	cin >> a >> b;
	rep(i, a)rep(j, b) cin >> d[i][j];

	rep(one, 1, 18) {
		const int other = 299 / one;
		trial(one, other);
		trial(other, one);
	}


	puts("Impossible");
	return 0;
}