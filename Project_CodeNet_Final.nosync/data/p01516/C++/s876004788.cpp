#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);

using Point = complex<double>;
using Polygon = vector<Point>;

inline int sgn(const double &a) { return (a < -EPS ? -1 : (a > EPS ? 1 : 0)); }

inline bool eq(const Point &a, const Point &b) { return abs(a - b) < EPS; }

namespace std {
inline bool operator<(const Point &a, const Point &b) {
    if (sgn(a.real() - b.real()))
        return sgn(a.real() - b.real()) < 0;
    return sgn(a.imag() - b.imag()) < 0;
}
} // namespace std;

double dot(const Point &a, const Point &b) { return real(conj(a) * b); }

double det(const Point &a, const Point &b) { return imag(conj(a) * b); }

struct Line {
    Point p1, p2;

    Line(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}

    bool operator<(const Line &rhs) const {
        if (eq(p2, rhs.p2))
            return p1 < rhs.p1;
        return p2 < rhs.p2;
    }
    bool operator==(const Line &rhs) const {
        return (eq(p1, rhs.p1) && eq(p2, rhs.p2)) ||
               (eq(p1, rhs.p2) && eq(p2, rhs.p1));
    }
};

inline Point curr(const Polygon &p, const int &i) { return p[i % p.size()]; }

inline Point next(const Polygon &p, const int &i) {
    return p[(i + 1) % p.size()];
}

inline Point prev(const Polygon &p, const int &i) {
    return p[(i + p.size() - 1) % p.size()];
}

enum CCW {
    ONLINE_FRONT = -2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK
};

int ccw(Point p0, Point p1, Point p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (sgn(det(a, b)) == 1)
        return COUNTER_CLOCKWISE;
    if (sgn(det(a, b)) == -1)
        return CLOCKWISE;
    if (sgn(dot(a, b)) == -1)
        return ONLINE_BACK;
    if (sgn(norm(b) - norm(a)) == 1)
        return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersectLS(Line a, Line b, bool segflag) {
    if (segflag)
        return (ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2) <= 0) &&
               (ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2) <= 0);
    else
        return (sgn(det(a.p2 - a.p1, b.p1 - a.p1) *
                    det(a.p2 - a.p1, b.p2 - a.p1)) <= 0) &&
               (sgn(det(b.p2 - b.p1, a.p1 - b.p1) *
                    det(b.p2 - b.p1, a.p2 - b.p1)) <= 0);
}

double distanceLP(Line line, Point p) {
    return abs(det(line.p2 - line.p1, p - line.p1)) / abs(line.p2 - line.p1);
}

double distanceSP(Line line, Point p) {
    if (sgn(dot(line.p2 - line.p1, p - line.p1)) < 0)
        return abs(p - line.p1);
    if (sgn(dot(line.p1 - line.p2, p - line.p2)) < 0)
        return abs(p - line.p2);
    return distanceLP(line, p);
}

double distanceSS(Line s1, Line s2) {
    if (intersectLS(s1, s2, true))
        return 0;
    double d1 = distanceSP(s1, s2.p1);
    double d2 = distanceSP(s1, s2.p2);
    double d3 = distanceSP(s2, s1.p1);
    double d4 = distanceSP(s2, s1.p2);
    return min({d1, d2, d3, d4});
}

vector<Line> make_star(double x, double y, double a, double r) {
    Point c(0, r);
    vector<Point> v;
    for(int i=0;i<5;++i){
        double theta = (a + 72*i) * PI / 180.0;
        Point rot(cos(theta), sin(theta));
        v.push_back(c*rot + Point(x, y));
    }
    vector<Line> res;
    for(int i=0;i<5;++i){
        res.push_back(Line(v[i], v[(i+2)%5]));
    }
    return res;
}

double compute_distance(vector<Line> st1, vector<Line> st2) {
    double res = INF;
    for(auto l1: st1){
        for(auto l2: st2){
            double d = distanceSS(l1, l2);
            if(sgn(res - d) > 0)res = d;
        }
    }
    return res;
}

struct Edge{
    int from, to;
    double cost;
};

struct Node{
    int num;
    double cost;
    bool operator<(const Node &obj)const{
        return sgn(cost - obj.cost) > 0;
    }
};

double mini[102]={};

void init(int n, int m){
    for(int i=0;i<=n;++i)
        mini[i] = INF;
    mini[m] = 0;
}

int main(){
    int n, m, l;
    while(cin >> n >> m >> l, n != 0){
        init(n, m);
        vector<vector<Line>> stars;
        for(int i=0;i<n;++i){
            double x, y, a, r;
            cin >> x >> y >> a >> r;
            auto star = make_star(x, y, a, r);
            stars.push_back(star);
        }
        vector<vector<Edge>> graph(n+1, vector<Edge>());
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                double d = compute_distance(stars[i], stars[j]);
                graph[i+1].push_back({i+1, j+1, d});
                graph[j+1].push_back({j+1, i+1, d});
            }
        }
        priority_queue<Node> que;
        que.push({m, 0});
        while(!que.empty()){
            auto cur = que.top(); que.pop();
            if(cur.num == l){
                printf("%.10f\n", cur.cost);
                break;
            }
            for(auto e: graph[cur.num]){
                double new_cost = cur.cost + e.cost;
                if(sgn(mini[e.to] - new_cost) > 0){
                    mini[e.to] = new_cost;
                    que.push({e.to, new_cost});
                }
            }
        }
    }
    return 0;
}

