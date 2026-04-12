#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

const double PI=acos(-1);

inline int Signum(double x){
	return abs(x)<EPS?0:x<0?-1:1;
}

struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
};
inline Point operator+(Point a,Point b){
	return Point(a.x+b.x,a.y+b.y);
}
inline Point operator-(Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
inline Point operator*(double c,Point p){
	return Point(c*p.x,c*p.y);
}
inline double Abs(Point p){
	return sqrt(p.x*p.x+p.y*p.y);
}
inline double Abs2(Point p){
	return p.x*p.x+p.y*p.y;
}
inline Point Rot(Point p,double t){
	return Point(cos(t)*p.x-sin(t)*p.y,sin(t)*p.x+cos(t)*p.y);
}
inline double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
inline double Cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
inline int CCW(Point a,Point b,Point c){
	Point d1=b-a,d2=c-a;
	if(int sign=Signum(Cross(d1,d2)))
		return sign;	// 1:ccw,-1:cw
	if(Dot(d1,d2)<-EPS)
		return -2;		// c-a-b
	if(Abs2(d1)<Abs2(d2)-EPS)
		return 2;		// a-b-c
	return 0;			// a-c-b
}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(double px,double py,double dx,double dy):pos(px,py),dir(dx,dy){}
};
typedef Line Segment;

inline Point Proj(Line l,Point p){
	Point a=p-l.pos,b=l.dir;
	return l.pos+Dot(a,b)/Abs2(b)*b;
}
inline bool InterLS(Line l,Segment s){
	Point a=l.pos,b=l.pos+l.dir,c=s.pos,d=s.pos+s.dir;
	return CCW(a,b,c)*CCW(a,b,d)<0;
}
inline bool InterSS(Segment a,Segment b){
	return InterLS(a,b) && InterLS(b,a);
}
inline double DistLP(Line l,Point p){
	return Abs(Proj(l,p)-p);
}
inline double DistSP(Segment s,Point p){
	int ccw=CCW(s.pos,s.pos+s.dir,Proj(s,p));
	if(ccw==-2)
		return Abs(p-s.pos);
	if(ccw==2)
		return Abs(p-(s.pos+s.dir));
	return DistLP(s,p);
}
inline double DistLS(Line l,Segment s){
	if(InterLS(l,s)) return 0;
	return min(DistLP(l,s.pos),DistLP(l,s.pos+s.dir));
}
inline double DistSS(Segment a,Segment b){
	if(InterSS(a,b)) return 0;
	double d1=min(DistSP(a,b.pos),DistSP(a,b.pos+b.dir));
	double d2=min(DistSP(b,a.pos),DistSP(b,a.pos+a.dir));
	return min(d1,d2);
}

int main()
{
	for(int n,src,dst;scanf("%d%d%d",&n,&src,&dst),n|src|dst;){
		vi xs(n),ys(n),as(n),rs(n);
		rep(i,n) scanf("%d%d%d%d",&xs[i],&ys[i],&as[i],&rs[i]);
		
		vvd dp(n,vd(n,INFTY));
		int counter=0;
		rep(i,n) rep(j,n){
			Point p1[6],p2[6];
			rep(k,6){
				p1[k]=Point(xs[i],ys[i])+Rot(Point(0,rs[i]),(as[i]+k*144)*PI/180);
				p2[k]=Point(xs[j],ys[j])+Rot(Point(0,rs[j]),(as[j]+k*144)*PI/180);
			}
			rep(k,5) rep(l,5){
				counter++;
				Segment s1(p1[k],p1[k+1]-p1[k]);
				Segment s2(p2[l],p2[l+1]-p2[l]);
				dp[i][j]=min(dp[i][j],DistSS(s1,s2));
			}
		}
		
		rep(k,n) rep(i,n) rep(j,n)
			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		printf("%.10f\n",dp[src-1][dst-1]);
	}
	
	return 0;
}