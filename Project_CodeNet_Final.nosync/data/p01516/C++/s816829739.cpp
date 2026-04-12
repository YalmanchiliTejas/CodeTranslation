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

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
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
const double PI=acos(-1);

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

double Signum(double x)
{
	return abs(x)<EPS?0:x<0?-1:1;
}

typedef complex<double> Point;

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
};
typedef Line Segment;

double Dot(Point a,Point b)
{
	return real(conj(a)*b);
}

double Cross(Point a,Point b)
{
	return imag(conj(a)*b);
}

int CCW(Point a,Point b,Point c)
{
	Point d1=b-a,d2=c-a;
	if(int sign=Signum(Cross(d1,d2)))
		return sign;
	if(Dot(d1,d2)<-EPS)
		return -2;
	if(norm(d1)<norm(d2)-EPS)
		return 2;
	return 0;
}

Point Proj(Line l,Point p)
{
	Point a=p-l.pos,b=l.dir;
	return Dot(a,b)/norm(b)*b+l.pos;
}

bool InterLS(Line l,Segment s)
{
	Point a=l.pos,b=l.pos+l.dir;
	Point c=s.pos,d=s.pos+s.dir;
	return CCW(a,b,c)*CCW(a,b,d)<0;
}
bool InterSS(Segment a,Segment b)
{
	return InterLS(a,b) && InterLS(b,a);
}

double DistLP(Line l,Point p)
{
	return abs(Proj(l,p)-p);
}
double DistSP(Segment s,Point p)
{
	int ccw=CCW(s.pos,s.pos+s.dir,Proj(s,p));
	if(ccw==-2)
		return abs(p-s.pos);
	if(ccw==2)
		return abs(p-(s.pos+s.dir));
	return DistLP(s,p);
}

double DistSS(Segment a,Segment b)
{
	if(InterSS(a,b)) return 0;
	double d1=min(DistSP(a,b.pos),DistSP(a,b.pos+b.dir));
	double d2=min(DistSP(b,a.pos),DistSP(b,a.pos+a.dir));
	return min(d1,d2);
}

int main()
{
	for(int n,src,dst;cin>>n>>src>>dst,n|src|dst;){
		vi xs(n),ys(n),as(n),rs(n);
		rep(i,n) cin>>xs[i]>>ys[i]>>as[i]>>rs[i];
		
		vvd d(n,vd(n,INFTY));
		rep(i,n) rep(j,n){
			double x1[6],y1[6],x2[6],y2[6];
			rep(k,6){
				x1[k]=xs[i]+rs[i]*cos((90+as[i]+k*144)*PI/180);
				y1[k]=ys[i]+rs[i]*sin((90+as[i]+k*144)*PI/180);
				x2[k]=xs[j]+rs[j]*cos((90+as[j]+k*144)*PI/180);
				y2[k]=ys[j]+rs[j]*sin((90+as[j]+k*144)*PI/180);
			}
			rep(k,5) rep(l,5){
				Line s1(Point(x1[k],y1[k]),Point(x1[k+1]-x1[k],y1[k+1]-y1[k]));
				Line s2(Point(x2[l],y2[l]),Point(x2[l+1]-x2[l],y2[l+1]-y2[l]));
				d[i][j]=min(d[i][j],DistSS(s1,s2));
			}
		}
		
		rep(k,n) rep(i,n) rep(j,n)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		printf("%.10f\n",d[src-1][dst-1]);
	}
	
	return 0;
}