#include <bits/stdc++.h>

namespace geo {

// ???????????§??????

typedef std::complex<double> Point;

struct Segment {
	Point p1, p2;
	Segment(const Point &p1 = Point(), const Point &p2 = Point()): p1(p1), p2(p2){}
};

struct Circle {
	Point p;
	double r;
	Circle(const Point &p = Point(), double r = 0.0): p(p), r(r){}
};

typedef Point Vector;
typedef Segment Line;
typedef std::vector<Point> Polygon;


// ?????°, ??????

const double PI = acos(-1);
const double EPS = 1e-8;
const double INF = 1e16;
const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE 		= -1;
const int ONLINE_BACK		= 2;
const int ONLINE_FRONT		= -2;
const int ON_SEGMENT		= 0;
const int OUT				= 0;
const int ON				= 1;
const int IN				= 2;

inline double square(double a){return a * a;}
inline bool equal(double a, double b){return abs(a - b) < EPS;}
inline bool equalVector(const Vector &a, const Vector &b){return equal(a.real(), b.real()) && equal(a.imag(), b.imag());}
inline double norm(const Point &a){return square(a.real()) + square(a.imag());}
inline double dot(const Point &a, const Point &b){return (conj(a) * b).real();}
inline double cross(const Point &a, const Point &b){return (conj(a) * b).imag();}
inline double toDeg(double t){return t / PI * 180;}
inline double toRad(double t){return t / 180 * PI;}

#define curr(v, i) v[i]
#define next(v, i) v[(i + 1) % v.size()]
#define prev(v, i) v[(i - 1 + v.size()) % v.size()]


// ????????¢??° (x ??§?¨?, y ??§?¨?, ????§?)
// ????§?????????????????????? Point rp ?????£??\????????????

bool cmpx(const Point &a, const Point &b){
	if (!equal(a.real(), b.real())) return a.real() < b.real();
	return b.imag() < b.imag();
}

bool cmpy(const Point &a, const Point &b){
	if (!equal(a.imag(), b.imag())) return a.imag() < b.imag();
	return a.real() < b.real();
}

Point rp;
bool cmparg(const Point &a, const Point &b){
	double rada = arg(a - rp); if (rada < 0.0) rada += 2 * PI;
	double radb = arg(b - rp); if (radb < 0.0) radb += 2 * PI;
	if (!equal(rada, radb)) return rada < radb;
	return norm(a) < norm(b);
}


// ??´???, ??????

bool orthgonal(const Vector &a, const Vector &b){
	return equal(dot(a, b), 0.0);
}

bool parallel(const Vector &a, const Vector &b){
	return equal(cross(a, b), 0.0);
}


// ????°?, ?°???±

Point project(const Segment &s, const Point &p){
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / norm(base);
	return s.p1 + base * r;
}

Point reflect(const Segment &s, const Point &p){
	return p + (project(s, p) - p) * 2.0;
}


// ??????????????????

int ccw(const Point &p0, const Point &p1, const Point &p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (norm(a) > norm(b)) return ONLINE_FRONT;
	return ON_SEGMENT;
}


// ?????¢

double distanceLP(const Line &l, const Point &p){
	return std::abs(cross(l.p2 - l.p1, p - l.p1) / std::abs(l.p2 - l.p1));
}

double distanceSP(const Segment &s, const Point &p){
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return std::abs(p - s.p1);
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return std::abs(p - s.p2);
	return distanceLP(s, p);
}

bool intersect(const Segment &s1, const Segment &s2);
double distance(const Segment &s1, const Segment &s2){
	if (intersect(s1, s2)) return 0.0;
	return std::min(
		std::min(distanceSP(s1, s2.p1), distanceSP(s1, s2.p2)),
		std::min(distanceSP(s2, s1.p1), distanceSP(s2, s1.p2))
	);
}


// ????????????

bool intersect(const Segment &s1, const Segment &s2){
	return ccw(s1.p1, s1.p2, s2.p1) * ccw(s1.p1, s1.p2, s2.p2) <= 0 &&
		ccw(s2.p1, s2.p2, s1.p1) * ccw(s2.p1, s2.p2, s1.p2) <= 0;
}

int intersect(const Circle &c, const Segment &s){
	// ???????????° (0 ~ 2) ?????????
	double dist = distanceSP(s, c.p) - c.r;
	if (equal(dist, 0.0)) return 1;
	if (dist < 0.0) return 2;
		return 0;
	}

int intersect(const Circle &c1, const Circle &c2){
	// ???????????° (0 ~ 2) ?????????
	double dist = abs(c1.p - c2.p) - (c1.r + c2.r);
	if (equal(dist, 0.0)) return 1;
	if (dist < 0.0) return 2;
	return 0;
}


// ??????

Point crossPoint(const Segment &s1, const Segment &s2){
	Vector base = s2.p2 - s2.p1;
	double d1 = std::abs(cross(base, s1.p1 - s2.p1));
	double d2 = std::abs(cross(base, s1.p2 - s2.p1));
	
	// !! ????????´?????¶????????????????????\????????¨ 0 ?????? !!
	assert(!equal(d1 + d2, 0.0));
	
	double t = d1 / (d1 + d2);
	return s1.p1 + (s1.p2 - s1.p1) * t;
}

std::vector<Point> crossPoints(const Circle &c, const Line &l){
	std::vector<Point> res;
	if (!intersect(c, l)) return res;
	
	Vector pr = project(l, c.p);
	Vector e = (l.p2 - l.p1) / std::abs(l.p2 - l.p1);
	double base = std::sqrt(c.r * c.r - norm(pr - c.p));
	res.push_back(pr + e * base);
	res.push_back(pr - e * base);
	if (equalVector(res[0], res[1])) res.pop_back();
	return res;
}

std::vector<Point> crossPoints(const Circle &c1, const Circle &c2){
	std::vector<Point> res;
	if (!intersect(c1, c2)) return res;
	
	double d = std::abs(c1.p - c2.p);
	double a = std::acos(square(c1.r) + square(d) - square(c2.r) / (2 * c2.r * d));
	double t = std::arg(c2.p - c1.p);
	res.push_back(c1.p + std::polar(c1.r, t + a));
	res.push_back(c1.p + std::polar(c1.r, t - a));
	if (equalVector(res[0], res[1])) res.pop_back();
	
	return res;
}


// ??????

int contains(const Polygon &g, const Point &p){
	int n = g.size();
	bool res = false;
	for (int i = 0; i < n; i++){
		Point a = g[i] - p;
		Point b = g[(i + 1) % n] - p;
		if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON;
		if (a.imag() > b.imag()) swap(a, b);
		if (a.imag() < EPS && EPS < b.imag() && cross(a, b) > EPS) res = !res;
	}
	return res ? IN : OUT;
}


// ??????

Polygon convexHull(std::vector<Point> s){
	Polygon u, l;
	if (s.size() < 3) return s;
	std::sort(s.begin(), s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);
	l.push_back(s[s.size() - 1]);
	l.push_back(s[s.size() - 2]);
	
	for (int i = 2; i < s.size(); i++){
		int n = u.size();
		while (n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE){
			u.pop_back();
			n--;
		}
		u.push_back(s[i]);
	}
	
	for (int i = s.size() - 3; i >= 0; i--){
		int n = l.size();
		while (n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE){
			l.pop_back();
			n--;
		}
		l.push_back(s[i]);
	}
	
	std::reverse(l.begin(), l.end());
	for (int i = u.size() - 2; i >= 1; i--){
		l.push_back(u[i]);
	}
	
	return l;
}
	

// ???????§???¢??????

Polygon convexCut(const Polygon &g, const Line &l){
	Polygon res;
	for (int i = 0; i < g.size(); i++){
		const Point &a = curr(g, i);
		const Point &b = next(g, i);
		if (ccw(l.p1, l.p2, a) != CLOCKWISE){
			res.push_back(a);
		}
		if (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) < 0){
			res.push_back(crossPoint(Line(a, b), l));
		}
	}
	
	return res;
}

}

namespace std {
bool operator < (const geo::Point &a, const geo::Point &b){
	return geo::cmpx(a, b);
}
}

int n, m, l;
double x[1000], y[1000], r[1000], a[1000];
std::vector<geo::Point> ps[100];
std::vector<geo::Segment> star[100];

double solve()
{
	static double dist[100][100];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			double t = geo::INF;
			for (auto &S : star[i]){
				for (auto &T : star[j]){
					t = std::min(t, geo::distance(S, T));
				}
			}
			dist[i][j] = dist[j][i] = t;
		}
	}
	
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	return dist[m][l];
}

int main()
{
	while (std::scanf("%d %d %d", &n, &m, &l), n){
		m--; l--;
		
		for (int i = 0; i < n; i++){
			std::scanf("%lf %lf %lf %lf", x + i, y + i, a + i, r + i);
			a[i] = geo::toRad(a[i]);
			
			ps[i].clear();
			for (int j = 0; j < 5; j++){
				double A = a[i] + (geo::PI * 2 / 5) * j + (geo::PI / 2);
				ps[i].push_back(geo::Point(x[i], y[i]) + std::polar(r[i], A));
				//std::cout << ps[i].back();
			}
			star[i].clear();
			for (int j = 0; j < 5; j++){
				int k = (j + 2) % 5;
				star[i].push_back(geo::Segment(ps[i][j], ps[i][k]));
			}
		}
		
		printf("%.20f\n", solve());
	}
	
	return 0;
}