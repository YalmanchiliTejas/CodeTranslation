#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<map>
#include<complex>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

//geometry
typedef long double ld;
typedef complex<ld> Point;
const ld pi = acos(-1.0);
ld dot(Point a, Point b) { return real(conj(a)*b); }
ld cross(Point a, Point b) { return imag(conj(a)*b); }

struct Line {
	Point a, b;
};

Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a;
	Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

void solve() {
	int n, k; cin >> n >> k;

	ld theta = 2 * pi / (ld)n;


	Point o = { 0,1 };
	Point a = Point{ cos(k*theta),-sin(k*theta) }*o;
	Line l1 = { o,a };
	Point p = Point{ cos(theta),-sin(theta) }*o;
	Point b = Point{ cos(k*theta),sin(k*theta) }*p;
	Line l2 = { p,b };
	Point c = is_ll(l1, l2);
	ld x = real(c);
	ld ans = x * n;
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	solve();
	//stop
		return 0;
}

