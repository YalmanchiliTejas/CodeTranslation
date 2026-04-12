#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 999999999
#define edge pair<pair<double,double>,pair<double,double>>
#define point pair<double,double>
#define PI 3.1415926535898
using namespace std;
struct star{
    double x;
    double y;
    double a;
    double r;
};

typedef double D;      // 座標値の型。doubleかlong doubleを想定
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;
const D EPS = 0.00000001;    // 許容誤差。問題によって変える
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {
  return (conj(a)*b).X;
}
// 外積　cross(a,b) = |a||b|sinθ
D cross(P a, P b) {
  return (conj(a)*b).Y;
}

// 点の進行方向
int ccw(P a, P b, P c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

/* 交差判定　直線・線分は縮退してはならない。接する場合は交差するとみなす。isecはintersectの略 */

// 直線と点
bool isecLP(P a1, P a2, P b) {
  return abs(ccw(a1, a2, b)) != 1;  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 直線と線分
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分と線分
bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(P a1, P a2, P b) {
  return !ccw(a1, a2, b);
}


/* 距離　各直線・線分は縮退してはならない */

// 点pの直線aへの射影点を返す
P proj(P a1, P a2, P p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
P reflection(P a1, P a2, P p) {
  return 2.0*proj(a1, a2, p) - p;
}

D distLP(P a1, P a2, P p) {
  return abs(proj(a1, a2, p) - p);
}

D distLL(P a1, P a2, P b1, P b2) {
  return isecLL(a1, a2, b1, b2) ? 0 : distLP(a1, a2, b1);
}

D distLS(P a1, P a2, P b1, P b2) {
  return isecLS(a1, a2, b1, b2) ? 0 : min(distLP(a1, a2, b1), distLP(a1, a2, b2));
}

D distSP(P a1, P a2, P p) {
  P r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  return min(abs(a1-p), abs(a2-p));
}

D distSS(P a1, P a2, P b1, P b2) {
  if (isecSS(a1, a2, b1, b2)) return 0;
  return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
             min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}


double min_star_dist(star a,star b){
    const complex<double> arg(cos(PI*72.0/180.0),sin(PI*72.0/180.0));
    vector<L> a_edges;
    vector<L> b_edges;
    vector<P> a_points;
    vector<P> b_points;
    complex<double> tmp;
    tmp=complex<double>(0,a.r);
    tmp*=complex<double>(cos(PI*a.a/180.0),sin(PI*a.a/180.0));
    rep(i,5){
        a_points.push_back(tmp+P(a.x,a.y));
        tmp*=arg;
    }
    tmp=complex<double>(0,b.r);
    tmp*=complex<double>(cos(PI*b.a/180.0),sin(PI*b.a/180.0));
    rep(i,5){
        b_points.push_back(tmp+P(b.x,b.y));
        tmp*=arg;
    }
    rep(i,5){
        a_edges.emplace_back(a_points[i],a_points[(i+2)%5]);
        b_edges.emplace_back(b_points[i],b_points[(i+2)%5]);
    }
    double ret=INF;
    rep(i,5){
        rep(j,5){
            if(isecSS(a_edges[i].first,a_edges[i].second,b_edges[j].first,b_edges[j].second)){
                return 0;
            }
            double t = distSP(a_edges[i].first,a_edges[i].second,b_points[j]);
            ret=(ret<t)?ret:t;
            t = distSP(b_edges[j].first,b_edges[j].second,a_points[i]);
            ret=(ret<t)?ret:t;
        }
    }
    return ret;
}

int main(void){
    int n,m,l;
    while(cin>>n>>m>>l,n){
        vector<star> stars(n);
        vector<vector<double>> dist(n,vector<double>(n,INF));
        rep(i,n){
            dist[i][i]=0;
            double a,b,c,d;
            cin>>a>>b>>c>>d;
            stars[i]=(star){a,b,c,d};
        }
        rep(i,n-1){
            for(int j=i+1;j<n;j++){
                dist[i][j]=dist[j][i]=min_star_dist(stars[i],stars[j]);
            }
        }
        rep(k,n)rep(i,n)rep(j,n){
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
        printf("%.10lf\n",dist[m-1][l-1]);
    }
}

