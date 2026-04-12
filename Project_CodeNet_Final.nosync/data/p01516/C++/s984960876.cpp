#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define lengthof(array) (sizeof(array) / sizeof(*array))
#define dump(a) (cerr << (#a) << " = " << (a) << endl)
#define FOR(it,c) for(__typeof((c).begin())it=(c).begin(); it!=(c).end();++it)
#define RFOR(it,c) for(__typeof((c).rbegin())it=(c).rbegin(); it!=(c).rend();++it)

template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
	return os;
}

const double EPS = 1e-9;

struct point {
	double x, y;
	point():x(0), y(0) {}
	point(double x, double y):x(x), y(y) {}
	point(const point& p):x(p.x), y(p.y) {}

	point operator+ (const point& p) const {
		return point(x + p.x, y + p.y);
	}

	point operator- (const point& p) const {
		return point(x - p.x, y - p.y);
	}

	point operator* (const double s) const {
		return point(x * s, y * s);
	}

	point operator* (const point& p) const {
		return point(x * p.x - y * p.y, x * p.y + y * p.x);
	}

	point operator/ (const double s) const {
		return point(x / s, y / s);
	}

	bool operator< (const point& p) const {
		return x + EPS < p.x || abs(x - p.x) < EPS && y + EPS < p.y;
	}

	bool operator== (const point& p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

point rotate90(const point& p) {
	return point(-p.y, p.x);
}

point rotate(const point& p, const double theta) {
	const double s = sin(theta), c = cos(theta);
	return point(c * p.x - s * p.y, s * p.x + c * p.y);
}

double angle(const point& p) {
	return atan2(p.y, p.x);
}

double abs(const point& p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

double norm(const point& p) {
	return p.x * p.x + p.y * p.y;
}

double dot(const point& l, const point& r) {
	return l.x * r.x + l.y * r.y;
}

double cross(const point& l, const point& r) {
	return l.x * r.y - l.y * r.x;
}

struct line {
	point a, b;
	line(point a, point b):a(a), b(b){}
};

struct segment {
	point a, b;
	segment(point a, point b):a(a), b(b){}
};

struct circle {
	point c;
	double r;
	circle(point c, double r):c(c), r(r){}
};

typedef vector<point> polygon;

int ccw(const point& a, point b, point c) {
	b = b - a;
	c = c - a;
	if(cross(b, c) > EPS) return +1; // ccw
	if(cross(b, c) < -EPS) return -1; // cw
	if(dot(b, c) < 0) return +2; // c, a, b 順に一直線上
	if(norm(b) < norm(c)) return -2; // a, b, c 順に一直線上
	return 0; //a, c, b 順で一直線上
}

point projection(const line& l, const point& p) {
	const point dif = l.b - l.a;
	const double tmp = dot(p - l.a, dif) / norm(dif);
	return l.a + dif * tmp;
}

bool intersect(const line& l, const line& m) {
	return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const line& l, const segment& s) {
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

bool intersect(const line& l, const point& p) {
	return abs(ccw(l.a, l.b, p)) != -1;
}

bool intersect(const segment& s, const segment& t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool intersect(const segment& s, const point& p) {
	return ccw(s.a, s.b, p) == 0;
}

bool intersect(const circle& c, const point& p) {
	return abs(c.c - p) <= c.r + EPS;
}

bool intersect(const circle& c, const circle& d) {
	return abs(c.c - d.c) <= c.r + d.r && abs(c.c - d.c) >= abs(c.r - d.r);
}

double dist(const line& l, const point& p) {
	return abs(p - projection(l, p));
}

double dist(const line& l, const line& m) {
	return intersect(l, m) ? 0 : dist(l, m.a);
}

double dist(const line& l, const segment& s) {
	return intersect(l, s) ? 0 : min(dist(l, s.a), dist(l, s.b));
}

double dist(const segment& s, const point& p) {
	const point tmp = projection(line(s.a, s.b), p);
	return intersect(s, tmp) ? abs(tmp - p) : min(abs(s.a - p), abs(s.b - p));
}

double dist(const segment& s, const segment& t) {
	if(intersect(s, t))
		return 0;
	return min(min(dist(s, t.a), dist(s, t.b)), min(dist(t, s.a), dist(t, s.b)));
}

point crosspoint(const line& l, const line& m) {
	const double tmp = cross(l.b - l.a, m.b - m.a);
	if(abs(tmp) < EPS) // 平行
		return l.a;
	return l.a + (l.b - l.a) * cross(m.b - m.a, m.b - l.a) * (1.0 / tmp);
}

point crosspoint(const segment& s, const segment& t) {
	if(!intersect(s, t)) // 交点を持たない
		return s.a; // 用改善

	const double tmp = cross(s.b - s.a, t.b - t.a);
	if(abs(tmp) < EPS) { // 一直線上
		if(intersect(s, t.a)) return t.a;
		if(intersect(s, t.b)) return t.b;
		if(intersect(t, s.a)) return s.a;
		return s.b;
	}

	return s.a + (s.b - s.a) * cross(s.b - s.a, s.b - t.a) * (1.0 / tmp);
}

vector<point> crosspoint(const circle &c, const circle& d) {
	vector<point> res;
	if(abs(c.c - d.c) < EPS) // 中心の座標が同じ
		return res;

	const double tmp = abs(c.c - d.c);
	const double rc = (tmp * tmp + c.r * c.r - d.r * d.r) / (tmp + tmp);
	const double rs = sqrt(c.r * c.r - rc * rc);
	const point diff = (d.c - c.c) / tmp;
	res.push_back(point(c.c + diff * point(rc, rs)));
	res.push_back(point(c.c + diff * point(rc, -rs)));
	return res;
}

vector<point> crosspoint(const circle& c, const line& l) {
	vector<point> res;
	const point h = projection(l, c.c);
	const double d = abs(h - c.c);
	if(d > c.r - EPS) {
		res.push_back(h);
	}
	else if(d <= c.r - EPS) {
		point v = l.b - l.a;
		v = v * sqrt(c.r * c.r - d * d) / abs(v);
		res.push_back(h + v);
		res.push_back(h - v);
	}

	return res;
}

vector<point> crosspoint(const circle& c, const segment& s) {
	vector<point> res;
	vector<point> tmp = crosspoint(c, line(s.a, s.b));
	for(int i = 0; i < tmp.size(); ++i)
		if(intersect(s, tmp[i]))
			res.push_back(tmp[i]);

	return res;
}

const double alpha = 72.0 / 180.0 * M_PI;
struct star {
	vector<segment> seg;
	star(int x, int y, int a, int r) {
		const point s(r, 0);
		const point m(x, y);
		const double aa = a * M_PI / 180.0;
		for(int i = 0; i < 5; ++i) {
			double theta = aa + i * 2 * M_PI / 5.0 + M_PI / 2.0;
			const point p = rotate(s, theta) + m;
			theta = aa + (i + 2) * 2 * M_PI / 5.0 + M_PI / 2.0;
			const point q = rotate(s, theta) + m;
			seg.push_back(segment(p, q));
		}
	}
};

const double INF = 10000.0;

double dist(const star& s, const star& t) {
	double res = INF;
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			chmin(res, dist(s.seg[i], t.seg[j]));

	return res;
}

int n;
double mat[100][100];
double dijkstra(const int s, const int t) {
	vector<double> d(n, INF);
	vector<bool> used(n, false);
	d[s] = 0;

	for(;;) {
		int v = -1;
		for(int u = 0; u < n; ++u)
			if(!used[u] && (v == -1 || d[u] < d[v]))
				v = u;

		if(v == t)
			return d[t];

		used[v] = true;
		for(int u = 0; u < n; ++u)
			chmin(d[u], d[v] + mat[v][u]);
	}
}


int main() {
	for(int m, l; scanf("%d %d %d", &n, &m, &l), n;) {
		--m; --l;
		vector<star> stars;
		stars.reserve(n);

		for(int i = 0; i < n; ++i) {
			int x, y, a, r;
			scanf("%d %d %d %d", &x, &y, &a, &r);
			stars.push_back(star(x, y, a, r));
		}

		fill(mat[0], mat[0] + lengthof(mat), 0.0);
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j)
				mat[i][j] = mat[j][i] = dist(stars[i], stars[j]);

		printf("%.20lf\n", dijkstra(m, l));
	}

	return EXIT_SUCCESS;
}