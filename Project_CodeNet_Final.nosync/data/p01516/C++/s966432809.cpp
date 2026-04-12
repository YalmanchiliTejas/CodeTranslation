#include "bits/stdc++.h"
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-8;
typedef complex<double> point;

point operator*(const point &p, const double &d) { return point(real(p) * d, imag(p) * d); }
namespace std {
bool operator<(const point &a, const point &b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); }
}  // namespace std

struct Line : public vector<point> {
    Line(const point &a, const point &b) {
        push_back(a);
        push_back(b);
    }
};

double dist(const point &p1, const point &p2) { return abs(p1 - p2); }

double cross(const point &a, const point &b) { return real(a) * imag(b) - imag(a) * real(b); }
double dot(const point &a, const point &b) { return real(a) * real(b) + imag(a) * imag(b); }
int ccw(point a, point b, point c) {
    b -= a, c -= a;
    if (cross(b, c) > EPS) return +1;
    if (cross(b, c) < -EPS) return -1;
    if (dot(b, c) < -EPS) return +2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}
bool intersectSS(const Line &s, const Line &t) {
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 && ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
bool intersectSP(const Line &s, const point &p) { return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS; }
point projection(const Line &l, const point &p) {
    double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
    return l[0] + (l[0] - l[1]) * t;
}
double distanceSP(const Line &s, const point &p) {
    const point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const Line &s, const Line &t) {
    if (intersectSS(s, t)) return 0;
    return min({distanceSP(s, t[0]), distanceSP(s, t[1]), distanceSP(t, s[0]), distanceSP(t, s[1])});
}

const double PI = acos(-1);
struct Star {
    point c;
    double argu;
    double r;
    vector<point> ends;
    vector<Line> edges;
    Star(point c_, double argu_, double r_) : c(c_), r(r_), ends(5) {
        argu = argu_ / 360 * 2 * PI;
        double theta = PI / 2 + argu;
        REP(i, 5) {
            double phi = theta + (double)72 / 180 * PI * i;
            double x = r * cos(phi), y = r * sin(phi);
            ends[i] = c + point(x, y);
        }
        REP(i, 5) {
            Line e(ends[i], ends[(i + 2) % 5]);
            edges.push_back(e);
            // edges[i] = Line(ends[i], ends[(i + 2) % 5]);
        }
    }
};

double d[101][101];
void solve() {
    int N, M, L;
    cin >> N >> M >> L;
    if (N == 0) exit(0);
    L--, M--;
    REP(i, N) REP(j, N) {
        if (i == j)
            d[i][j] = 0;
        else
            d[i][j] = 1e9;
    }
    vector<Star> stars;
    REP(i, N) {
        double x, y, a, r;
        cin >> x >> y >> a >> r;
        point p(x, y);
        Star s(p, a, r);
        stars.push_back(s);
    }
    REP(i, N - 1) {
        FOR(j, i + 1, N) {
            double tmp = 1e9;
            REP(k, 5) REP(l, 5) { tmp = min(tmp, distanceSS(stars[i].edges[k], stars[j].edges[l])); }
            REP(k, 5) REP(l, 5) { tmp = min(tmp, dist(stars[i].ends[k], stars[j].ends[l])); }
            d[i][j] = d[j][i] = tmp;
        }
    }
    REP(k, N) REP(i, N) REP(j, N) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    REP(k, N) REP(i, N) REP(j, N) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    REP(k, N) REP(i, N) REP(j, N) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }

    cout << fixed << setprecision(20) << d[L][M] << endl;
}
signed main() {
    while (true) {
        solve();
    }
}
