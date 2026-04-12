#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>


using namespace std;

const long double EPS = 1e-8;
const long double INF = 1e12;
typedef complex<long double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
long double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
long double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P projection(const L &l, const P &p) {
  long double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

long double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
long double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

class Star{
public:
	vector<L> star;
	void add(P p1,P p2){
		star.push_back(L(p1,p2));
	}
	
	long double dist(const Star &s){
		long double res=INF;
		for(int i=0;i<star.size();i++){
			for(int j=0;j<s.star.size();j++){
				res=min(res,distanceSS(star[i],s.star[j]));
			}
		}

		return res;
	}
	
};


int main()
{
	int n,m,l;
	while(cin>>n>>m>>l,n){
		vector<Star> stars(n);
		for(int i=0;i<n;i++){
			int x,y,a,r;
			cin>>x>>y>>a>>r;
			
			long double theta=M_PI/180.0*a;
			long double theta2=M_PI/180.0*72.0;
			
			vector<P> p(5);
			
			for(int j=0;j<5;j++){
				p[j]=P(0,r)*polar((long double)1.0,theta+j*theta2)+P(x,y);
				//cout<<p[j]<<endl;
			}
			
			for(int j=0;j<5;j++){
				stars[i].add(p[(2*j)%5],p[(2+2*j)%5]);
			}
		}
		
		vector<vector<long double> > dist(n,vector<long double>(n));
		for(int i=0;i<n;i++) dist[i][i]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) dist[i][j]=dist[j][i]=stars[i].dist(stars[j]);
		}
		
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		
		cout<<setprecision(10)<<dist[m-1][l-1]<<endl;;
		
	}
	
	
	return 0;
}