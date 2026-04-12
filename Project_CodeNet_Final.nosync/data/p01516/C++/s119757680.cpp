#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <complex>

using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) loop(i,0,b)
double const pi = acos(-1);
double const inf = 1e100;
double const eps = 1e-8;

typedef complex<double> point;
typedef vector<point> polygon;

inline double cross(const point& a, const point& b) {
    return imag(conj(a)*b);
}

inline double dot(const point& a, const point& b) {
    return real(conj(a)*b);
}

struct line : public vector<point> {
    line(const point &a, const point &b) {
        push_back(a); push_back(b);
    }
};

inline int ccw(point a, point b, point c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // counter clockwise
    if (cross(b, c) < 0)   return -1;       // clockwise
    if (dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}

bool intersectSS(const line &s, const line &t) {
    return
        ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
        ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

point projection(const line &l, const point &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}

bool intersectSP(const line &s, const point &p) {
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < eps; // triangle inequality
}

double distanceSP(const line &s, const point &p) {
    const point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}

double distanceSS(const line &s, const line &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s,t[0]), distanceSP(s,t[1])),
               min(distanceSP(t,s[0]), distanceSP(t,s[1])));
}

int N,M,L;
double x[128], y[128], a[128], r[128];

double u = 2*pi/5;
double distanceStarStar(int s1, int s2){
    point p1(x[s1],y[s1]), p2(x[s2],y[s2]);
    double r1=r[s1], r2=r[s2], t1=a[s1], t2=a[s2];
    double res = inf;
    rep(i1,5)rep(i2,5){
        line l1(p1 + polar(r1,t1+u*i1 + pi/2),
                p1 + polar(r1,t1+u*(2+i1) + pi/2));
        line l2(p2 + polar(r2,t2+u*i2 + pi/2),
                p2 + polar(r2,t2+u*(2+i2) + pi/2));
        res = min(res, distanceSS(l1,l2));
        if(abs(res)<eps) return 0;
    }
    return res;
}

double solve(){
    M--; L--;
    double d[128][128];
    rep(i,N)loop(j,i,N){
        d[i][j] = i==j ? 0 : distanceStarStar(i,j);
        d[j][i] = d[i][j];
    }
    rep(k,N)rep(i,N)rep(j,N){
        d[i][j] = min(d[i][k]+d[k][j], d[i][j]);
    }
    return d[M][L];
}

int main(){
    while(scanf("%d%d%d",&N,&M,&L), N|M|L){
        rep(i,N){
            scanf("%lf%lf%lf%lf",x+i,y+i,a+i,r+i);
            a[i]=a[i]*pi/180;
        }
        printf("%.20lf\n",solve());
    }
}