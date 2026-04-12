#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
#define double long double
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

constexpr double eps=1e-9;
constexpr double PI=3.14159265358979323846264338327950;
 
inline int sgn(double x){
    if(x<-eps) return -1;
    if(x>eps) return 1;
    return 0;
}
 
inline bool EQ(double x, double y){
    return sgn(x-y)==0;
}
 
inline bool GE(double x, double y){
    return sgn(x-y)==1;
}
 
inline bool LE(double x, double y){
    return sgn(x-y)==-1;
}
 
inline bool GEQ(double x, double y){
    return sgn(x-y)>=0;
}
 
inline bool LEQ(double x, double y){
    return sgn(x-y)<=0;
}
 
struct Point{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y){}
 
    Point operator+(const Point &p){
        return {x+p.x, y+p.y};
    }
 
    Point operator-(const Point &p){
        return {x-p.x, y-p.y};
    }
 
    Point operator*(const double k){
        return {k*x, k*y};
    }
 
    Point operator/(const double k){
        return {x/k, y/k};
    }
 
    double operator*(const Point &p){
        return x*p.x+y*p.y;
    }
 
    double operator^(const Point &p){
        return x*p.y-y*p.x;
    }
 
    bool operator==(const Point &p){
        return EQ(x, p.x) && EQ(y, p.y);
    }
 
    bool operator<(const Point &p) const{
        if(EQ(x, p.x)) return LE(y, p.y);
        return LE(x, p.x);
    }
};

using Vec=Point;
using Polygon=vector<Point>;

double norm(Point p){
    return p.x*p.x+p.y*p.y;
}
 
double abs(Point p){
    return sqrt(norm(p));
}

Point rot(Point p, double t){
    return {p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)};
}

constexpr int CCW_COUNTER_CLOCKWISE=1; //反時計回り
constexpr int CCW_CLOCKWISE=-1; //時計回り
constexpr int CCW_ONLINE_BACK=-2; //一直線, C->A->B
constexpr int CCW_ONLINE_FRONT=2; //一直線, A->B->C
constexpr int CCW_ON_SEGMENT=0; //一直線, A->C->B
 
inline int ccw(Point a, Point b, Point c){
    Vec v=b-a, w=c-a;
    if(GE(v^w, 0)) return CCW_COUNTER_CLOCKWISE;
    if(LE(v^w, 0)) return CCW_CLOCKWISE;
    if(LE(v*w, 0)) return CCW_ONLINE_BACK;
    if(LE((a-b)*(c-b), 0)) return CCW_ONLINE_FRONT;
    return CCW_ON_SEGMENT;
}

bool intersectSS(Point a, Point b, Point c, Point d){
    return ccw(a, b, c)*ccw(a, b, d)<=0 && ccw(c, d, a)*ccw(c, d, b)<=0;
}

double getDistanceLP(Point a, Vec v, Point p){
    return abs(v^(p-a)/abs(v));
}

double getDistanceSP(Point a, Point b, Point p){
    if(LE((b-a)*(p-a), 0)) return abs(p-a);
    if(LE((a-b)*(p-b), 0)) return abs(p-b);
    return getDistanceLP(a, b-a, p);
}

double getDistanceSS(Point a, Point b, Point c, Point d){
    if(intersectSS(a, b, c, d)) return 0;
    return min({getDistanceSP(a, b, c), getDistanceSP(a, b, d), getDistanceSP(c, d, a), getDistanceSP(c, d, b)});
}

int main(){
    int n, M, L;
    while(scanf("%d%d%d", &n, &M, &L) && n){
        --M; --L;
        Polygon p[n];
        rep(i, n){
            Point c; double a, r;
            scanf("%Lf%Lf%Lf%Lf", &c.x, &c.y, &a, &r);
            p[i].push_back({c.x, c.y+r});

            For(k, 1, 5) p[i].push_back(c+rot(p[i][0]-c, PI*72*k/180));

            rep(k, 5) p[i][k] = c+rot(p[i][k]-c, PI*a/180);
        }

        double d[n][n];
        rep(i, n){
            rep(j, n)if(i != j){
                double tmp = INF;
                rep(k, 5)rep(l, 5){
                    chmin(tmp, getDistanceSS(p[i][k], p[i][(k+2)%5], p[j][l], p[j][(l+2)%5]));
                }
                d[i][j] = tmp;
            }
            d[i][i] = 0;
        }

        rep(k, n)rep(i, n)rep(j, n){
            chmin(d[i][j], d[i][k] + d[k][j]);
        }
        printf("%.20Lf\n", d[M][L]);
    }
}
