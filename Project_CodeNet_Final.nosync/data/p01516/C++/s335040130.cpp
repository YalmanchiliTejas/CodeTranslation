#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld eps = 1e-8, pi = acos(-1.0);

bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}

using Point = complex<ld>;
class Line {
public:
	Point a, b;
	Line() : a(0, 0), b(0, 0) {}
	Line(Point _a, Point _b) : a(_a), b(_b) {}
};
ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c) {
	b -= a, c -= a;
	if (cross(b, c) > eps) return 1;
	if (cross(b, c) < -eps) return -1;
	if (dot(b, c) < 0) return 2;
	if (norm(b) < norm(c)) return -2;
	return 0;
}

bool isis_ll(Line l, Line m) {
	return abs(cross(l.b - l.a, m.b - m.a)) > eps;
}

bool isis_ls(Line l, Line s) {
	return (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

bool isis_lp(Line l, Point p) {
	return abs(cross(l.b - p, l.a - p)) < eps;
}

bool isis_sp(Line s, Point p) {
	return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;
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

bool isis_ss(Line s, Line t) {
	if (isis_ll(s, t)) return isis_ls(s, t) && isis_ls(t, s);
	return isis_sp(s, t.a) || isis_sp(s, t.b) || isis_sp(t, s.a);
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
int main()
{
	int N, M, L;
	cout << fixed << setprecision(15);
	cin.sync_with_stdio(false);
	while (cin >> N >> M >> L, N || M || L) {
		vector<vector<ld>> dis(N, vector<ld>(N, 10000000000));
		for (int i = 0; i < N; i++) {
			dis[i][i] = 0;
		}
		vector<vector<Point>> seg(N, vector<Point>(5));
		vector<vector<Line>> segd(N, vector<Line>(5));
		vector<ld> x(N), y(N), a(N), r(N);
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> y[i] >> a[i] >> r[i];
			for (int j = 0; j < 5; j++) {
				seg[i][j] = Point(x[i], y[i]) + Point(cosl((90 + a[i] + 72 * j) / 180.0 * pi), sinl((90 + a[i] + 72 * j) / 180.0 * pi)) * r[i];
			}
			for (int j = 0; j < 5; j++) {
				segd[i][j] = Line(seg[i][j], seg[i][(j + 2) % 5]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int ii = 0; ii < 5; ii++) {
					for (int jj = 0; jj < 5; jj++) {
						dis[j][i] = dis[i][j] = min(dis[j][i], min(dis[i][j], dist_ss(segd[i][ii], segd[j][jj])));
					}
				}
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		cout << dis[M - 1][L - 1] << endl;
	}
	return 0;
}