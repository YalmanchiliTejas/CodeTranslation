#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef vector<LL> VLL;
typedef complex<double> P;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))
#define T1 first
#define T2 second.first
#define T3 second.second

//repetitionint
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef complex<double> P;
struct star{
	P p[5];
};
star stars[111];
double dist[111][111];

double dot(P p,P q){
	return real(conj(p)*q);
}

double cross(P p,P q){
	return imag(conj(p)*q);
}



double distPointPoint(P p1, P p2){
	return sqrt(norm(p1-p2));
}

double distPointSeg(P r,P p1, P p2){
	double t = dot(p2-p1, r-p1)/norm(p2-p1);
	if(0.0<=t && t<=1.0)return distPointPoint(r, (1.0-t)*p1+t*p2);
	else return min(distPointPoint(r,p1),distPointPoint(r,p2));
}

bool isIntersect(P p1, P p2, P q1, P q2){
	return (cross(p2-p1, q1-p1)*cross(p2-p1, q2-p1) < 0.0) && (cross(q2-q1, p1-q1)*cross(q2-q1, p2-q1) < 0.0);
}

double distSegSeg(P p1, P p2, P q1, P q2){
	if(isIntersect(p1,p2,q1,q2))return 0.0;
	double ret=distPointSeg(p1, q1, q2);
	ret = min(ret,distPointSeg(p2, q1, q2));
	ret = min(ret,distPointSeg(q1, p1, p2));
	ret = min(ret,distPointSeg(q2, p1, p2));
	return ret;
}

double distStarStar(star s1, star s2){
	double ret = 1.0e20;
	REP(i,5){
		REP(j,5){
			ret = min(ret, distSegSeg(s1.p[i], s1.p[(i+1)%5], s2.p[j], s2.p[(j+1)%5]));
		}
	}
	return ret;
}

int main(){
	int n,s,e;
	double pi=acos(-1.0);
	while(cin>>n>>s>>e, n){
		REP(i,n){
			double x,y,a,r;
			cin >> x>>y>>a>>r;
			REP(j,5){
				double theta = (a+144.0*j)/180.0;
				stars[i].p[j] = P(x-r*sin(theta*pi),y+r*cos(theta*pi));
			}
		}
		REP(i,n){
			REP(j,n){
				if(i==j)dist[i][j]=0.0;
				else dist[i][j] = distStarStar(stars[i], stars[j]);
			}
		}
		REP(k,n){
			REP(i,n){
				REP(j,n){
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
		printf("%.10f\n", dist[s-1][e-1]);
	}
	return 0;
}