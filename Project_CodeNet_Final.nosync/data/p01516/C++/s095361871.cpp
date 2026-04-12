// *template

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

// *define class

typedef double Real;
constexpr Real EPS = 1e-8;
const Real PI = acos((Real)-1.0);
int sign(Real d) { return d > EPS ? 1 : d < -EPS ? -1 : 0; }

struct Point {
	Real x, y;
	Point(Real x_ = 0, Real y_ = 0):x(x_), y(y_) {}
	inline Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
	inline Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
	inline Point operator*(Real s) const { return Point(x * s, y * s); }
	inline Point operator/(Real s) const { return Point(x / s, y / s); }
	inline bool operator<(const Point &p) const { return sign(x - p.x) == -1 || (sign(x - p.x) == 0 && sign(y - p.y) == -1); }
	inline bool operator==(const Point &p) const { return sign(x - p.x) == 0 && sign(y - p.y) == 0; }
};

inline istream &operator>>(istream &is, Point &p) {
	return is >> p.x >> p.y;
}

inline ostream &operator<<(ostream &os, const Point &p) {
	return os << '(' << p.x << ", " << p.y << ')';
}

struct Line : public array<Point, 2> {
	Line(const Point &a, const Point &b) { at(0) = a; at(1) = b; }
};

struct Segment : public array<Point, 2> {
	Segment() {}
	Segment(const Point &a, const Point &b) { at(0) = a; at(1) = b; }
};

struct Circle {
	Point c;
	Real r;
	Circle(const Point &c_, Real r_):c(c_), r(r_) {}
};

typedef vector<Point> Polygon;

// *define base function

inline Point rotate90(const Point &p) {
	return Point(-p.y, p.x);
}

inline Point rotate(const Point &p, Real theta) {
	const Real s = sin(theta), c = cos(theta);
	return Point(c * p.x - s * p.y, s * p.x + c * p.y);
}

inline Real angle(const Point &p) {
	return atan2(p.y, p.x);
}

inline Real norm(const Point &p) {
	return p.x * p.x + p.y * p.y;
}

inline Real abs(const Point &p) {
	return sqrt(norm(p));
}

inline Real dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

inline Real cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

// *define app function

enum { CCW = 1, CW = -1, BACK = 2, FRONT = -2, ON = 0};
inline int ccw(const Point &a, const Point &b, const Point &c) { // a:p0, b:p1, c:p2
	const Point p = b - a;
	const Point q = c - a;
	const int sign_cross = sign(cross(p, q));

	if(sign_cross == 1) return CCW;
	if(sign_cross == -1) return CW;
	if(sign(dot(p, q)) == -1) return BACK;
	if(sign(norm(p) - norm(q)) == -1) return FRONT;
	return ON;
}

inline Point project(const Line &l, const Point &p) {
	const Point a = p - l[0];
	const Point b = l[1] - l[0];
	return l[0] + b * (dot(a, b) / norm(b));
}

inline Point reflect(const Line &l, const Point &p) {
	const Point t = project(l, p);
	return t + (t - p);
}

inline bool intersect(const Segment &s, const Point &p) {
	return ccw(s[0], s[1], p) == ON;
}

inline bool intersect(const Segment &a, const Segment &b) {
	return ccw(a[0], a[1], b[0]) * ccw(a[0], a[1], b[1]) <= 0
		&& ccw(b[0], b[1], a[0]) * ccw(b[0], b[1], a[1]) <= 0;
}

inline bool intersect(const Line &l, const Point &p) {
	return abs(ccw(l[0], l[1], p)) != 1;
}

inline bool intersect(const Line &l, const Segment &s) {
	return sign(cross(l[1] - l[0], s[0] - l[0]) * cross(l[1] - l[0], s[1] - l[0])) <= 0;
}

inline bool intersect(const Line &a, const Line &b) {
	return sign(cross(a[1] - a[0], b[1] - b[0])) != 0
		|| sign(cross(a[1] - a[0], b[1] - a[0])) == 0;
}

inline Real dist(const Point &a, const Point &b) {
	return abs(a - b);
}

inline Real dist(const Line &l, const Point &p) {
	const Point a = l[1] - l[0];
	const Point b = p - l[0];
	return abs(cross(a, b)) / abs(a);
}

inline Real dist(const Line &l, const Segment &s) {
	if(intersect(l, s)) return 0;
	return min(dist(l, s[0]), dist(l, s[1]));
}

inline Real dist(const Line &a, const Line &b) {
	if(intersect(a, b)) return 0;
	return dist(a, b[0]);
}

inline Real dist(const Segment &s, const Point &p) {
	if(sign(dot(s[1] - s[0], p - s[0])) == -1) return dist(s[0], p);
	if(sign(dot(s[0] - s[1], p - s[1])) == -1) return dist(s[1], p);
	return dist(Line(s[0], s[1]), p);
}

inline Real dist(const Segment &a, const Segment &b) {
	if(intersect(a, b)) return 0;
	return min({dist(a, b[0]), dist(a, b[1]), dist(b, a[0]), dist(b, a[1])});
}

// *solve

typedef array<Segment, 5> Star;

Real dist(const Star &a, const Star &b) {
	Real res = INT_MAX;
	for(const auto &s1 : a) {
		for(const auto &s2 : b) {
			chmin(res, dist(s1, s2));
		}
	}
	return res;
}

Real dijkstra(int s, int g, const vector<vector<Real>> &mat) {
	const int n = mat.size();
	vector<Real> dist(n, INT_MAX);
	vector<bool> used(n, false);
	dist[s] = 0;

	while(true) {
		int v = -1;
		for(int u = 0; u < n; ++u) {
			if(!used[u] && (v == -1 || dist[v] > dist[u])) v = u;
		}

		if(v == g) return dist[v];
		used[v] = true;

		for(int u = 0; u < n; ++u) {
			chmin(dist[u], dist[v] + mat[v][u]);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(20);

	constexpr int N = 5;
	array<Point, N> points;
	Star buf;

	for(int n, m, l; cin >> n >> m >> l && n;) {
		vector<Star> stars;
		stars.reserve(n);

		for(int _ = 0; _ < n; ++_) {
			Point c;
			int a, r;
			cin >> c >> a >> r;

			const Point p(0, r);
			for(int i = 0; i < N; ++i) {
				const Real theta = (a + 72 * i) * (PI / 180.0);
				points[i] = rotate(p, theta) + c;
			}

			for(int i = 0; i < N; ++i) {
				buf[i] = Segment(points[i], points[(i + 2) % N]);
			}

			stars.emplace_back(buf);
		}

		vector<vector<Real>> mat(n, vector<Real>(n));
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				mat[i][j] = mat[j][i] = dist(stars[i], stars[j]);
			}
		}
		cout << dijkstra(m - 1, l - 1, mat) << '\n';
	}

	return EXIT_SUCCESS;
}