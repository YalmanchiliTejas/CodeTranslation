#include <bits/stdc++.h>

#define int long long
#define double long double

using namespace std;

template<class T> string tostr(T x) { stringstream o; o << x; return o.str(); }
template<class T> T sqr(T x) { return x*x; }
template<class T> T mypow(T x, int n) { T r = 1; while (n > 0) { if (n & 1)r = r*x; x = x*x; n >>= 1; }return r; }

int toint(string s) { int v; stringstream i(s); i >> v; return v; }
bool check(int x, int y, int w, int h) { return x >= 0 && y >= 0 && w > x && h > y; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

#define REP(i,a,b)	for(int (i) = (a);i < (b);(i)++)
#define rep(i,n)	REP(i,0,n)
#define PER(i,a,b)	for(int (i) = (a-1);i >= (b);(i)--)
#define per(i,n)	PER(i,n,0)
#define each(i,n)	for(auto &i : n)
#define clr(a)		memset((a), 0 ,sizeof(a))
#define mclr(a)		memset((a), -1 ,sizeof(a))
#define all(a)		(a).begin(),(a).end()
#define dump(val) 	cerr << #val " = " << val << endl;
#define dum(val)	cerr << #val " = " << val;
#define FILL(a,v)	fill(a,a+sizeof(a)/sizeof(*a),v)

const int dx[8] = { +1,+0,-1,+0,+1,+1,-1,-1 };
const int dy[8] = { +0,-1,+0,+1,-1,+1,-1,+1 };
const int mod = 1e9 + 7;
const int INF = 1e9;

typedef tuple<int,int,int> T;

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool set(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
		if (data[y] < data[x]) swap(x, y);
		data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool find(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

signed main() {

	int n;
	cin >> n;

	vector<T> xp(n), yp(n);

	rep(i,n){
		int x, y;
		cin >> x >> y;
		xp[i] = tie(x, y, i);
		yp[i] = tie(y, x, i);
	}

	sort(all(xp));
	sort(all(yp));
	
	vector<T> e;
	rep(i,n-1){
		int x0 = get<0>(xp[i]);
		int x1 = get<0>(xp[i+1]);

		int i0 = get<2>(xp[i]);
		int i1 = get<2>(xp[i+1]);

		e.push_back(T(x1-x0,i0,i1));
	}
	rep(i,n-1){
		int y0 = get<0>(yp[i]);
		int y1 = get<0>(yp[i+1]);

		int i0 = get<2>(yp[i]);
		int i1 = get<2>(yp[i+1]);

		e.push_back(T(y1-y0,i0,i1));
	}

	UnionFind uf(n);

	int ans = 0;
	sort(all(e));
	rep(i, e.size()){

		int t0 = get<1>(e[i]);
		int t1 = get<2>(e[i]);

		if(uf.find(t0, t1) == false){
			uf.set(t0, t1);
			ans += get<0>(e[i]);
		}
	}

	cout << ans << endl;

	return 0;
}
