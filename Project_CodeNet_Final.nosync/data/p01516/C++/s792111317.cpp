#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=105,INF=1<<20;

#define double long double

const double eps=1e-10;
const double pi=acos((double)-1.0L);
#define equals(a,b) (fabs((a)-(b))<eps)

double torad(int deg) {return (double)(deg)*pi/180.0;}
double todeg(double ang) {return ang*180.0/pi;}

class Point{
public:
    double x,y;
    
    Point(double x=0,double y=0):x(x),y(y){}
    
    Point operator + (Point p){return Point(x+p.x,y+p.y);}
    Point operator - (Point p){return Point(x-p.x,y-p.y);}
    Point operator * (double a){return Point(a*x,a*y);}
    Point operator / (double a){return Point(x/a,y/a);}
    
    double abs(){return sqrt(norm());}
    double norm(){return x*x+y*y;}
    
    bool operator < (const Point &p)const{
        return x!=p.x ? x<p.x : y<p.y;
    }
    
    bool operator == (const Point &p)const{
        return fabs(x-p.x)<eps&&fabs(y-p.y)<eps;
    }
};

typedef Point Vector;

double norm(Vector a){
    return a.x*a.x+a.y*a.y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

struct Segment{
    Point p1,p2;
};

bool isOrthogonal(Vector a,Vector b){
    return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
    return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
    return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
    return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
    return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
    return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

Point reflect(Segment s,Point p){
    return p+(project(s,p)-p)*2.0;
}

static const int counter_clockwise=1;
static const int clockwise=-1;
static const int online_back=2;
static const int online_front=-2;
static const int on_segment=0;

int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    
    if(cross(a,b)>eps) return counter_clockwise;
    if(cross(a,b)<-eps) return clockwise;
    if(dot(a,b)<-eps) return online_back;
    if(a.norm()<b.norm()) return online_front;
    
    return on_segment;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
    return(ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

typedef Segment Line;

double getDistance(Point a,Point b){
    return abs(a-b);
}

double getDistanceLP(Line l,Point p){
    return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
    if(dot(s.p2-s.p1,p-s.p1)<0.0) return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0) return abs(p-s.p2);
    return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
    if(intersect(s1,s2)) return 0.0;
    return min({getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2),getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)});
}

Point getCrossPoint(Segment s1,Segment s2){
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}

class Circle{
public:
    Point c;
    double r;
    Circle(Point c=Point(),double r=0.0):c(c),r(r){}
};

pair<Point,Point> segCrossPpoints(Circle c,Line l){
    //assert(intersect(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return make_pair(pr+e*base,pr-e*base);
}

double arg(Vector p){return atan2(p.y,p.x);}
Vector polar(double a,double r){return Point(cos(r)*a,sin(r)*a);}

pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
    //assert(intersect(c1,c2));
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r-c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}

typedef vector<Point> Polygon;

/*
 IN 2
 ON 1
 OUT 0
 */

int contains(Polygon g,Point p){
    int n=int(g.size());
    bool x=false;
    for(int i=0;i<n;i++){
        Point a=g[i]-p,b=g[(i+1)%n]-p;
        if(a.y>b.y) swap(a,b);
        if(a.y<eps&&eps<b.y&&cross(a,b)>eps) x=!x;
    }
    return (x?2:0);
}

Polygon andrewScan(Polygon s,bool ok){
    Polygon u,l;
    sort(all(s));
    
    if(int(s.size())<3) return s;
    int n=int(s.size());
    
    u.push_back(s[0]);
    u.push_back(s[1]);
    
    l.push_back(s[n-1]);
    l.push_back(s[n-2]);
    
    if(ok){
        for(int i=2;i<n;i++){
            for(int j=int(u.size());j>=2&&ccw(u[j-2],u[j-1],s[i])==counter_clockwise;j--){
                u.pop_back();
            }
            u.push_back(s[i]);
        }
        
        for(int i=int(s.size())-3;i>=0;i--){
            for(int j=int(l.size());j>=2&&ccw(l[j-2],l[j-1],s[i])==counter_clockwise;j--){
                l.pop_back();
            }
            l.push_back(s[i]);
        }
    }
    
    if(!ok){
        for(int i=2;i<n;i++){
            for(int j=int(u.size());j>=2&&ccw(u[j-2],u[j-1],s[i])!=clockwise;j--){
                u.pop_back();
            }
            u.push_back(s[i]);
        }
        
        for(int i=int(s.size())-3;i>=0;i--){
            for(int j=int(l.size());j>=2&&ccw(l[j-2],l[j-1],s[i])!=clockwise;j--){
                l.pop_back();
            }
            l.push_back(s[i]);
        }
    }
    
    reverse(all(l));
    
    for(int i=int(u.size())-2;i>=1;i--) l.push_back(u[i]);
    
    return l;
}//ok==1なら辺の上も含める

double dis[MAX][MAX];
int N;

void floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        int s,g;cin>>N>>s>>g;
        if(N==0) break;
        s--;g--;
        vector<vector<Point>> A(N,vector<Point>(6));
        
        for(int i=0;i<N;i++){
            double x,y,a,r;cin>>x>>y>>a>>r;
            
            for(int j=0;j<6;j++){
                A[i][j]={x+r*cos(torad(a+90.0+144.0*j)),y+r*sin(torad(a+90.0+144.0*j))};
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dis[i][j]=INF;
            }
            dis[i][i]=0.0;
        }
        
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                if(a==b) continue;
                
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        Segment s1={A[a][i],A[a][i+1]};
                        Segment s2={A[b][j],A[b][j+1]};
                        dis[a][b]=min(dis[a][b],getDistance(s1,s2));
                    }
                }
            }
        }
        
        floyd();
        
        cout<<setprecision(25)<<dis[s][g]<<endl;
    }
}



