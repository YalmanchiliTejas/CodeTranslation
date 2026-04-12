#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
class point2d {
public:
	double x, y;
	point2d() : x(0), y(0) {};
	point2d(double x_, double y_) : x(x_), y(y_) {};
	bool operator==(const point2d& p) const { return x == p.x && y == p.y; }
	bool operator!=(const point2d& p) const { return x != p.x || y != p.y; }
	point2d& operator+=(const point2d& p) { x += p.x; y += p.y; return *this; }
	point2d& operator-=(const point2d& p) { x -= p.x; y -= p.y; return *this; }
	point2d& operator*=(const double v) { x *= v; y *= v; return *this; }
	point2d operator+(const point2d& p) const { return point2d(*this) += p; }
	point2d operator-(const point2d& p) const { return point2d(*this) -= p; }
	point2d operator*(const double v) const { return point2d(*this) *= v; }
	double norm() const { return x * x + y * y; }
	double abs() const { return std::sqrt(x * x + y * y); }
	double dot(const point2d& p) const { return x * p.x + y * p.y; }
	double cross(const point2d& p) const { return x * p.y - y * p.x; }
	int ccw(const point2d& p1, const point2d& p2) const {
		point2d pr1 = p1 - point2d(*this);
		point2d pr2 = p2 - point2d(*this);
		if (pr1.cross(pr2) != 0) return pr1.cross(pr2) > 0 ? 1 : -1;
		if (pr1.dot(pr2) < 0) return 2;
		return pr1.norm() < pr2.norm() ? -2 : 0;
	}
};
class segment2d {
public:
	point2d p1, p2;
	segment2d() : p1(), p2() {};
	segment2d(const point2d& p1_, const point2d& p2_) : p1(p1_), p2(p2_) {};
	double norm() const { return (p1 - p2).norm(); }
	double abs() const { return (p1 - p2).abs(); }
};
bool intersect(const segment2d& s1, const segment2d& s2) {
	if (s1.p1 == s2.p1 || s1.p1 == s2.p2 || s1.p2 == s2.p1 || s1.p2 == s2.p2) return false; // EXCEPTION !!!
	return s1.p1.ccw(s1.p2, s2.p1) * s1.p1.ccw(s1.p2, s2.p2) <= 0 && s2.p1.ccw(s2.p2, s1.p1) * s2.p1.ccw(s2.p2, s1.p2) <= 0;
}
point2d intersect_point(const segment2d &s1, const segment2d &s2) {
	point2d base = s2.p2 - s2.p1;
	double d1 = std::abs(base.cross(s1.p1 - s2.p1));
	double d2 = std::abs(base.cross(s1.p2 - s2.p1));
	return s1.p1 + (s1.p2 - s1.p1) * (d1 / (d1 + d2));
}
bool contain(const std::vector<point2d>& v, const point2d& p) {
	int ans = -1;
	for (int i = 0; i < v.size(); ++i) {
		point2d p1 = v[i] - p;
		point2d p2 = v[(i + 1) % v.size()] - p;
		if (p1.x > p2.x) std::swap(p1, p2);
		if (p1.x <= 0 && 0 < p2.x && p1.cross(p2) < 0) ans *= -1;
	}
	return (ans == 1);
}
int main() {
	int n;
	vector<point2d> v(2);
	cin >> v[0].x >> v[0].y >> v[1].x >> v[1].y;
	cin >> n;
	v.resize(n + 2);
	for (int i = 2; i < n + 2; ++i) {
		cin >> v[i].x >> v[i].y;
	}
	// Shortest Path (Warshall-Floyd Algorithm)
	vector<vector<double> > d(n + 2, vector<double>(n + 2, 1.0e+99));
	for (int i = 0; i < n + 2; ++i) {
		d[i][i] = 0;
	}
	for (int i = 0; i < n + 2; ++i) {
		for (int j = 0; j < i; ++j) {
			// Going to vertex j from vertex i
			bool ok = true;
			for (int k = 0; k < v.size() - 2; ++k) {
				segment2d s(v[k + 2], v[(k + 1) % (v.size() - 2) + 2]);
				if (intersect(s, segment2d(v[i], v[j]))) {
					//cout << i << ' ' << j << ' ' << k << "-" << k + 1 << endl;
					ok = false;
				}
			}
			if (contain(vector<point2d>(v.begin() + 2, v.end()), (v[i] + v[j]) * 0.5)) {
				ok = false;
			}
			if (ok || (j >= 2 && i - j == 1) || (j == 2 && i == n + 1)) {
				//cout << i << ' ' << j << endl;
				d[i][j] = (v[i] - v[j]).abs();
				d[j][i] = (v[i] - v[j]).abs();
			}
		}
	}
	d[0][1] = 1.0e+99;
	d[1][0] = 1.0e+99;
	for (int i = 0; i < n + 2; ++i) {
		for (int j = 0; j < n + 2; ++j) {
			for (int k = 0; k < n + 2; ++k) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
	double ans = d[0][1];
	for (int i = 0; i < n; ++i) {
		point2d p1 = v[i + 2], p2 = v[(i + 1) % (v.size() - 2) + 2];
		point2d bs = p1 + (p2 - p1) * (v[1] - p1).dot(p2 - p1) * (1.0 / (p2 - p1).norm());
		point2d rfl = bs * 2 - v[1];
		point2d crp = intersect_point(segment2d(p1, p2), segment2d(v[0], rfl));
		if (min(p1.x, p2.x) <= crp.x && crp.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= crp.y && crp.y <= max(p1.y, p2.y)) {
			bool ok = true;
			for (int j = 0; j < n; ++j) {
				point2d pp1 = v[j + 2], pp2 = v[(j + 1) % (v.size() - 2) + 2];
				if (intersect(segment2d(pp1, pp2), segment2d(v[0], v[1]))) {
					ok = false;
				}
			}
			if (ok) {
				double d0 = (crp - v[0]).abs();
				double d1 = (crp - v[1]).abs();
				ans = min(ans, d0 + d1);
			}
		}
	}
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}
