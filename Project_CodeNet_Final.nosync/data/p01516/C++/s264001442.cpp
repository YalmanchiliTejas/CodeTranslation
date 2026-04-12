#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
  
using namespace std;
  
#if __GNUC__
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#else
#include <unordered_map>
#include <unordered_set>
#endif
  
  
  
#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int popcount(T n) { return n ? 1 + popcount(n & (n - 1)) : 0; }
#endif
#ifdef __GNUC__
template <class T> int popcount(T n);
template <> int popcount(unsigned int n) { return __builtin_popcount(n); }
template <> int popcount(int n) { return __builtin_popcount(n); }
template <> int popcount(unsigned long long n) { return __builtin_popcountll(n); }
template <> int popcount(long long n) { return __builtin_popcountll(n); }
#endif
  
#define rep (i, n) for (int i = 0; i < (int)n; ++i)
#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define rforeach(it, c) for (__typeof__((c).rbegin()) it=(c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define MEMCPY(dest, src) memcpy(dest, src, sizeof(src))
  
  
template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }
  
typedef long long ll;
typedef pair<int, int> pint;
  
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
  
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
bool valid_pos(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }
  
template <class T> void print(T a, int n, int br = 1, const string& deli = ", ") { cout << "{ "; for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } cout << " }"; while (br--) cout << endl; }
template <class T> void print(const vector<T>& v, int br = 1, const string& deli = ", ") { print(v, v.size(), br, deli); }
template <class T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) {    if (width != -1) cout.width(width); cout << a[i][j] << ' '; } cout << endl; } while (br--) cout << endl; }
  
template <class T> void input(int n, T& a) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T, class U> void input(int n, T& a, U& b) { for (int i = 0; i < n; ++i) cin >> a[i] >> b[i]; }
template <class T> vector<T> input(int n) { vector<T> res(n); for (int i = 0; i < n; ++i) cin >> res[i]; return res; }
 
 
 
 
 
const double EPS_FOR_LIB = 1e-8;
typedef double geo_type;
typedef complex<geo_type> Point;
namespace std
{
	bool operator<(const Point& a, const Point& b)
	{
		return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
	}
};
struct Line
{
	Point a, b;
	Line(Point a, Point b) : a(a), b(b) { }
	Line() { }
	Point vec() const { return b - a; }
};
typedef vector<Point> Poly;
 
void pri(const Point& p)
{
	printf("(%f, %f)\n", p.real(), p.imag());
}
void pri(const Line& line)
{
	printf("(%f, %f) - (%f, %f)\n", line.a.real(), line.a.imag(), line.b.real(), line.b.imag());
}


geo_type dot(const Point& a, const Point& b)
{
	return a.real() * b.real() + a.imag() * b.imag();
}
geo_type cross(const Point& a, const Point& b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}
 
enum res_ccw
{
	counter_clockwise = +1,
	clockwise = -1,
	straight = 0,
};
res_ccw ccw(const Point& a, const Point& b, const Point& c)
{
	Point p = b - a, q = c - a;
	if (cross(p, q) > EPS_FOR_LIB) return counter_clockwise;
	else if (cross(p, q) < -EPS_FOR_LIB) return clockwise;
	else return straight;
}

// 交差判定
bool intersectLL(const Line& line1, const Line& line2)
{
	// non-parallel
	if (abs(cross(line1.b - line1.a, line2.b - line2.a) > EPS_FOR_LIB))
		return true;
	// same line
	if (abs(cross(line1.b - line1.a, line2.a - line1.a) < EPS_FOR_LIB))
		return true;
	return false;
}
bool intersectLS(const Line& line, const Line& seg)
{
	return cross(line.b - line.a, seg.a - line.a)
		* cross(line.b - line.a, seg.b - line.a) < EPS_FOR_LIB;
}
bool intersectLP(const Line& line, const Point& p)
{
	return abs(cross(line.b - p, line.a - p)) < EPS_FOR_LIB;
}
bool intersectSS(const Line& seg1, const Line& seg2)
{
	return ccw(seg1.a, seg1.b, seg2.a) * ccw(seg1.a, seg1.b, seg2.b) <= 0
		&& ccw(seg2.a, seg2.b, seg1.a) * ccw(seg2.a, seg2.b, seg1.b) <= 0;
}
bool intersectSP(const Line& seg, const Point& p)
{
	return norm(seg.a - p) + norm(seg.b - p) - norm(seg.a - seg.b) < EPS_FOR_LIB;
}

// 距離
// complex<double>で使わないとNG
// 点から直線に垂線を下ろした点
Point projection(const Line& line, const Point& p)
{
	Point a = line.a - line.b;
	double t = dot(p - line.a, a) / norm(a);
	return line.a + t * a;
}
// 線対称な点
Point reflection(const Line& line, const Point& p)
{
	return p + ((geo_type)2) * (projection(line, p) - p);
}

// new
double dist(const Point& a, const Point& b)
{
	return abs(a - b);
}

// 直交判定
bool is_orthogonal(const Line& a, const Line& b)
{
	return dot(a.vec(), b.vec()) < EPS_FOR_LIB;
}
bool is_parallel(const Line& a, const Line& b)
{
	return cross(a.vec(), b.vec()) < EPS_FOR_LIB;
}

bool is_on_line(const Line& line, const Point& p)
{
	return cross(line.b - line.a, p - line.a) < EPS_FOR_LIB;
}
bool is_on_seg(const Line& seg, const Point& p)
{
	return dist(seg.a, p) + dist(p, seg.b) < dist(seg.a, seg.b) + EPS_FOR_LIB;
}

bool intersect_LL(const Line& line1, const Line& line2)
{
	return !is_parallel(line1, line2);
}
bool intersect_LS(const Line& line, const Line& seg)
{
	return cross(line.b - line.a, seg.a - line.a)
		* cross(line.b - line.a, seg.b - line.a) < EPS_FOR_LIB;
}
bool intersect_SS(const Line& seg1, const Line& seg2)
{
	return cross(seg1.b - seg1.a, seg2.a - seg1.a) * cross(seg1.b - seg1.a, seg2.b - seg1.a) < -EPS_FOR_LIB
		&& cross(seg2.b - seg2.a, seg1.a - seg2.a) * cross(seg2.b - seg2.a, seg1.b - seg2.a) < -EPS_FOR_LIB
		|| is_on_seg(seg1, seg2.a)
		|| is_on_seg(seg1, seg2.b)
		|| is_on_seg(seg2, seg1.a)
		|| is_on_seg(seg2, seg1.b);
}

double dist_LP(const Line& line, const Point& p)
{
	return abs(cross(line.a - line.b, p - line.b) / abs(line.a - line.b));
}
double dist_LS(const Line& line, const Line& seg)
{
	if (intersect_LS(line, seg))
		return 0;
	else
		return min(dist_LP(line, seg.a), dist_LP(line, seg.b));
}
double dist_SP(const Line& seg, const Point& p)
{
	if (dot(seg.b - seg.a, p - seg.a) < 0)
		return abs(seg.a - p);
	else if (dot(seg.a - seg.b, p - seg.b) < 0)
		return abs(seg.b - p);
	else
		return dist_LP(seg, p);
}
double dist_SS(const Line& seg1, const Line& seg2)
{
	if (intersect_SS(seg1, seg2))
		return 0;
	else
		return min(min(dist_SP(seg1, seg2.a), dist_SP(seg1, seg2.b))
			, min(dist_SP(seg2, seg1.a), dist_SP(seg2, seg1.b)));
}
// new


double distanceLP(const Line& line, const Point& p)
{
	return abs(p - projection(line, p));
}
double distanceLL(const Line& line1, const Line& line2)
{
	return intersectLL(line1, line2) ? 0 : distanceLP(line1, line2.a);
}
double distanceLS(const Line& line, const Line& seg)
{
	if (intersectLS(line, seg))
		return 0;
	return min(distanceLP(line, seg.a), distanceLP(line, seg.b));
}
double distanceSP(const Line& seg, const Point& p)
{
	const Point r = projection(seg, p);
	if (intersectSP(seg, r))
		return abs(r - p);
	return min(abs(seg.a - p), abs(seg.b - p));
}


Point rotate(const Point& p, double angle, const Point& base = Point(0, 0))
{
	double c = cos(angle), s = sin(angle);
	Point t = p - base;
	return Point(t.real() * c - t.imag() * s + base.real(), t.real() * s + t.imag() * c + base.imag());
}


vector<Line> lines(int x, int y, int a, int r)
{
    double w = PI * 2 / 5;
    double a1 = PI / 2 - w;
    double a2 = w - a1;
 
    double c1 = cos(a1), s1 = sin(a1);
    double c2 = cos(a2), s2 = sin(a2);
 
    double px[] = { 0, -c2, c1, -c1, c2, 0 };
    double py[] = { 1, -s2, s1, s1, -s2, 1 };
 
	Point p[6];
    double ang = PI * a / 180;
    for (int i = 0; i < 6; ++i)
		p[i] = (double)r * rotate(Point(px[i], py[i]), ang) + Point(x, y);

    vector<Line> res;
    for (int i = 0; i < 5; ++i)
        res.push_back(Line(p[i], p[i + 1]));
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
 
    const double INF = 1e20;
 
    int n, s, g;
    while (cin >> n >> s >> g, n)
    {
        --s, --g;
 
        vector<Line> star[128];
        for (int i = 0; i < n; ++i)
        {
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            star[i] = lines(x, y, a, r);
        }
 
 
        double e[128][128];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
				if (i == j)
				{
					e[i][j] = 0;
					continue;
				}
                e[i][j] = INF;
                for (int k = 0; k < 5; ++k)
                    for (int l = 0; l < 5; ++l)
                        min_swap(e[i][j], dist_SS(star[i][k], star[j][l]));
            }
        }
 
 
        double dis[128];
        fill(dis, dis + n, INF);
 
        typedef pair<double, int> P;
        priority_queue<P, vector<P>, greater<P> > q;
        dis[s] = 0;
        q.push(P(0, s));
        while (!q.empty())
        {
            P tt = q.top(); q.pop();
            int p = tt.second;
            double c = tt.first;
 
            if (p == g)
                break;
            else if (c > dis[p])
                continue;
 
            for (int i = 0; i < n; ++i)
            {
                double nc = c + e[p][i];
                if (nc < dis[i])
                {
                    dis[i] = nc;
                    q.push(P(nc, i));
                }
            }
        }
 
        cout.setf(ios::fixed);
        cout.precision(15);
        cout << dis[g] << endl;
    }
}