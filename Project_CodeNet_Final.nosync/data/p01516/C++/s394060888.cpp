#include<iostream>
#include<cstdio>
#include<functional>
#include<vector>
#include<algorithm>
#include<complex>
#include<cassert>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);

bool eq(ld a, ld b) {
	return (abs(a - b) < eps);
}

namespace std {
	bool operator<(const Point &lhs, const Point &rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}

Point input_point() {
	ld x, y;
	cin >> x >> y;
	return Point(x, y);
}

ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

class Line {
public:
	Point a, b;
	Line() : a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
};

class Circle {
public:
	Point p;
	ld r;
	Circle() : p(Point(0, 0)), r(0) {}
	Circle(Point p, ld r) : p(p), r(r) {}
};

int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;
	if (cross(b, c) < -eps) return -1;
	if (dot(b, c) < 0) return 2;
	if (norm(b) < norm(c)) return -2;
	return 0;
}

bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}

bool isis_ls(Line l, Line s) {
	return isis_ll(l, s) &&
		(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

bool isis_ss(Line s, Line t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool isis_lp(Line l, Point p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}

bool isis_sp(Line s, Point p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}

ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}


int main() {
	ld n, m, l;
	while (scanf("%Le %Le %Le",&n,&m,&l), n) {
		vector<vector<Line>>star(n, vector<Line>(5));
		for (int i = 0; i < n; i++) {
			ld x, y, a, r;
			cin >> x >> y >> a >> r;
			vector<Point>s(5);
			for (int j = 0; j < 5; j++) {
				s[j] = Point(x + r * sin(-a/180*pi), y + r * cos(a/180*pi));
				a += 144;
			}
			for (int j = 0; j < 4; j++) {
				star[i][j] = Line(s[j], s[j + 1]);
			}
			star[i][4] = Line(s[4], s[0]);
		}
		vector<vector<ld>>cost(n, vector<ld>(n,(ld)0));
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				ld ma=(ld)9999.999999999;
				for (int k = 0; k < 5; k++) {
					for (int li = 0; li < 5; li++) {
						ma =min(ma, dist_ss(star[i][k], star[j][li]));
					}
				}
				cost[i][j] = cost[j][i] = ma;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (cost[j][k] > cost[j][i] + cost[k][i])cost[j][k] = cost[j][i] + cost[k][i];
				}
			}
		}
		printf("%.20Lf\n", cost[m - 1][l - 1]);
	}
}