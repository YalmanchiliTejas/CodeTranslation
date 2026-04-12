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
ll C[1010][1010];

const ll inf = 1LL << 60;

ll Add(ll a, ll b) {
	return min(a + b, inf);
}

int main(void) {

	const int limit = 1000;
	rep(i, limit + 1) {
		rep(j, i + 1) {
			if (j == 0 or j == i)
				C[i][j] = 1LL;
			else
				C[i][j] = Add(C[i - 1][j - 1], C[i - 1][j]);
		}
	}

	ll n;
	cin >> n;

	ll total = 0LL;
	int cmax = 0;

	while (cmax < 650 and C[7 + cmax][7] <= n) cmax++;

	n -= total;
	vector<int> coef(cmax, 0);

	rrep(i, cmax) {
		while (n >= C[7 + i][7]) {
			n -= C[7 + i][7];
			coef[i]++;
		}
	}

	rrep(i, cmax) {
		rep(loop, coef[i]) cout << "F";
		cout << "ESTIVAL";
	}

	cout << endl;

	return 0;
}