#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

constexpr double PI = 3.141592653589;

double deg2rad(double deg) {
    return (PI / 180) * deg;
}

struct point {
    double x, y;
    point() {}
    point(double a, double b): x(a), y(b) {}
    point operator + (const point& o) const { return point(x+o.x, y+o.y); }
    point operator - (const point& o) const { return point(x-o.x, y-o.y); }
    point operator * (const double a) const { return point(x*a, y*a); }
};

double abs(point a) { return sqrt(a.x*a.x + a.y*a.y); }
double fabs(point a) { return sqrt(a.x*a.x + a.y*a.y); }
double dot(point a, point b) { return a.x*b.x + a.y*b.y; }
double cross(point a, point b) { return a.x*b.y - a.y*b.x; }

struct line {
    point a, b;
    line() {}
    line(point a, point b): a(a), b(b) {}
};

bool has_intersect(line s, line t) {
    double csa = cross(s.b - s.a, t.a - s.a);
    double csb = cross(s.b - s.a, t.b - s.a);
    double cta = cross(t.b - t.a, s.a - t.a);
    double ctb = cross(t.b - t.a, s.b - t.a);

    return csa * csb < 0 && cta * ctb < 0;
}

point intersect(line s, line t) {
    assert(has_intersect(s, t));

    double c1 = fabs(cross(t.b - t.a, s.a - t.a));
    double c2 = fabs(cross(t.b - t.a, s.b - t.a));

    return s.a + (s.b - s.a) * (c1 / (c1 + c2));
}

double dist_line_point(line s, point p) {
    if (dot(s.b - s.a, p - s.a) >= 0 && dot(s.a - s.b, p - s.b) >= 0)
        return fabs(cross(s.b - s.a, p - s.a)) / abs(s.b - s.a);
    return min(fabs(p - s.a), fabs(p - s.b));
}

double dist_lines(line s, line t) {
    if (has_intersect(s, t)) return 0;

    double d1 = dist_line_point(s, t.a);
    double d2 = dist_line_point(s, t.b);
    double d3 = dist_line_point(t, s.a);
    double d4 = dist_line_point(t, s.b);

    return min(min(d1, d2), min(d3, d4));
}

struct star {
    vector<line> ls;
    star() {}
};

star make_star(double cx, double cy, double deg, double r) {
    point c(cx, cy);

    point a(-sin(deg2rad(deg)) * r,     cos(deg2rad(deg)) * r);
    point b(-sin(deg2rad(deg+144)) * r, cos(deg2rad(deg+144)) * r);

    star ret;

    for (int i = 0; i < 5; ++i) {
        ret.ls.emplace_back(c + a, c + b);

        a = point(cos(deg2rad(72)) * a.x - sin(deg2rad(72)) * a.y,
                  sin(deg2rad(72)) * a.x + cos(deg2rad(72)) * a.y);
        b = point(cos(deg2rad(72)) * b.x - sin(deg2rad(72)) * b.y,
                  sin(deg2rad(72)) * b.x + cos(deg2rad(72)) * b.y);
    }

    return ret;
}

double dist_stars(star s, star t) {
    double ret = 1e250;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            ret = min(ret, dist_lines(s.ls[i], t.ls[j]));

    return ret;
}

int N, M, L;
vector<star> S;

double solve() {
    vector<vector<double>> dist(N, vector<double>(N, 1e250));
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
        for (int j = i+1; j < N; ++j) {
            double d = dist_stars(S[i], S[j]);
            dist[i][j] = dist[j][i] = d;
        }
    }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist[M][L];
}

int main() {
    cout << fixed << setprecision(20);
    while (true) {
        cin >> N >> M >> L;
        if (N == 0 && M == 0 && L == 0) break;

        --M; --L;
        S.resize(N);
        for (int i = 0; i < N; ++i) {
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            S[i] = make_star(x, y, a, r);
        }
        cout << solve() << endl;
    }
    return 0;
}

