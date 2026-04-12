#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using int64 = int64_t;

constexpr int64 MOD = 1000000007;

constexpr double INF = numeric_limits<double>::max();

constexpr double EPS = 1e-8;

double sq (const double v) { return v * v; }

struct Vec {
    double x, y;
    Vec () {}
    ~Vec (){ }

    Vec (double x_, double y_): x(x_), y(y_) {}

    Vec operator + (const Vec& o) const { return Vec(x + o.x, y + o.y); }
    Vec operator - (const Vec& o) const { return Vec(x - o.x, y - o.y); }
};

double inner_prod(const Vec p1, const Vec p2) { return p1.x * p2.x + p1.y * p2.y; }

struct line {
    Vec p1, p2;

    line (Vec p1_, Vec p2_): p1(p1_), p2(p2_) {}
};

struct star {
    double x, y, a, r;
    star () {}
    ~star () {}

    star (double x_, double y_, double a_, double r_): x(x_), y(y_), a(a_), r(r_) {}

    vector<Vec> get_vertices () {
        vector<Vec> ret;

        for (int j = 0; j < 5; ++j) {
            const double rad = a + 72*j;

            const double ret_x = x - r * sin(M_PI * rad / 180);
            const double ret_y = y + r * cos(M_PI * rad / 180);

            ret.emplace_back(ret_x, ret_y);
        }

        return ret;
    }

    vector<line> get_lines () {
        vector<line> ret;

        auto vs = get_vertices();
        assert(vs.size() == 5);
        for (int j = 0; j < 5; ++j) ret.emplace_back(vs[j], vs[(j+2)%5]);

        return ret;
    }
};

double dist_ps (const Vec p, const line l) {

    if (inner_prod(p - l.p1, l.p2 - l.p1) <= 0 || inner_prod(p - l.p2, l.p1 - l.p2) <= 0) {
        double d1 = sq(p.x - l.p1.x) + sq(p.y - l.p1.y);
        double d2 = sq(p.x - l.p2.x) + sq(p.y - l.p2.y);

        return min(d1, d2);
    }

    if (abs(l.p1.x * l.p2.y - l.p2.x * l.p1.y) < EPS) {
        const double a = l.p1.x, b = l.p1.y;
        return sq(a * p.x + b * p.y) / (a * a + b * b);
    }

    const double a = (l.p1.y - l.p2.y) / (l.p1.x * l.p2.y - l.p2.x * l.p1.y);
    const double b = (l.p1.x - l.p2.x) / (l.p1.y * l.p2.x - l.p2.y * l.p1.x);
    return sq(a * p.x + b * p.y + 1) / (a * a + b * b);
}

double put(const Vec p, const line l) {
    double a, b, c;
    if (abs(l.p1.x * l.p2.y - l.p2.x * l.p1.y) < EPS) {
        a = l.p1.x; b = l.p1.y; c = 0;
    } else {
        a = (l.p1.y - l.p2.y) / (l.p1.x * l.p2.y - l.p2.x * l.p1.y);
        b = (l.p1.x - l.p2.x) / (l.p1.y * l.p2.x - l.p2.y * l.p1.x);
        c = 1;
    }

    return a * p.x + b * p.y + c;
}

double dist2lines(const line l1, const line l2) {
    double ans = numeric_limits<double>::max();
    if (put(l1.p1, l2) * put(l1.p2, l2) < 0 && put(l2.p1, l1) * put(l2.p2, l1) < 0) {
        return 0;
    }
    ans = min(ans, dist_ps(l1.p1, l2));
    ans = min(ans, dist_ps(l1.p2, l2));
    ans = min(ans, dist_ps(l2.p1, l1));
    ans = min(ans, dist_ps(l2.p2, l1));
    return ans;
}

// --------------------------------------------------

struct state {
    int pos; double dist;
    state (int pos_, double dist_): pos(pos_), dist(dist_) {}

    bool operator < (const state& o) const {
        return dist > o.dist;
    }
};

// --------------------------------------------------

int N, M, L;
double x[100], y[100], a[100], r[100];

double graph[100][100];

double solve() {
    for (int j = 0; j < N; ++j) fill(graph[j], graph[j]+N, INF);
    for (int j = 0; j < N; ++j) graph[j][j] = 0;

    vector<star> stars;
    for (int j = 0; j < N; ++j) stars.emplace_back(x[j], y[j], a[j], r[j]);

    for (int j = 0; j < N; ++j) {
        for (int k = j+1; k < N; ++k) {
            const vector<line> ls1 = stars[j].get_lines();
            const vector<line> ls2 = stars[k].get_lines();

            for (auto& e: ls1) {
                for (auto& f: ls2) {
                    graph[j][k] = graph[k][j] = min(graph[j][k], sqrt(dist2lines(e, f)));
                }
            }
        }
    }

    double min_dist[100];
    fill(min_dist, min_dist+N, INF);
    min_dist[M] = 0;

    priority_queue<state> pq;
    pq.emplace(M, 0);

    while (!pq.empty()) {
        state st = pq.top(); pq.pop();

        if (st.dist > min_dist[st.pos]) { continue; }

        for (int j = 0; j < N; ++j) {
            if (j == st.pos) continue;

            if (min_dist[j] > st.dist + graph[st.pos][j]) {
                min_dist[j] = st.dist + graph[st.pos][j];

                pq.emplace(j, min_dist[j]);
            }
        }
    }

    return min_dist[L];
}

int main() {
    while (true) {
        cin >> N >> M >> L;
        if (N == 0 && M == 0 && L == 0) return 0;

        --M; --L;

        for (int j = 0; j < N; ++j) {
            cin >> x[j] >> y[j] >> a[j] >> r[j];
        }

        printf("%.12f\n", solve());
    }
    return 0;
}