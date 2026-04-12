#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS (1e-10)
#define equlas(a, b) (fabs((a) - (b)) < EPS)
#define INF (1e9+7)
#define PI acos(-1)

class Point {
public:
    double x, y;

    Point (double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator + (Point p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (Point p) {
        return Point(x - p.x, y - p.y);
    }

    Point operator * (double c) {
        return Point(c * x, c * y);
    }

    Point operator / (double c) {
        return Point(x / c, y / c);
    }

    bool operator < (const Point &p) {
        return (x != p.x ? x < p.x : y < p.y);
    }

    bool operator == (const Point &p) {
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }

    bool operator != (const Point &p) {
        return (fabs(x - p.x) > EPS || fabs(y - p.y) > EPS);
    }

    double norm() {
        return (x * x + y * y);
    }

    double abs() {
        return sqrt(norm());
    }

    Point rotatePoint(Point s, int angle) {
        Point tmp(x - s.x, y - s.y);
        double a = angle * PI / 180.0;

        return Point(
                    tmp.x * cos(a) - tmp.y * sin(a) + s.x, 
                    tmp.x * sin(a) + tmp.y * cos(a) + s.y);
    }
};

typedef Point Vector;

double dot (Vector a, Vector b) {
    return (a.x * b.x + a.y * b.y);
}

double cross (Vector a, Vector b) {
    return (a.x * b.y - a.y * b.x);
}

double norm(Vector a) {
    return (a.x * a.x + a.y * a.y);
}

double abs(Vector a) {
    return sqrt(norm(a));
}

class Segment {
public:
    Point p1, p2;

    Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};

typedef Segment Line;

double distL(Line l, Point p) {
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double distS (Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return distL(s, p);
}

const int CCW = 1;
const int CW = -1;
const int ONBACK = 2;
const int ONFRONT = -2;
const int ONSEG = 0;

int ccw (Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;

    if (cross(a, b) > EPS) return CCW;
    if (cross(a, b) < -EPS) return CW;
    if (dot(a, b) < -EPS) return ONBACK;
    if (a.norm() < b.norm()) return ONFRONT;
    return ONSEG;
}

bool intersect (Point a, Point b, Point c, Point d) {
    return (ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0);
}

bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double distSS (Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0;
    return min(min(distS(s1, s2.p1), distS(s1, s2.p2)), min(distS(s2, s1.p1), distS(s2, s1.p2)));
}

class Star {
public:
    Point p;
    vector<Point> v;
    vector<Segment> sg;
    int r, a;

    Star (Point p = Point(), int a = 0, int r = 0) : p(p), a(a), r(r) {}

    void setVandSG () {
        v.resize(5);
        sg.resize(5);
        Point topp(p.x, p.y + r);
        int cnt = 0;

        for (int i = 0; i < 5; ++i) {
            v[i] = topp.rotatePoint(p, a + 72 * i);
        }

        for (int i = 0; i < 3; ++i) {
            sg[cnt] = Segment(v[i], v[i + 2]);
            cnt++;
            if (i + 3 <= 4) sg[cnt] = Segment(v[i], v[i + 3]);
            cnt++;
        }
    }

};

int n, m, l, x, y, a, r;
double d[110][110];
vector<Star> star;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << fixed;
    cout.precision(20);

    while (cin >> n >> m >> l, n | m | l) {
        // initialize
        star.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) d[i][j] = 0.0;
                else d[i][j] = INF;
            }
        }

        //input
        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> a >> r;
            star[i] = Star(Point(double(x), double(y)), a, r);
            star[i].setVandSG();
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 5; ++k) {
                    for (int o = 0; o < 5; ++o) {
                        if (i != j) d[i][j] = min(d[i][j], distSS(star[i].sg[k], star[j].sg[o]));
                    }
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        cout << d[m-1][l-1] << endl;

        star.clear();
    }

    return 0;
}