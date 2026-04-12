#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <iomanip>

using namespace std;

typedef complex<double> Point;
#define rep(i, n) for(int i=0; i<(n); ++i)
const double eps = 1e-8, inf = 1e8, pi = acos(-1.);

template<typename T> inline void chmin(T& t, T f){if(t > f)t = f;}

inline double cross(const Point& a, const Point& b){
    return imag(conj(a) * b);
}

inline double dot(const Point& a, const Point& b){
    return real(conj(a) * b);
}

int ccw(Point a, Point b, Point c){
    b -= a; c -= a;
    if(cross(b, c) > eps)return 1;
    if(cross(b, c) < -eps)return -1;
    if(dot(b, c) < 0)return 2;
    if(norm(b) < norm(c))return -2;
    return 0;
}

struct Line : vector<Point> {
    Line(const Point& a, const Point& b){
        push_back(a); push_back(b);
    }
};

inline Point proj(const Line& l, const Point& p){
    double t = dot(p - l[0], l[1] - l[0]) / norm(l[0] - l[1]);
    return l[0] + (l[1] - l[0]) * t;
}

inline bool interSP(const Line& s, const Point& p){
    return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < eps;
}

inline bool interSS(const Line& s, const Line& t){
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
           ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

inline double distSP(const Line& s, const Point& p){
    const Point r = proj(s, p);
    return interSP(s, r)? abs(r - p): min(abs(s[0] - p), abs(s[1] - p));
}

inline double distSS(const Line& s, const Line& t){
    return interSS(s, t)? 0: min(min(distSP(s, t[0]), distSP(s, t[1])), min(distSP(t, s[0]), distSP(t, s[1])));
}

int N, M, L;

double solve(vector<vector<Line> >& pent){
    vector<vector<double> > dist(N, vector<double>(N));
    rep(i, N)rep(j, i){
        dist[i][j] = inf;
        rep(k, 5)rep(l, 5)chmin(dist[i][j], distSS(pent[i][k], pent[j][l]));
        dist[j][i] = dist[i][j];
    }
    rep(k, N)rep(i, N)rep(j, N)chmin(dist[i][j], dist[i][k] + dist[k][j]);
    return dist[M][L];
}

int main(){
    while(cin >> N >> M >> L, N|M|L){
        M--; L--;
        vector<vector<Line> > pent(N);
        rep(i, N){
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            vector<Point> v;
            rep(j, 5)v.push_back(Point(x, y) + polar(1. * r, (a + 72 * j + 90) * pi / 180));
            rep(j, 5)pent[i].emplace_back(v[j], v[(j + 2) % 5]);
        }
        cout << fixed << setprecision(20) << solve(pent) << '\n';
    }
    return 0;
}