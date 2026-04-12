#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
#define EPS (1e-10)
using namespace std;

double add(double a, double b)
{

    if (abs(a + b) < EPS * (abs(a) + abs(b)))
        return 0;
    return a + b;
}

struct P
{
    double x, y;
    P(){};
    P(double x, double y) : x(x), y(y) {}
    P operator+(P p)
    {
        return (P(add(x, p.x), add(y, p.y)));
    }
    P operator-(P p)
    {
        return (P(add(x, -p.x), add(y, -p.y)));
    }
    P operator*(double k)
    {
        return (P(k * x, k * y));
    }
    double dot(P p)
    {
        return add(x * p.x, y * p.y);
    }
    double det(P p)
    {
        return add(x * p.y, -y * p.x);
    }
};
typedef P Vector;
struct Seg
{
    P p1, p2;
    Seg() {}
    Seg(P p1, P p2) : p1(p1), p2(p2) {}
};
//点qが線分p1-p2上にあるか
bool on_seg(P p1, P p2, P q)
{
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
P intersection(P p1, P p2, P q1, P q2)
{
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

//三辺の長さがそれぞれa,b,cの三角形の面積を求める
double heron(double a, double b, double c)
{
    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// p1-p2の線分の長さを求める
double distPP(P p1, P p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 線分p1-p2と点qの長さを求める
double distLP(P p1, P p2, P q)
{
    if ((p2 - p1).dot(q - p1) < 0.0)
    {
        return distPP(p1, q);
    }
    if ((p1 - p2).dot(q - p2) < 0.0)
    {
        return distPP(p2, q);
    }
    return abs((p2 - p1).det(q - p1) / distPP(p2, p1));
}

//線分p1-p2とq1-q2が交差しているならtrue、そうでないならfalse
bool isCrossed(P p1, P p2, P q1, P q2)
{
    P pi = intersection(p1, p2, q1, q2);
    return (on_seg(p1, p2, pi) && on_seg(q1, q2, pi));
}

//線分p1-p2とq1-q2の最小距離を求める
double distLL(P p1, P p2, P q1, P q2)
{
    if (isCrossed(p1, p2, q1, q2))
    {
        return 0.0;
    }
    else
    {
        return min({distLP(p1, p2, q1), distLP(p1, p2, q2), distLP(q1, q2, p1), distLP(q1, q2, p2)});
    }
}
double distLL(Seg s1, Seg s2)
{
    return distLL(s1.p1, s1.p2, s2.p1, s2.p2);
}

double deg2rad(int n)
{
    return (double)n * M_PI / 180.0;
}

struct Star
{
    double x, y, a, r;
    P p[5];
    Seg s[5];
    Star(){};

    Star(double x, double y, double a, double r) : x(x), y(y), a(a), r(r)
    {
        rep(i, 5)
        {
            p[i] = P(x + r * cos(deg2rad(90 + a + 72 * i)), y + r * sin(deg2rad(90 + a + 72 * i)));
        }
        rep(i, 5)
        {
            s[i] = Seg(p[i], p[(i + 2) % 5]);
        }
    }
};

int main(int argc, char const *argv[])
{
    while (true)
    {
        int n, m, l;
        cin >> n >> m >> l;
        if (n == 0)
            break;
        Star star[n];
        rep(i, n)
        {
            double x, y, a, r;
            cin >> x >> y >> a >> r;
            star[i] = Star(x, y, a, r);
        }
        double dist[n][n];

        rep(i, n) rep(j, n)
        {
            dist[i][j] = 101010.0;
            rep(a, 5) rep(b, 5)
            {
                dist[i][j] = min(dist[i][j], distLL(star[i].s[a], star[j].s[b]));
            }
        }
        rep(i, n) rep(j, n) rep(k, n)
        {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        rep(i, n) rep(j, n) rep(k, n)
        {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        rep(i, n) rep(j, n) rep(k, n)
        {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }

        cout << setprecision(16) << dist[l - 1][m - 1] << endl;
    }
    return 0;
}

