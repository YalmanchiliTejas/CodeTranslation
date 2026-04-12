#include<bits/stdc++.h>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
 
using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator + (Point &p) {return Point(x+p.x,y+p.y);}
  Point operator - (Point &p) {return Point(x-p.x,y-p.y);}
  Point operator * (double k) {return Point(x*k,y*k);}
  Point operator / (double k) {return Point(x/k,y/k);}
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

struct Circle{
  Point c;
  double r;
  Circle(Point c,double r):c(c),r(r){}
};

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
int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CLOCKWISE;
  if(dot(a,b) < -EPS) return ONLINE_BACK;
  if(a.norm()<b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
	  ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
  if(intersect(s1,s2)) return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
	     min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

const double PI = 3.1415926535;
int main(){
  int n,m,l;
  while(cin>>n>>m>>l,n){
    m--;l--;
    int i,j,k,s,t;
    double x,y,a,r;
    Segment star[n][5];
    for(i=0;i<n;i++){
      cin>>x>>y>>a>>r;
      Point p[5];
      for(j=0;j<5;j++) {
	p[j].x=x-r*sin(PI/180.0*(a+72.0*j));
	p[j].y=y+r*cos(PI/180.0*(a+72.0*j));
      }
      for(j=0;j<5;j++) star[i][j]=Segment(p[j%5],p[(j+2)%5]);
    }
    double inf = 1 << 28;
    double d[n][n];
    fill(d[0],d[0]+n*n,inf);
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(i==j) continue;
	for(s=0;s<5;s++){
	  for(t=0;t<5;t++){
	    d[i][j]=min(d[i][j],getDistance(star[i][s],star[j][t]));
	  }
	}
      }
    }
    double v[n];
    fill(v,v+n,inf);
    bool used[n];
    memset(used,0,sizeof(used));
    typedef pair<double,int> P;
    priority_queue<P,vector<P>,greater<P> > q;
    q.push(P(0,m));
    while(!q.empty()){
      a=q.top().first;k=q.top().second;q.pop();
      if(used[k]||v[k]<=a) continue;
      used[k]=true;v[k]=a;
      for(i=0;i<n;i++) q.push(P(a+d[k][i],i));
    }
    printf("%.8f\n",v[l]);
  }
  return 0;
}