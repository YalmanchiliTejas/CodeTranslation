#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<assert.h>
#include <math.h>
#include<iomanip>
using namespace std;
#define OUT 0
#define ON 1
#define IN 2
#define EPS (1e-10)
class P{                    //???
public:
    double x,y;
    
    P(double _x=0,double _y=0):x(_x),y(_y){};
    P operator + (const P &p     )const{ return P( x+p.x , y+p.y ); }  //??????
    P operator - (const P &p     )const{ return P( x-p.x , y-p.y ); }  //??????
    P operator * (const double k )const{ return P( x*k   , y*k    ); } //??????
    P operator / (const double k )const{ return P( x/k   , y/k    ); } //??????
    
    bool operator == (const P &p){ return ( fabs(x-p.x)<EPS && fabs(y-p.y)<EPS ); }
    bool operator < (const P &p) const{ return ( x!=p.x ? x<p.x:y<p.y ); }
    
    double norm(){ return x*x+y*y; }        //?????????
    double abs() { return sqrt(norm()); }   //??§??????
    void normalize() {double d = sqrt(x*x+y*y); x /= d; y /= d;}	//??£??????
};
struct C{P p;double r;};    //???
struct S{P p1,p2;};         //??????
typedef vector<P> Polygon;  //????§???¢
typedef P Vector;           //????????????
typedef S L;                //??´???

double norm (P p)               { return p.norm(); }
double abs  (P p)               { return p.abs(); }
double dot  (Vector a,Vector b) { return a.x*b.x+a.y*b.y; }
double cross(Vector a,Vector b) { return a.x*b.y-a.y*b.x; }
double sqDist(P a, P b)         {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
double dist (P a, P b)          {return sqrt(sqDist(a,b));}
Vector vec(S a)                 {return P(a.p2.x-a.p1.x,a.p2.y-a.p1.y);}

int ccw(P p0,P p1,P p2){    //AOJ_BOOK_P386 verified
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    
    if( cross(a,b) > EPS  ) return 1 ;      //COUNTER_CLOCKWISE
    if( cross(a,b) < -EPS ) return -1;      //CLOCKWISE
    if( dot(a,b)   < -EPS ) return 2;       //ONLINE_BACK
    if( a.norm()   < b.norm() ) return -2;  //ONLINE_FRONT
    
    return 0;                               //ON_SEGMENT;
}

// ??´?????¨??´???????????? vefiried AOJ CGL_2
P getCrossPointSS(S l1, S l2){
    double A = cross(vec(l1), vec(l2));
    double B = cross(vec(l1), l1.p2 - l2.p1);
    if(abs(A)<EPS && abs(B)<EPS) return l2.p1; // ?????´??????????????£?????????
    if(abs(A)<EPS) assert(false); // ??´?????????????????????
    return l2.p1 + vec(l2) * B / A;
}

//????????¨???????????¢ verified ARC042-B
double dLP(S l, P p) { return abs(cross(l.p2-l.p1, p-l.p1)) /(l.p2-l.p1).abs(); }

int main() {
    // source code
    int n, k;
    cin >> n >> k;
    double theta = (360.0/n)*(acos(-1)/180.0);
    P p = P(0, 1);
    vector<P> vp;
    for(int i = 0; i < n; i++){
        vp.push_back(P(p.x*cos(i*theta) - p.y*sin(i*theta),
                       p.x*sin(i*theta) + p.y*cos(i*theta)));
    }
    double area = cross(vp[0], vp[1])/2.0;
    S a = S{vp[0], vp[k]};
    S b = S{vp[(1-k+n)%n], vp[1]};
    P cp = getCrossPointSS(a, b);
    //double dist = seg_to_point_dis(line(vp[0], vp[1]), cp);
    double d = dLP(S{vp[0], vp[1]}, cp);
    cout << setprecision(12) << (area - dist(vp[0], vp[1])*d/2)*n << endl;
    return 0;
}