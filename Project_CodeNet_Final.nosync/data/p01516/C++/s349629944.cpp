#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define inf 100000000
#define eps (1e-11)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;

class Point{
public:
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}

  Point operator+(Point p){ return Point(x+p.x,y+p.y);}
  Point operator-(Point p){ return Point(x-p.x,y-p.y);}
  Point operator*(double k){ return Point(x*k,y*k);}
  Point operator/(double k){ return Point(x/k,y/k);}
  bool operator<(Point p)const{ return (x!=p.x ? x<p.x : y<p.y);}
  bool operator==(Point p)const{ return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}

  double abs(){ return sqrt(norm());}
  double norm(){ return (x*x+y*y);}
};
typedef Point Vector;
typedef vector<Point> Polygon;

class Segment{
public:
  Point p1,p2;
  Segment(Point p1,Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

static const int COUNTER_CLOCKWISE=1;
static const int CLOCKWISE=-1;
static const int ONLINE_BACK=2;
static const int ONLINE_FRONT=-2;
static const int ON_SEGMENT=0;

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return COUNTER_CLOCKWISE;
  if(cross(a,b)<-eps)return CLOCKWISE;
  if(dot(a,b)<-eps)return ONLINE_BACK;
  if(a.norm()<b.norm())return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
  if(intersect(s1,s2))return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Point PointRotation(Point base,Point a,double r){
  Point b=a-base;
  a.x=b.x*cos((r/180)*M_PI)-b.y*sin((r/180)*M_PI);
  a.y=b.x*sin((r/180)*M_PI)+b.y*cos((r/180)*M_PI);
  a=a+base;
  return a;
}

double dis[101][101];
vector<Polygon> Stars;
int N,M,L,x,y,a,r;

double getDis(Polygon a,Polygon b){
  double mind=inf;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      Segment s1(a[i],a[(i+2)%5]),s2(b[j],b[(j+2)%5]);
      mind=min(getDistance(s1,s2),mind);
    }
  }
  return mind;
}

double Dijkstra()
{
  priority_queue<pair<double,int> > PQ;
  int color[101];
  double d[101];
  for(int i=0;i<N;i++){
    d[i]=inf;
    color[i]=0;
  }
  d[M-1]=0;
  PQ.push(make_pair(0,M-1));
  color[M-1]=0;
  while(!PQ.empty()){
    pair<double,int> p=PQ.top();PQ.pop();
    int u=p.s;
    color[u]=2;

    if(d[u]<p.f*(-1))continue;

    for(int i=0;i<N;i++){
      if(color[i]==2 || dis[u][i]==inf)continue;
      if(d[i]>dis[u][i]+d[u]){
	d[i]=dis[u][i]+d[u];
	PQ.push(make_pair(d[i]*(-1),i));
	color[i]=1;
      }
    }
  }
  return d[L-1];
}  

int main()
{
  while(1){
    cin>>N>>M>>L;
    if(N+M+L==0)break;
    Stars.clear();
    for(int i=0;i<N;i++){
      cin>>x>>y>>a>>r;
      Polygon p;
      for(int i=0;i<5;i++){
	p.push_back(PointRotation(Point(x,y),Point(x,y+r),(a+i*72)));
      }
      Stars.push_back(p);
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if(i==j)dis[i][j]=0;
	else dis[i][j]=getDis(Stars[i],Stars[j]);
      }
    }
    printf("%.10f\n",Dijkstra());
  }
  return 0;
}