#include<bits/stdc++.h>
using namespace std;

typedef complex<double>Point;

struct Segment{
    Point p1,p2;
    Segment(const Point &p1=Point(),const Point &p2=Point()):p1(p1),p2(p2){}
};

struct Circle{
    Point p;
    double r;
    Circle(const Point &p=Point(),double r=0.0):p(p),r(r){}
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point>Polygon;

const double PI=acos(-1);
const double EPS=1e-8;
const double INF=1e16;
const int COUNTER_CLOCKWISE=1;
const int CLOCKWISE=-1;
const int ONLINE_BACK=2;
const int ONLINE_FRONT=-2;
const int ON_SEGMENT=0;

inline double square(double a){return a*a;}
inline double norm(const Point &a){return square(a.real())+square(a.imag());}
inline double dot(const Point &a,const Point &b){return (conj(a)*b).real();}
inline double cross(const Point &a,const Point &b){return (conj(a)*b).imag();}
inline double toDeg(double t){return t/PI*180.0;}
inline double toRad(double t){return t/180.0*t;}
#define equals(a,b) (fabs((a)-(b))<EPS)

void getPoint(Point &p){
    double x,y;
    scanf("%lf%lf",&x,&y);
    p=Point(x,y);
}

void getSegment(Segment &s){
    getPoint(s.p1);
    getPoint(s.p2);
}

bool orthogonal(Vector a,Vector b){
    return equals(dot(a,b),0.0);
}

bool orthogonal(Point a1,Point a2,Point b1,Point b2){
    return orthogonal(a1-a2,b1-b2);
}

bool orthogonal(Segment s1,Segment s2){
    return orthogonal(s1.p1-s1.p2,s2.p1-s2.p2);
}

bool parallel(Vector a,Vector b){
    return equals(cross(a,b),0.0);
}

bool parallel(Point a1,Point a2,Point b1,Point b2){
    return parallel(a1-a2,b1-b2);
}

bool parallel(Segment s1,Segment s2){
    return parallel(s1.p1-s1.p2,s2.p1-s2.p2);
}

Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

Point reflection(Segment s,Point p){
    return p+(project(s,p)-p)*2.0;
}

int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS)return COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS)return CLOCKWISE;
    if(dot(a,b)<-EPS)return ONLINE_BACK;
    if(norm(a)<norm(b))return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
    return ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0;
}

bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

Point getCrossPoint(Segment s1,Segment s2){
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));

    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}

void push(Point p){
    printf("%.20f %.20f\n",real(p),imag(p));
}

int main(){
    int N,K;
    cin>>N>>K;
    double t=2*PI/N;
    double a=(2*PI-2*t*K)/4;
    double s=t+2*a;
    double l=2*PI/N;

    double x=abs(polar(1.0,0.0)-polar(1.0,t));
    double h=x/2/tan(s/2);
    double S=h*x/2;
    h=x/2/tan(t/2);
    S+=t/2-h*x/2;
    printf("%.20f\n",PI-S*N);
    return 0;
}