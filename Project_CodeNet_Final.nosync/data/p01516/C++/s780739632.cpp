#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>

using namespace std;

const double EPS (1e-8);
const double PI=acos(-1.0);

template<class T>
struct point{
    T x,y;
    point() : x(0), y(0) {}
    point(const T& x,const T& y) : x(x), y(y) {}
    point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
    void operator+=(const point &a){x += a.x; y += a.y;}
    point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
    void operator-=(const point &a){x -= a.x; y -= a.y;}
    point operator*(const double a)const{ return point(a*x,a*y); }
    point operator*=(const double a)const{ x *= a; y *= a; }
    point operator/(const double a)const{ return point(a/x,a/y); }
    point operator/=(const double a)const{ x /= a; y /= a; }
 
};

template<class T> T SQ(T x){ return x*x; }
template<class T> T dist2(const point<T> &a,const point<T> &b){return SQ(a.x-b.x)+SQ(a.y-b.y);}
template<class T> T abs(const point<T>& p){return sqrt(SQ(p.x) + SQ(p.y));}
template<class T> T dot(const point<T>& a,const point<T>& b)
{return a.x*b.x + a.y*b.y;}
template<class T> T cross(const point<T>& a,const point<T>& b)
{return a.x*b.y - a.y*b.x;}
template<class T> point<T> rot(const point<T>& a,const double theta){
        return point<T>(a.x*cos(theta)-a.y*sin(theta),
			a.x*sin(theta)+a.y*cos(theta));
}

enum{CCW=1,CW=-1,ON=0};
template<class T>
int ccw(const point<T> &a,const point<T> &b,const point<T> &c){
    double rdir=cross(b-a,c-a);
    if(rdir> EPS) return CCW; //cがabより上(反時計周り)
    if(rdir<-EPS) return CW; // cがabより下(時計周り)
    return ON; // a,b,cが一直線上
}

template<class T>
struct segment{
    point<T> a,b;
    segment() : a(point<T>()), b(point<T>()) {}
    segment(const point<T>& a,const point<T>& b) : a(a), b(b) {}
};

bool intersect(const segment<double> &S1,const segment<double> &S2){
    if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
    || max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
    || max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
    || max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
    return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
        && ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

template<class T>
double dist2(const segment<T> &S,const point<T> &p){
    if(dot(S.b-S.a,p-S.a)<=0) return dist2(p,S.a);
    if(dot(S.a-S.b,p-S.b)<=0) return dist2(p,S.b);
    return (double)SQ(cross(S.b-S.a,p-S.a)) / dist2(S.a,S.b);
}

template<class T>
double dist(const segment<T> &S1,const segment<T> &S2){
    if(intersect(S1,S2)) return 0;
    return sqrt(min(min(dist2(S1,S2.a),dist2(S1,S2.b)),
                    min(dist2(S2,S1.a),dist2(S2,S1.b))));
}

 
typedef point<double> P;
typedef segment<double> S;

template<class T>
std::ostream& operator<<(std::ostream& os, const point<T>& point){return ( os << '(' << point.x << ',' << point.y << ')' );}
template<class T>
std::ostream& operator<<(std::ostream& os, const segment<T>& seg){return ( os << '{' << seg.a << ',' << seg.b << '}' );}


typedef point<double> P;
typedef segment<double> S;

#define rep(i,n) for(int i=0;i<(n);i++)

struct star{
    point<double> c;
    double a,r;
    point<double> p[5];
};

int main(){
    for(int n,m,l;scanf("%d%d%d",&n,&m,&l),n||m||l;){
        m--;
        l--;
  
        star S[100];
        rep(i,n){
            scanf("%lf%lf%lf%lf",&S[i].c.x,&S[i].c.y,&S[i].a,&S[i].r);
        }
  
        rep(i,n){
            S[i].p[0].x = 0, S[i].p[0].y = S[i].r;
            S[i].p[0]=rot(S[i].p[0],S[i].a/180*PI);
            for(int j=1;j<5;j++){
                S[i].p[j]=rot(S[i].p[j-1],2*PI/5);
            }
            rep(j,5) S[i].p[j]=S[i].p[j]+S[i].c;
        }
  
        int f1[]={0,2,4,1,3,0};
  
        double d[100][100];
        rep(i,n){
            rep(j,n) {
				d[i][j] = 1e100;
				rep(a,5) rep(b,5){
					segment<double> s(S[i].p[f1[a]],S[i].p[f1[a+1]]);
					segment<double> t(S[j].p[f1[b]],S[j].p[f1[b+1]]);
					d[i][j]=min(d[i][j],dist(s,t));
				}
            }
        }
  
        rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  
        printf("%.15f\n",d[m][l]);
    }
  
    return 0;
}