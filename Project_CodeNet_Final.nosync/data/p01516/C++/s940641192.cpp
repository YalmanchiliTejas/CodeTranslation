#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll sq(ll num) { return num*num; }
ll mod_pow(ll x, ll n) {
	if (n == 0)return 1;
	if (n == 1)return x%MOD;
	ll res = sq(mod_pow(x, n / 2));
	res %= MOD;
	if (n % 2 == 1) {
		res *= x;
		res %= MOD;
	}
	return res;
}
ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return a*b % MOD; }

ll n, m, l;

vector<Point> p[110];

namespace std {
	bool operator < (const Point& a, const Point& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const Point& a, const Point& b) {
	return imag(conj(a)*b);
}
double dot(const Point& a, const Point& b) {
	return real(conj(a)*b);
}

struct L : public vector<Point> {
	L(const Point &a, const Point &b) {
		push_back(a); push_back(b);
	}
};

typedef vector<Point> G;

struct C {
	Point p; double r;
	C(const Point &p, double r) : p(p), r(r) { }
};

int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // a → b で半時計方向に折れて b → c
	if (cross(b, c) < 0)   return -1;       // a → b で時計方向に折れて b → c
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;								// a → b で逆を向いて b → c ( または b == c )
}

double dist(Point p) { return abs(p); }//ベクトルpの絶対値
double dist(Point a, Point b) {//2点間の距離
	return abs(a - b);
}

Point rot(Point p, double a) {//aはrad
	double x1 = p.real(), y1 = p.imag();
	return Point(x1*cos(a) - y1*sin(a), x1*sin(a) + y1*cos(a));
}

// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {
	return EQ(dot(a1 - a2, b1 - b2), 0.0);
}
// 2直線の平行判定 : a//b <=> cross(a, b) = 0
bool is_parallel(Point a1, Point a2, Point b1, Point b2) {
	return EQ(cross(a1 - a2, b1 - b2), 0.0);
}

//交差判定
bool intersectLL(const L &l, const L &m) {
	return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || 
		abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;   
}
bool intersectLS(const L &l, const L &s) {
	return cross(l[1] - l[0], s[0] - l[0])*    
		cross(l[1] - l[0], s[1] - l[0]) < EPS; 
}
bool intersectLP(const L &l, const Point &p) {
	return abs(cross(l[1] - p, l[0] - p)) < EPS;
}
bool intersectSS(const L &s, const L &t) {
	return ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) <= 0 &&
		ccw(t[0], t[1], s[0])*ccw(t[0], t[1], s[1]) <= 0;
}
bool intersectSP(const L &s, const Point &p) {
	return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

// 点a,bを通る直線と点cとの距離(cross(x,y)=|x||y|sinθ)
double distanceLP(Point a, Point b, Point c) {
	return abs(cross(b - a, c - a)) / abs(b - a);
}

// 点a,bを端点とする線分と点cとの距離
double distanceSP(Point a, Point b, Point c) {
	if (dot(b - a, c - a) < EPS) return abs(c - a);
	if (dot(a - b, c - b) < EPS) return abs(c - b);
	return distanceLP(a, b, c);
}

// 点a1,a2を端点とする線分と点b1,b2を端点とする線分との距離
double distanceSS(Point a1, Point a2, Point b1, Point b2) {
	L a = L(a1, a2);
	L b = L(b1, b2);
	if (intersectSS(a, b))return 0.0;
	return min(min(distanceSP(a1, a2, b1), distanceSP(a1, a2, b2)),
		min(distanceSP(b1, b2, a1), distanceSP(b1, b2, a2)));
}


class DK {
public:
	struct edge {
		int to;
		double cost;
	};

	double d[100010];
	vector<edge> G[100010];//各頂点からの辺

	void clear() {
		rep(i, 100010)G[i].clear();
	}

	void dijkstra(int start) {
		fill(d, d + 100010, INF);
		d[start] = 0;

		priority_queue<P, vector<P>, greater<P>> que;
		que.push(P(0, start));

		while (!que.empty()) {
			P p = que.top();
			que.pop();
			int v = p.second;
			if (d[v] < p.first)continue;
			for (int i = 0; i < G[v].size(); i++) {
				edge e = G[v][i];
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					que.push(P(d[e.to], e.to));
				}
			}
		}
	}
};

DK dk;

int main() {
	while (cin >> n >> m >> l&&n + m + l) {
		m--; l--;
		rep(i, 110)p[i].clear();
		dk.clear();
		rep(i, n) {
			double x, y, a, r;
			cin >> x >> y >> a >> r;
			Point po = Point(0, r);
			po = rot(po, 2 * PI *a / 360);
			rep(j, 5) {
				p[i].push_back(po + Point(x, y));
				po = rot(po, 2 * PI / 5);
			}
		}
		//rep(i, n) {
		//	rep(j, 5) {
		//		cout << p[i][j].real() << " " << p[i][j].imag() << endl;
		//	}
		//}
		rep(i, n) {
			FOR(j, i + 1, n) {
				double mind = INF;
				rep(k, p[i].size()) {
					rep(l, p[j].size()) {
						mind = min(distanceSS(p[i][k], p[i][(k + 2) % 5],
							p[j][l], p[j][(l + 2) % 5]), mind);
					}
				}
				//cout << mind << endl;
				dk.G[i].push_back({ j,mind });
				dk.G[j].push_back({ i,mind });
			}
		}
		dk.dijkstra(m);
		printf("%.20lf\n", dk.d[l]);
	}
}
