#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define R(i,a,n) for(int i=a;i<n;i++)
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b))<EPS)
class Point{
  public:
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}
  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}

  bool operator < (const Point &p) const{
    return x!=p.x?x<p.x:y<p.y;
  }
  bool operator == (const Point &p) const{
    return fabs(x-p.x)<EPS&&fabs(y-p.y)<EPS;
  }
};
typedef Point vect;
struct seg{Point p1,p2;};
double norm(Point p){return p.x*p.x+p.y*p.y;}
double abs(Point p){return sqrt(norm(p));}
double dot(Point a,Point b){
  return a.x*b.x+a.y*b.y;
}
double cross(Point a,Point b){
  return a.x*b.y-a.y*b.x;
}
int CCW(Point p0,Point p1,Point p2){
  Point a=p1-p0;
  Point b=p2-p0;
  if(cross(a,b)>EPS)return 1;
  if(cross(a,b)<-EPS)return -1;
  if(dot(a,b)<-EPS)return 2;
  if(norm(a)<norm(b))return -2;
  return 0;
}
double getDistancePP(Point a,Point b){
  return abs(a-b);
}
double getDistanceLP(seg l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}
double getDistanceSP(seg s,Point p){
  if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
  return getDistanceLP(s,p);
}
bool intersect(Point p1,Point p2,Point p3,Point p4){
  return(CCW(p1,p2,p3)*CCW(p1,p2,p4)<=0&&CCW(p3,p4,p1)*CCW(p3,p4,p2)<=0);
}
bool intersect(seg s1,seg s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}
double getDistance(seg s1,seg s2){
  if(intersect(s1,s2))return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
    min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}
int main(){
  double a,b,c,d;
  int n,ve,al;
  while(cin>>n>>ve>>al,n){
    Point p[n][5];
    seg D[n][5];
    r(i,n){
      scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
      r(j,5){
        p[i][j].x=a-d*sin(M_PI/180*(72*j+c));
        p[i][j].y=b+d*cos(M_PI/180*(72*j+c));
      }
      D[i][0].p1=p[i][0];D[i][0].p2=p[i][2];
      D[i][1].p1=p[i][1];D[i][1].p2=p[i][3];
      D[i][2].p1=p[i][2];D[i][2].p2=p[i][4];
      D[i][3].p1=p[i][3];D[i][3].p2=p[i][0];
      D[i][4].p1=p[i][4];D[i][4].p2=p[i][1];
    }
    double w[n][n];
    r(i,n)r(j,n)w[i][j]=i==j?0:1000000000;
    r(i,n)R(j,i+1,n){
      double t=1000000000;
      r(k,5)r(l,5)t=min(t,getDistance(D[i][k],D[j][l]));
      w[i][j]=w[j][i]=t;
    }
    r(k,n)r(i,n)r(j,n)w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
    printf("%.11f\n",w[ve-1][al-1]);
  }
}