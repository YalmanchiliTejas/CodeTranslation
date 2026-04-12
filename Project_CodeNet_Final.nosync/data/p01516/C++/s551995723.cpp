#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

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
inline double toRad(double t){return t/180.0*PI;}
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

bool isOrthogonal(Vector a,Vector b){
    return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
    return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
    return isOrthogonal(s1.p1-s1.p2,s2.p1-s2.p2);
}

bool isParallel(Vector a,Vector b){
    return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
    return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
    return isParallel(s1.p1-s1.p2,s2.p1-s2.p2);
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

bool isIntersectSS(Point p1,Point p2,Point p3,Point p4){
    return ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0;
}

bool isIntersectSS(Segment s1,Segment s2){
    return isIntersectSS(s1.p1,s1.p2,s2.p1,s2.p2);
}

Point getCrossPointSS(Segment s1,Segment s2){
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));

    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}

double getDistancePP(Point a,Point b){
    return abs(a-b);
}

double getDistanceLP(Line l,Point p){
    return fabs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceLL(Line l,Line m){
    if(isParallel(l,m))return getDistanceLP(l,m.p1);
    return 0.0;
}

double getDistanceSP(Segment s,Point p){
    if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
    return getDistanceLP(s,p);
}

double getDistanceSS(Segment s1,Segment s2){
    if(isIntersectSS(s1,s2))return 0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
               min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}


int N,M,L;
Segment s[1000];

double D[1000];


void solve(){
    M--;L--;
    Point rot(cos(toRad(72)),sin(toRad(72)));

    rep(i,N){
        double x,y,a,r;
        cin>>x>>y>>a>>r;
        Point p0(x,y);
        Point p(0,r);
        p*=Point(cos(toRad(a)),sin(toRad(a)));
        for(int j=0;j<5;j++){
            s[i*5+j]=Segment(p0+p,p0+p*rot*rot);
            p*=rot;
        }
    }

    fill_n(D,N*5,1e12);
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>que;
    rep(i,5)D[M*5+i]=0,que.push({0,M*5+i});

    while(que.size()){
        double d;
        int v;
        tie(d,v)=que.top();
        que.pop();
        if(D[v]<d)continue;

        rep(i,N*5){
            double cost=getDistanceSS(s[v],s[i]);
            if(D[i]<=D[v]+cost)continue;
            D[i]=D[v]+cost;
            que.push({D[i],i});
        }
    }

    double ans=1e12;
    rep(i,5)chmin(ans,D[L*5+i]);
    printf("%.20f\n",ans);
}
signed main(){
    while(cin>>N>>M>>L,N||M||L)solve();
    return 0;
}