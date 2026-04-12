#include <bits/stdc++.h>

//???????????????http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2402

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long double ld;
typedef complex<ld> Point;

const ld eps = 1e-9, pi = acos(-1.0);

const int INF = numeric_limits<int>::max() / 2;
const double PI = 3.14159265358979323846;

namespace std
{
bool operator<(const Point &lhs, const Point &rhs)
{
    if (lhs.real() < rhs.real() - eps)
        return true;
    if (lhs.real() > rhs.real() + eps)
        return false;
    return lhs.imag() < rhs.imag();
}
} // namespace std

// ????????\???
Point input_point()
{
    ld x, y;
    cin >> x >> y;
    return Point(x, y);
}

// ????????????????????????
bool eq(ld a, ld b)
{
    return (abs(a - b) < eps);
}

// ??????
ld dot(Point a, Point b)
{
    return real(conj(a) * b); //conj::??±???????´???°
}

// ??????
ld cross(Point a, Point b)
{
    return imag(conj(a) * b);
}

// ??´????????????
class Line
{
  public:
    Point a, b;
    Line() : a(Point(0, 0)), b(Point(0, 0)) {}
    Line(Point a, Point b) : a(a), b(b) {}
};

// ????????????
class Circle
{
  public:
    Point p;
    ld r;
    Circle() : p(Point(0, 0)), r(0) {}
    Circle(Point p, ld r) : p(p), r(r) {}
};

// CCW::counter clockwise
int ccw(Point a, Point b, Point c)
{
    b -= a;
    c -= a;
    if (cross(b, c) > eps)
        return 1; // a,b,c??????????¨???¨?????????????????¶
    if (cross(b, c) < -eps)
        return -1; // a,b,c???????¨???¨?????????????????¶
    if (dot(b, c) < 0)
        return 2; // c,a,b???????????´???????????¶
    if (norm(b) < norm(c))
        return -2; // a,b,c???????????´???????????¶
    return 0;      // a,c,b???????????´???????????¶
}

/* ???????????? */

// ??´?????¨??´??????????????????
//l::??´??????s::??????
bool isis_ll(Line l, Line m)
{
    return !eq(cross(l.b - l.a, m.b - m.a), 0);
}

// ??´?????¨?????????????????????
bool isis_ls(Line l, Line s)
{
    return isis_ll(l, s) &&
           (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

// ????????¨?????????????????????
bool isis_ss(Line s, Line t)
{
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
           ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

// ????????´????????????
bool isis_lp(Line l, Point p)
{
    return (abs(cross(l.b - p, l.a - p)) < eps);
}

// ?????????????????????
bool isis_sp(Line s, Point p)
{
    return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

// ??????????¶?
Point proj(Line l, Point p)
{
    ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    //norm::??¶?????????2???
    return l.a + t * (l.a - l.b);
}

// ??´?????¨??´????????????
Point is_ll(Line s, Line t)
{
    Point sv = s.b - s.a, tv = t.b - t.a;
    assert(cross(sv, tv) != 0);
    return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

// ??´?????¨???????????¢
ld dist_lp(Line l, Point p)
{
    return abs(p - proj(l, p));
}

// ??´?????¨??´???????????¢
ld dist_ll(Line l, Line m)
{
    return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

// ??´?????¨??????????????¢
ld dist_ls(Line l, Line s)
{
    return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

// ????????¨???????????¢
ld dist_sp(Line s, Point p)
{
    Point r = proj(s, p);
    return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// ????????¨??????????????¢
ld dist_ss(Line s, Line t)
{
    if (isis_ss(s, t))
        return 0;
    return min({dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b)});
}

/* ??? */

// ?????¨????????????
vector<Point> is_cc(Circle c1, Circle c2)
{
    vector<Point> res;
    ld d = abs(c1.p - c2.p);
    ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
    ld dfr = c1.r * c1.r - rc * rc;
    if (abs(dfr) < eps)
        dfr = 0.0;
    else if (dfr < 0.0)
        return res; // no intersection
    ld rs = sqrt(dfr);
    Point diff = (c2.p - c1.p) / d;
    res.push_back(c1.p + diff * Point(rc, rs));
    if (dfr != 0.0)
        res.push_back(c1.p + diff * Point(rc, -rs));
    return res;
}

// ?????¨??´????????????
vector<Point> is_lc(Circle c, Line l)
{
    vector<Point> res;
    ld d = dist_lp(l, c.p);
    if (d < c.r + eps)
    {
        ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;
        Point nor = (l.a - l.b) / abs(l.a - l.b);
        res.push_back(proj(l, c.p) + len * nor);
        res.push_back(proj(l, c.p) - len * nor);
    }
    return res;
}

// ?????¨??????????????¢
vector<Point> is_sc(Circle c, Line l)
{
    vector<Point> v = is_lc(c, l), res;
    for (Point p : v)
        if (isis_sp(l, p))
            res.push_back(p);
    return res;
}

// ?????¨????????\???
vector<Line> tangent_cp(Circle c, Point p)
{
    vector<Line> ret;
    Point v = c.p - p;
    ld d = abs(v);
    ld l = sqrt(norm(v) - c.r * c.r);
    if (isnan(l))
    {
        return ret;
    }
    Point v1 = v * Point(l / d, c.r / d);
    Point v2 = v * Point(l / d, -c.r / d);
    ret.push_back(Line(p, p + v1));
    if (l < eps)
        return ret;
    ret.push_back(Line(p, p + v2));
    return ret;
}

// ?????¨????????\???
vector<Line> tangent_cc(Circle c1, Circle c2)
{
    vector<Line> ret;
    if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps)
    {
        Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
        ret = tangent_cp(c1, center);
    }
    if (abs(c1.r - c2.r) > eps)
    {
        Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
        vector<Line> nret = tangent_cp(c1, out);
        ret.insert(ret.end(), ALL(nret));
    }
    else
    {
        Point v = c2.p - c1.p;
        v /= abs(v);
        Point q1 = c1.p + v * Point(0, 1) * c1.r;
        Point q2 = c1.p + v * Point(0, -1) * c1.r;
        ret.push_back(Line(q1, q1 + v));
        ret.push_back(Line(q2, q2 + v));
    }
    return ret;
}

/* ????§???¢ */

typedef vector<Point> Polygon;

// ??¢???
ld area(const Polygon &p)
{
    ld res = 0;
    int n = p.size();
    REP(j, n)
    res += cross(p[j], p[(j + 1) % n]);
    return res / 2;
}

// ????§???¢????????¢??????
bool is_counter_clockwise(const Polygon &poly)
{
    ld angle = 0;
    int n = poly.size();
    REP(i, n)
    {
        Point a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
        angle += arg((c - b) / (b - a));
    }
    return angle > eps;
}

int main()
{

    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true)
    {
        int n, m, l;
        cin >> n >> m >> l;

        if (n == 0)
            break;

        Polygon stars[n];
        ld dis[n][n];

        for (int i = 0; i < n; i++)
        {
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            for (int j = 0; j < 5; j++)
            {
                Point v = Point(x, y) + Point(r * cos((18 + a + 72 * j) * (2 * PI) / 360), r * sin((18 + a + 72 * j) * (2 * PI) / 360));
                stars[i].push_back(v);
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    dis[i][j] = 0.0;
                else
                    dis[i][j] = INF;
            }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ld tmp = INF;
                for (int k = 0; k < 5; k++)
                {
                    for (int l = 0; l < 5; l++)
                    {
                        Line x = Line(stars[i][k], stars[i][(k + 2) % 5]);
                        Line y = Line(stars[j][l], stars[j][(l + 2) % 5]);
                        tmp = min(tmp, dist_ss(x, y));
                    }
                }
                dis[i][j] = tmp;
                dis[j][i] = tmp;
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int k = 0; k < n; k++)
                {
                    dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
                }
            }
        }

        cout << setprecision(10) << dis[m - 1][l - 1] << endl;
    }

    return 0;
}
