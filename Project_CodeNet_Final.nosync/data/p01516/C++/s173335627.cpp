#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
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

const double EPS=1e-9;
const double PI=acos(-1);

typedef complex<double> Point;
struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
};
typedef Line Segment;

int Signum(double x)
{
	return abs(x)<EPS?0:x<0?-1:1;
}

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
	int sign=Signum(Cross(d1,d2));
	
	if(sign)
		return sign;	// 1:ccw,-1:cw
	if(Dot(d1,d2)<-EPS)
		return -2;		// c-a-b
	if(norm(d1)<norm(d2)-EPS)
		return 2;		// a-b-c
	return 0;			// a-c-b
}

Point Proj(Point a,Point b)
{
    return b*Dot(a,b)/norm(b);
}

Point Perf(Line l,Point p)
{
	Point a(p-l.pos);
    return l.pos+Proj(a,l.dir);
}

bool IntersectLS(Line l,Segment s)
{
	Point a=l.pos;
	Point b=l.pos+l.dir;
	Point c=s.pos;
	Point d=s.pos+s.dir;
	return CCW(a,b,c)*CCW(a,b,d)<0;
}

bool IntersectSS(Segment s1,Segment s2)
{
	return IntersectLS(s1,s2) && IntersectLS(s2,s1);
}

double DistLP(Line l,Point p)
{
	return abs(Perf(l,p)-p);
}

double DistSP(Segment s,Point p)
{
	Point a=s.pos+Proj(p-s.pos,s.dir);
	int ccw=CCW(s.pos,s.pos+s.dir,a);
	if(ccw==-2)
		return abs(p-s.pos);
	if(ccw==2)
		return abs(p-(s.pos+s.dir));
	return DistLP(s,p);
}

double DistSS(Segment s1,Segment s2)
{
	if(IntersectSS(s1,s2))
		return 0;
	double a=DistSP(s1,s2.pos);
	double b=DistSP(s1,s2.pos+s2.dir);
	double c=DistSP(s2,s1.pos);
	double d=DistSP(s2,s1.pos+s1.dir);
	return min(min(a,b),min(c,d));
}

int main()
{
	for(int n,src,dst;cin>>n>>src>>dst,n|src|dst;){
		vi xs(n),ys(n),as(n),rs(n);
		rep(i,n) cin>>xs[i]>>ys[i]>>as[i]>>rs[i];
		
		vector<vector<Point> > ps(n,vector<Point>(5));
		rep(i,n) rep(j,5)
			ps[i][j]=Point(xs[i],ys[i])+polar(1.0,(as[i]+72*j)*PI/180)*Point(0,rs[i]);
		
		const double INFTY=1e9;
		vvd dist(n,vd(n,INFTY));
		rep(i,n) rep(j,n) rep(k,5) rep(l,5){
			int idx[]={0,2,4,1,3,0};
			Segment a(ps[i][idx[k]],ps[i][idx[k+1]]-ps[i][idx[k]]);
			Segment b(ps[j][idx[l]],ps[j][idx[l+1]]-ps[j][idx[l]]);
			dist[i][j]=min(dist[i][j],DistSS(a,b));
		}
		
		rep(k,n) rep(i,n) rep(j,n)
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		
		printf("%.20f\n",dist[src-1][dst-1]);
	}
	
	return 0;
}