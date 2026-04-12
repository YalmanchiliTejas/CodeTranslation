#include <bits/stdc++.h>
using namespace std;
#define REP(i, m, n) for (int i = m; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define MP make_pair
using ld = long double;
constexpr ld DINF = 1e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-13;

struct dijkstra
{
    int V;
    struct edge
    {
        int to;
        ld cost;
    };
    vector<vector<edge>> E;
    vector<ld> d;
    using pt = pair<ld, int>;
    dijkstra(int V_) : V(V_)
    {
        E.resize(V);
        d.resize(V);
    }

    void add_E(int a, int b, ld c)
    {
        E[a].emplace_back(edge{b, c});
        E[b].emplace_back(edge{a, c});
    }

    void calc(int s)
    {
        priority_queue<pt, vector<pt>, greater<pt>> que;
        d.assign(V, DINF);
        que.emplace(0.0, s);
        d[s] = 0.0;
        while (!que.empty())
        {
            pt p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first)
                continue;
            for (auto &&e : E[v])
            {
                if (d[e.to] > d[v] + e.cost)
                {
                    d[e.to] = d[v] + e.cost;
                    que.emplace(d[e.to], e.to);
                }
            }
        }
    }
};

struct point_t
{
    ld x, y;
    int exception = 0;
    constexpr point_t operator+(const point_t &p) const noexcept
    {
        return point_t{this->x + p.x, this->y + p.y};
    }
    constexpr point_t operator-(const point_t &p) const noexcept
    {
        return point_t{this->x - p.x, this->y - p.y};
    }
};

struct line_t
{
    ld a, b, c;
    int exception = 0;
};

inline bool Same(point_t &p1, point_t &p2)
{
    return (abs(p1.x - p2.x) < EPS && abs(p1.y - p2.y) < EPS);
}

inline ld Dist(point_t &p1, point_t &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

inline point_t Rotate(point_t &p, ld theta)
{
    return point_t{p.x * cos(theta) - p.y * sin(theta), p.x * sin(theta) + p.y * cos(theta)};
}

line_t Line2p(point_t &p1, point_t &p2)
{
    if (Same(p1, p2))
        return line_t{0, 0, 0, 1};
    line_t res;
    res.a = p2.y - p1.y;
    res.b = p1.x - p2.x;
    res.c = (p2.x - p1.x) * p1.y - (p2.y - p1.y) * p1.x;
    return res;
}

line_t VerticalLine(point_t &p, line_t &l)
{
    line_t res;
    res.a = l.b;
    res.b = -l.a;
    res.c = l.a * p.y - l.b * p.x;
    return res;
}

point_t Intersection(line_t &l1, line_t &l2)
{
    point_t res;
    if (abs(l1.a * l2.b - l1.b * l2.a) < EPS || abs(l1.b * l2.a - l1.a * l2.b) < EPS)
        return point_t{0, 0, 1};
    res.x = (l1.b * l2.c - l1.c * l2.b) / (l1.a * l2.b - l1.b * l2.a);
    res.y = (l1.a * l2.c - l1.c * l2.a) / (l1.b * l2.a - l1.a * l2.b);
    return res;
}

inline bool OnLineseg(point_t &p, point_t &L, point_t &R)
{
    if (abs(L.x - R.x) < EPS && abs(L.y - R.y) < EPS)
        return abs(L.x - p.x) < EPS;
    if (abs(L.x - R.x) < EPS)
    {
        ld k = (p.y - L.y) / (R.y - L.y);
        return (0.0 <= k && k <= 1.0);
    }
    else
    {
        ld k = (p.x - L.x) / (R.x - L.x);
        return (0.0 <= k && k <= 1.0);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(50) << setiosflags(ios::fixed);

    while (1)
    {
        int n, start, goal;
        cin >> n >> start >> goal;
        if (n == 0)
            return 0;
        start--, goal--;
        vector<ld> x(n), y(n), a(n), r(n);
        rep(i, n)
        {
            cin >> x[i] >> y[i] >> a[i] >> r[i];
            a[i] = a[i] * PI / 180.0;
        }
        vector<vector<point_t>> vp;
        vp.resize(n);
        rep(i, n)
        {
            point_t center = {x[i], y[i]};
            rep(ri, 5)
            {
                point_t p = {x[i], y[i] + r[i]};
                ld theta = 4.0 / 5.0 * PI * ld(ri) + a[i];
                p = p - center;
                p = Rotate(p, theta);
                p = p + center;
                vp[i].push_back(p);
            }
            vp[i].push_back(vp[i][0]);
        }

        dijkstra ds(n);
        rep(i, n) REP(j, i + 1, n)
        {
            ld Min = DINF;
            // 点と点
            rep(ii, 5) rep(jj, 5)
            {
                Min = min(Min, Dist(vp[i][ii], vp[j][jj]));
            }

            //点と線分
            rep(ii, 5) rep(jj, 5)
            {
                point_t p = vp[i][ii], L = vp[j][jj], R = vp[j][jj + 1];
                line_t l = Line2p(L, R);
                if (l.exception != 0)
                    continue;
                line_t m = VerticalLine(p, l);
                if (m.exception != 0)
                    continue;
                point_t q = Intersection(l, m);
                if (q.exception != 0)
                    continue;
                if (OnLineseg(q, L, R))
                    Min = min(Min, Dist(p, q));
            }

            //線分と点
            rep(ii, 5) rep(jj, 5)
            {
                point_t p = vp[j][ii], L = vp[i][jj], R = vp[i][jj + 1];
                line_t l = Line2p(L, R);
                if (l.exception != 0)
                    continue;
                line_t m = VerticalLine(p, l);
                if (m.exception != 0)
                    continue;
                point_t q = Intersection(l, m);
                if (q.exception != 0)
                    continue;
                if (OnLineseg(q, L, R))
                    Min = min(Min, Dist(p, q));
            }

            //線分と線分（交点があるかだけ調べる）
            rep(ii, 5) rep(jj, 5)
            {
                point_t L1 = vp[i][ii], R1 = vp[i][ii + 1];
                point_t L2 = vp[j][jj], R2 = vp[j][jj + 1];
                line_t l = Line2p(L1, R1);
                line_t m = Line2p(L2, R2);
                if (l.exception != 0)
                    continue;
                if (m.exception != 0)
                    continue;
                point_t p = Intersection(l, m);
                if (p.exception != 0)
                    continue;
                if (OnLineseg(p, L1, R1) && OnLineseg(p, L2, R2))
                    Min = 0.0;
            }

            ds.add_E(i, j, Min);
        }
        ds.calc(start);
        cout << ds.d[goal] << "\n";
    }
}
