// #define DEBUGGING
#include <bits/stdc++.h>
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
using ll = std::int64_t;
using ull = std::uint64_t;
using PLL = std::pair<ll, ll>;
using TLL = std::tuple<ll, ll, ll>;
template <typename T> using V = std::vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return std::min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return std::max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return std::max(low, std::min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { return t = clamp(t, low, high); }
namespace init__ { struct InitIO { InitIO() { std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); std::cout << std::fixed << std::setprecision(30); } } init_io; }
#define mv_rec make_v(init, tail...)
template <typename T> T make_v(T init) { return init; }
template <typename T, typename... Tail> auto make_v(T init, size_t s, Tail... tail) { return V<decltype(mv_rec)>(s, mv_rec); }
#undef mv_rec
using namespace std;

#ifdef DEBUGGING
#include "../../debug/debug.cpp"
#else
#define DEBUG(...) 0
#define DEBUG_SEPARATOR_LINE 0
#endif

using Point = complex<double>;

struct DualPoint : public pair<Point, Point> {
    using pair<Point, Point>::pair;

    Point& operator [](size_t idx) {
        return idx == 0 ? first : second;
    }
    
    const Point& operator [](size_t idx) const {
        return idx == 0 ? first : second;
    }
};

struct Line : public DualPoint {
    using DualPoint::DualPoint;
};

struct Seg : public DualPoint {
    using DualPoint::DualPoint;
};

const double eps = 1e-6;
const long double pi = 3.14159265358979323846264338327950288419716939937510L;

double dot(const Point &a, const Point &b) {
    return (conj(a) * b).real();
}

double cross(const Point &a, const Point &b) {
    return (conj(a) * b).imag();
}

enum ccwd {
    Clock = -1,
    CoClock = 1,
    CAB = 2,
    ABC = -2,
    ACB = 0,
};

ccwd ccw(Point a, Point b, Point c) {
    b -= a;
    c -= a;
    double p, q;
    {
        auto tmp = conj(b) * c;
        p = tmp.real();
        q = tmp.imag();
    }
    if (0 < q) return CoClock;
    if (q < 0) return Clock;
    if (p < 0) return CAB;
    if (norm(b) < norm(c)) return ABC;
    return ACB;
}

bool is_zero(double a) {
    return abs(a) <= eps;
}

bool is_parallel(const Line &l1, const Line &l2) {
    return is_zero(cross(l1[1] - l1[0], l2[1] - l2[0]));
}

bool is_same_line(Point o, Point a, Point b) {
    return is_zero(cross(a - o, b - o));
}

bool intersect(const Line &p, const Line &q) {
    if (!is_parallel(p, q)) return true;
    return is_same_line(p[0], p[1], q[1]);
}

bool intersect(const Line &l, const Seg &s) {
    double a = cross(l[1] - l[0], s[0] - l[0]);
    double b = cross(l[1] - l[0], s[1] - l[0]);
    return a * b < 0;
}

bool intersect(const Seg &p, const Seg &q) {
    bool pf = (ccw(p[0], p[1], q[0]) * ccw(p[0], p[1], q[1])) <= 0;
    bool qf = (ccw(q[0], q[1], p[0]) * ccw(q[0], q[1], p[1])) <= 0;
    return pf && qf;
}

bool intersect(const Line &l, const Point &p) {
    return is_same_line(p, l[0], l[1]);
}

bool intersect(const Seg &s, const Point &p) {
    double l1 = abs(s[0] - s[1]);
    double l2 = abs(s[0] - p);
    double l3 = abs(s[1] - p);
    return is_zero(l2 + l3 - l1);
}

// projection from p to l
Point proj(const Line &l, const Point &p) {
    double mul = dot(p - l[0], l[1] - l[0]) / norm(l[0] - l[1]);  // cos(theta) / (p-l[0]).norm()
    return l[0] + mul * (l[1] - l[0]);
}

Point refl(const Line &l, const Point &p) {
    Point pr = proj(l, p);
    return p + (2. * (pr - p));
}

double distance(const Line &l, const Point &p) {
    return abs(p - proj(l, p));
}

double distance(const Line &p, const Line &q) {
    if (is_parallel(p, q)) return distance(p, q[0]);
    return 0;
}

double distance(const Line &l, const Seg &s) {
    if (intersect(l, s)) return 0;
    return min(distance(l, s[0]), distance(l, s[1]));
}

double distance(const Seg &s, const Point &p) {
    Line l(s[0], s[1]);
    Point pr = proj(l, p);
    if (intersect(s, pr)) return abs(pr - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}

double distance(const Seg &p, const Seg &q) {
    if (intersect(p, q)) return 0;
    return var_min(distance(p, q[0]), distance(p, q[1]),
                   distance(q, p[0]), distance(q, p[1]));
}

double fix_arg(double arg) {
    arg += 2 * pi;
    if (2 * pi <= arg) arg -= 2 * pi;
    return arg;
}

bool comp_coclock(const Point &p1, const Point &p2) {
    return fix_arg(arg(p1)) < fix_arg(arg(p2));
}

Point rotate(const Point &p, double arg) {
    complex<double> r(cos(arg), sin(arg));
    return p * r;
}

struct Star {
    const static size_t line_sz = 5 * 4 / 2 - 5;
    array<Point, 5> points;
    array<Seg, line_sz> lines;
    double x, y, r;

    Star(double x, double y, double a, double r) : x(x), y(y), r(r) {
        a = a / 360 * 2 * pi + pi / 2;
        points[0] = rotate(Point(r, 0), a);
        for (int i = 1; i < 5; i++) points[i] = rotate(points[i - 1], 2 * pi / 5);
        sort(ALL(points), comp_coclock);
        for (auto &&e : points) e += Point(x, y);
        size_t idx = 0;
        for (int i = 0; i < 5; i++) for (int j = i + 2; j < (i == 0 ? 4 : 5); j++) lines[idx++] = Seg(points[i], points[j]);
    }
};

double distance(const Star &p, const Star &q) {
    double ret = numeric_limits<double>::max();
    for (auto &&s1 : p.lines) for (auto &&s2 : q.lines) {
        chmin(ret, distance(s1, s2));
    }
    return ret;
}

double mat[100][100];
using Dist = pair<double, ll>;

bool solve() {
    ll N, M, L;
    cin >> N >> M >> L;
    if (!(N + M + L)) return false;
    M--; L--;
    V<Star> stars;
    for (ll i = 0; i < N; i++) {
        double x, y, a, r;
        cin >> x >> y >> a >> r;
        stars.emplace_back(x, y, a, r);
    }

    for (ll i = 0; i < N; i++) for (ll j = i + 1; j < N; j++) {
        double d = distance(stars[i], stars[j]);
        mat[i][j] = mat[j][i] = d;
    }

    V<double> dists(N, numeric_limits<double>::max());
    priority_queue<Dist, V<Dist>, greater<Dist>> pq;
    dists[M] = 0;
    pq.emplace(0, M);
    while (pq.size()) {
        double d;
        ll cur;
        tie(d, cur) = pq.top();
        pq.pop();
        if (eps < d - dists[cur]) continue;
        for (ll nxt = 0; nxt < N; nxt++) {
            double c = mat[cur][nxt];
            double nd = d + c;
            if (!(eps < dists[nxt] - nd)) continue;
            dists[nxt] = nd;
            pq.emplace(nd, nxt);
        }
    }

    cout << dists[L] << endl;
    return true;
}

int main() {
    while (solve());
    return 0;
}

