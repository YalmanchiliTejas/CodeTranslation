#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <utility>

const double PI=3.14159265358979323846264;
const double EPS=1e-9;
const double INF=1e12;

using Point=std::complex<double>;
using LineSeg=std::pair<Point, Point>;

double dot(const Point &a, const Point &b) {
    return a.real()*b.real() + a.imag()*b.imag();
}

double cross(const Point &a, const Point &b) {
    return a.real()*b.imag() - a.imag()*b.real();
}

enum CCWise {
    ONLINE_FRONT=-2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK,
};

CCWise ccw(Point a, Point b, Point c) {
    b -= a;
    c -= a;
    if (cross(b, c) > EPS) return COUNTER_CLOCKWISE;
    if (cross(b, c) < -EPS) return CLOCKWISE;
    if (dot(b, c) < 0) return ONLINE_BACK;
    if (norm(b) < norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool crossed(const LineSeg &s, const LineSeg &t) {
    const Point &s1=s.first, &s2=s.second, &t1=t.first, &t2=t.second;
    if (ccw(s1, s2, t1) * ccw(s1, s2, t2) > 0)
        return false;

    return ccw(t1, t2, s1) * ccw(t1, t2, s2) <= 0;
}

double dist_sp(const LineSeg &s, const Point &p) {
    const Point &s1=s.first, &s2=s.second;
    if (dot(s2-s1, p-s1) < EPS) return std::abs(p-s1);
    if (dot(s1-s2, p-s2) < EPS) return std::abs(p-s2);
    return std::abs(cross(s2-s1, p-s1)) / std::abs(s2-s1);
}

struct Star {
    Point p;
    double angle, radius;
    Point pts[5];
    Star(double x, double y, double a, double r):
        p(x, y), angle(a), radius(r)
    {
        pts[0] = p + std::polar(r, (90+angle)*PI/180);
        Point q=std::polar(2*r*std::cos(18*PI/180), (108+angle)*PI/180);
        for (int i=1; i<5; ++i) {
            q *= std::polar(1.0, 144*PI/180);
            pts[i] = pts[i-1] + q;
        }
    }
    double howfar(const Star &other) const {
        double res=INF;

        for (size_t i=0; i<5; ++i)
            for (size_t j=0; j<5; ++j) {
                LineSeg s(pts[i], pts[(i+1)%5]);
                LineSeg t(other.pts[j], other.pts[(j+1)%5]);
                if (crossed(s, t))
                    return 0.0;

                res = std::min(res, dist_sp(s, other.pts[j]));
                res = std::min(res, dist_sp(t, pts[i]));
            }

        return res;
    }
};

int testcase_ends() {
    size_t N, M, L;
    scanf("%zu %zu %zu", &N, &M, &L);

    if (N == 0 && M == 0 && L == 0)
        return 1;

    std::vector<Star> s;
    s.reserve(N);
    for (size_t i=0; i<N; ++i) {
        int x, y, a, r;
        scanf("%d %d %d %d", &x, &y, &a, &r);
        s.emplace_back(x, y, a, r);
    }

    std::vector<std::vector<double>> dist(N, std::vector<double>(N));
    for (size_t i=0; i<N; ++i)
        for (size_t j=i+1; j<N; ++j)
            dist[i][j] = dist[j][i] = s[i].howfar(s[j]);

    for (size_t k=0; k<N; ++k)
        for (size_t i=0; i<N; ++i)
            for (size_t j=0; j<N; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("%.12f\n", dist[--M][--L]);
    return 0;
}

int main() {
    while (true)
        if (testcase_ends()) break;

    return 0;
}