#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <complex>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
const long double EPS = 1e-9;
const long double PI = acos(-1);
inline bool equals(long double a, long double b) { return abs(b - a) < EPS; }
using Point = complex<long double>;
ostream &operator<<(ostream &os, Point &p) { os << p.real() << " " << p.imag(); }
inline Point rotate(long double theta, const Point &p) { return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag()); }
inline long double to_degree(long double r) { return (r * 180.0 / PI); }
inline long double to_radian(long double d) { return (d * PI / 180.0); }
namespace std { bool operator < (const Point &a, const Point &b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } }
inline long double dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }
inline long double cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }
struct Line
{
    Point a, b;
    Line(Point a, Point b) : a(a), b(b) {}
};
struct Segment : Line { Segment(Point a, Point b) : Line(a, b) {} };
inline int ccw(const Point &a, Point b, Point c)
{
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return 1;
    if(cross(b, c) < -EPS) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
template<typename T = Line>
inline Point getProjection(const T &l, const Point &p)
{
    long double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
//点、直線、線分の交差
inline bool isIntersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }
inline bool isIntersect(const Line &l, const Line &m) { return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS; }
inline bool isIntersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }
inline bool isIntersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS; }
inline bool isIntersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }
//距離
inline long double getDistance(const Point &a, const Point &b) { return abs(a - b); }
inline long double getDistance(const Line &l, const Point &p) { return abs(p - getProjection(l, p)); }
inline long double getDistance(const Segment &s, const Point &p)
{
    Point r = getProjection(s, p);
    if(isIntersect(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
inline long double getDistance(const Line &l, const Line &m) { return isIntersect(l, m) ? 0 : getDistance(l, m.a); }
inline long double getDistance(const Segment &s1, const Segment &s2)
{
    if(isIntersect(s1, s2)) return 0;
    return min({getDistance(s1, s2.a), getDistance(s1, s2.b), getDistance(s2, s1.a), getDistance(s2, s1.b)});
}
int N, M, L;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    while(cin >> N >> M >> L, N or M or L)
    {
        vector<Point> s[N];
        for(int i = 0; i < N; i++)
        {
            long double x, y, a, r; cin >> x >> y >> a >> r;
            for(int j = 0; j < 5; j++)
            {
                long double rad = to_radian(72 * j + a + 90);
                Point p = Point(r * cos(rad) + x, r * sin(rad) + y);
                s[i].push_back(p);
            }
        }
        vector<Segment> t[N];
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                Segment l = Segment(s[i][j], s[i][(j + 2) % 5]);
                t[i].push_back(l);
            }
        }
        vector<vector<long double>> G(N, vector<long double>(N, 1e8));
        for(int i = 0; i < N; i++) G[i][i] = 0.0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(i == j) continue;
                long double dist = 1e8;
                for(int a = 0; a < 5; a++)
                {
                    for(int b = 0; b < 5; b++) dist = min(dist, getDistance(t[i][a], t[j][b]));
                }
                G[i][j] = min(G[i][j], dist);
            }
        }
        for(int k = 0; k < N; k++)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
        cout << G[M - 1][L - 1] << endl;
    }
    return 0;
}


