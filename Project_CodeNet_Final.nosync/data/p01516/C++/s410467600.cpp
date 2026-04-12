#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cmath>
#include<iomanip>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-10)
#define inf (1<<29)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define equals(a,b) (fabs((a)-(b)) < EPS)
using namespace std;
class Point
{
  public:
  double x,y;

  Point(double x = -1,double y = -1): x(x),y(y){}

  Point operator + (Point p ){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}//※イケメンに限る

  bool operator < (const Point& p) const
  {
    return x != p.x?x<p.x:y<p.y;
  }

  bool operator == (const Point& p)const
  {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }

//必要に応じて
double norm()
{
return x*x+y*y;
}

};

struct Segment
{
  Point p1,p2;
  Segment(Point p1 = Point(-1,-1),Point p2 = Point(-1,-1)):p1(p1),p2(p2){}
};
typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<Point> vp;
typedef vector<vp> vvp;
typedef vector<double> vd;
typedef vector<vd> vvd;


double dot(Point a,Point b)
{
  return a.x*b.x + a.y*b.y;
}
double cross(Point a,Point b)
{
  return a.x*b.y - a.y*b.x;
}

double norm(Point a)
{
  return a.x*a.x+a.y*a.y;
}

bool pequals(Point a,Point b)
{
  return equals(a.x,b.x) && equals(a.y,b.y);
}

//rad は角度をラジアンで持たせること
Point rotate(Point a,double rad)
{
  return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y);
}

double toRad(double agl)
{
  return agl*M_PI/180.0;
}

int ccw(Point p0,Point p1,Point p2)
{
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(Point p1,Point p2,Point p3,Point p4)
{
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 &&
          ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
}

bool isIntersect(Segment s1,Segment s2)
{
return isIntersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double abs(Point a)
{
  return sqrt(norm(a));
}

double getDistanceLP(Line s,Point p)
{
  return abs(cross(s.p2-s.p1,p-s.p1))/abs(s.p2-s.p1);
}

double getDistanceSP(Segment s,Point p)
{
  if(dot(s.p2-s.p1,p-s.p1) < 0.0)return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0)return abs(p-s.p2);
  return getDistanceLP(s,p);
}




int N,M,L;

int main()
{
  while(cin >> N >> M >> L,N|M|L)
    {
      vvp info(N);
      vvd G(N,vd(N));
      rep(i,N)rep(j,N)G[i][j] = (i==j?0:inf);

      rep(i,N)
	{
	  double x,y,a,r;
	  cin >> x >> y >> a >> r;
	  rep(j,5)
	    {
	      Point p = Point(0,r);
	      p = rotate(p,toRad(a+72*j));
	      info[i].push_back(Point(p.x+x,p.y+y));
	    }
	}

      rep(i,N)//from
	{
	  //REP(j,i+1,N)//to
	  rep(j,N)
	    {
	      double mincost = inf;

	      rep(k,5)
		{
		  rep(l,5)
		    {
		      if(isIntersect(Segment(info[i][k],info[i][(k+2)%5]),Segment(info[j][l],info[j][(l+2)%5])) || isIntersect(Segment(info[i][k],info[i][(k+2)%5]),Segment(info[j][l],info[j][(l+3)%5])))
			{
			  mincost = 0;
			  break;
			}		    
		      if(isIntersect(Segment(info[i][k],info[i][(k+3)%5]),Segment(info[j][l],info[j][(l+2)%5])) || isIntersect(Segment(info[i][k],info[i][(k+3)%5]),Segment(info[j][l],info[j][(l+3)%5])))
			{
			  mincost = 0;
			  break;
			}		    
		    }
		  if(mincost == 0)break;
		}

	      if(mincost == 0)goto Next;

	      rep(k,5)//which node
		{
		  rep(l,5)//which segment
		    {
		      mincost = min(mincost,min(getDistanceSP(Segment(info[j][l],info[j][(l+2)%5]),info[i][k]),
						getDistanceSP(Segment(info[j][l],info[j][(l+3)%5]),info[i][k])));
		    }
		}

	    Next:;
	      G[i][j] = G[j][i] = min(mincost,min(G[i][j],G[j][i]));
	    }
	}


      rep(k,N)rep(i,N)rep(j,N)G[i][j] = min(G[i][j],
					    G[i][k]+G[k][j]);      

      cout << setiosflags(ios::fixed) << setprecision(20) << G[M-1][L-1] << endl;

    }
  return 0;
}