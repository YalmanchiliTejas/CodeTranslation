#include<bits/stdc++.h>
using namespace std;
 
#define eps (1e-10)
#define INF (1e20)

static const double PI = acos(-1);
bool eq(double a,double b){
  return ( -eps < a-b && a-b < eps);
}

class Point{
public:
  double x, y;
  Point ( double x = 0, double y = 0): x(x), y(y){}
  Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
  Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
  Point operator * ( double a ){ return Point(x*a, y*a); }
  Point operator / ( double a ){ return Point(x/a, y/a); }
};
typedef Point Vector;

class Segment{
public:
  Point p1, p2;
  Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
  Vector base(){
    return p2-p1;
  }
};
typedef Segment Line;

bool eq(Point a,Point b){ return (eq(a.x,b.x)&&eq(a.y,b.y)); }
double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

Vector rotate(Vector v,double ti){
  return Point(v.x*cos(ti)-v.y*sin(ti),v.x*sin(ti)+v.y*cos(ti));
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
  
int ccw( Point p0, Point p1, Point p2 ){
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if ( cross(a, b) > eps ) return COUNTER_CLOCKWISE;
  if ( cross(a, b) < -eps ) return CLOCKWISE;
  if ( dot(a, b) < -eps ) return ONLINE_BACK;
  if ( norm(a) < norm(b) ) return ONLINE_FRONT;
  return ON_SEGMENT;
}
 
bool isIntersect(Point p1, Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <=0 &&
          ccw(p3,p4,p1) * ccw(p3,p4,p2) <=0);
}
 
bool isIntersect(Segment s1,Segment s2){
  return isIntersect(s1.p1 , s1.p2 , s2.p1 , s2.p2);
}

double getDistanceLP(Line s,Point p){
  return abs(cross(s.p2-s.p1,p-s.p1)/abs(s.p2-s.p1));
}
 
double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
  return getDistanceLP(s,p);
}
 
double getDistance(Segment s1,Segment s2){
  if(isIntersect(s1,s2))return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}


int N,M,L;
double G[100][100];
vector<Segment> A[100];

double solve(int a,int b){
  double res=INF;
  for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      res=min(res,getDistance(A[a][i],A[b][j]));      
  return res;
}

int main(){
  double B=2.0*acos(-1.0)/5.0;
  while(1){
    
    cin>>N>>M>>L;
    if(N==0&&M==0&&L==0)break;
    
    for(int i=0;i<N;i++){
      Point p;
      Vector v;
      double a;
      cin>>p.x>>p.y>>a>>v.y;
      a=a/360.0*2.0*acos(-1.0);
      v.x=0;
      v=rotate(v,a);
      A[i].clear();
      for(int j=0;j<5;j++){
        A[i].push_back(Segment(p+v,p+rotate(v,B+B)));
        v=rotate(v,B);
      }
    }
  
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        G[i][j]=solve(i,j);
  
    for(int k=0;k<N;k++)
      for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
          G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    printf("%.10f\n",G[M-1][L-1]);
  }
  return 0;
}