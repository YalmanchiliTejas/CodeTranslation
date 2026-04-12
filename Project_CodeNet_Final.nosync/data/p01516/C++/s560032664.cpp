#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)

typedef double Double;

const Double EPS = 1e-9;
const Double PI = acos(-1);

typedef struct Point {
	Double x, y;
	Point(Double x_, Double y_) : x(x_), y(y_) {}
	
	Point operator + (const Point& a) const {
		return Point(x + a.x, y + a.y);
	}
	
	Point operator - (const Point& a) const {
		return Point(x - a.x, y - a.y);
	}
} Vector;

Double norm(const Point& a) {
	return a.x * a.x + a.y * a.y;
}

Double abs(const Point& a) {
	return sqrt(norm(a));
}

Double dot(const Vector& a, const Vector& b) {
	return a.x * b.x + a.y * b.y;
}

Double cross(const Vector& a, const Vector& b) {
	return a.x * b.y - a.y * b.x;
}

Double dist(const Point& a, const Point& b) {
	return abs(a - b);
}

Point rotate(const Point& p, Double s) {
	return Point(p.x * cos(s) - p.y * sin(s),
				 p.x * sin(s) + p.y * cos(s));
}

int ccw(const Point& _a, const Point& _b, const Point&  _c) {
	Vector ba = _b - _a, ca = _c - _a;
	if (cross(ba, ca) > EPS) return +1; // ccw
	if (cross(ba, ca) < -EPS) return -1; // cw
	if (dot(ba, ca) < -EPS) return +2; // c-a-b
	if (abs(ba) + EPS < abs(ca)) return -2; // a-b-c
	return 0; // a-c-b
}

typedef struct Line {
	Point s, e;
	Line(Point s_, Point e_) : s(s_), e(e_) {}
} Segment;

bool is_cross(const Segment& _a, const Segment& _b) {
	return (ccw(_a.s, _a.e, _b.s) * ccw(_a.s, _a.e, _b.e) <= 0
			&& ccw(_b.s, _b.e, _a.s) * ccw(_b.s, _b.e, _a.e) <= 0);
}

Double dist_point_line(const Point& p, const Line& l) {
	return fabs(cross(p - l.s, l.e - l.s)) / abs(l.e - l.s);
}

Double dist_point_seg(const Point& p, const Segment& s) {
	if (dot(s.e - s.s, p - s.s) < EPS) return abs(p - s.s);
	if (dot(s.s - s.e, p - s.e) < EPS) return abs(p - s.e);
	return dist_point_line(p, s);
}

Double dist_seg_seg(const Segment& a, const Segment& b) {
	if (is_cross(a, b)) return 0.0;
	Double res = dist_point_seg(b.s, a);
	res = min(res, dist_point_seg(b.e, a));
	res = min(res, dist_point_seg(a.s, b));
	res = min(res, dist_point_seg(a.e, b));
	return res;
}

struct Star {
	vector< Segment > vs;
	
	Star(Point c, Double a, Double r) {
		vector< Point > vp;
		Point uc(0, r);
		vp.push_back(rotate(uc, a * PI / 180.));
		
		for_(i,0,4)	vp.push_back(rotate(vp[i], 0.4 * PI));
		
		vs.push_back(Segment(vp[0] + c, vp[2] + c));
		vs.push_back(Segment(vp[0] + c, vp[3] + c));
		vs.push_back(Segment(vp[1] + c, vp[3] + c));
		vs.push_back(Segment(vp[1] + c, vp[4] + c));
		vs.push_back(Segment(vp[2] + c, vp[4] + c));
	}
};

int N, M, L;
vector< Star > vst;

Double dst[111][111];

Double dist_star(const Star& a, const Star& b) {
	Double res = 1e5;
	for_(i,0,5) for_(j,0,5) res = min(res, dist_seg_seg(a.vs[i], b.vs[j]));
	return res;
}

void solve() {
	for_(i,0,N) for_(j,i+1,N) {
		dst[i][j] = dst[j][i] = dist_star(vst[i], vst[j]);
	}
	
	for_(k,0,N) for_(i,0,N) for_(j,0,N) {
		dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
	}
	
	cout << setprecision(20) << setiosflags(ios::fixed) << dst[M-1][L-1] << endl;
	//printf("%.20lf\n", dst[M-1][L-1]);
}

int main() {
	while (cin >> N >> M >> L, N) {
		vst.clear();
		
		for_(i,0,N) {
			Double x, y, a, r;
			cin >> x >> y >> a >> r;
			vst.push_back(Star(Point(x, y), a, r));
		}
		
		solve();
	}
	
	return 0;
}