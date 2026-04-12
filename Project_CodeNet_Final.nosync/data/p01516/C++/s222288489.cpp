#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<complex>
using namespace std;
double x[100][5];
double y[100][5];
double abs(double a){return max(-a,a);}
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
P wolf[100][5];
namespace std{
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
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
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
double dist[100][100];
double PI=3.14159265359;
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c),a){
		double p,q,r,s;
		for(int i=0;i<a;i++){
			scanf("%lf%lf%lf%lf",&p,&q,&s,&r);
			x[i][0]=p-r*sin(s*PI/180);
			x[i][1]=p-r*sin((s+144)*PI/180);
			x[i][2]=p-r*sin((s+288)*PI/180);
			x[i][3]=p-r*sin((s+72)*PI/180);
			x[i][4]=p-r*sin((s+216)*PI/180);
			y[i][0]=q+r*cos(s*PI/180);
			y[i][1]=q+r*cos((s+144)*PI/180);
			y[i][2]=q+r*cos((s+288)*PI/180);
			y[i][3]=q+r*cos((s+72)*PI/180);
			y[i][4]=q+r*cos((s+216)*PI/180);
		}
		for(int i=0;i<a;i++)
			for(int j=0;j<a;j++)
				dist[i][j]=INF;
		for(int i=0;i<a;i++)dist[i][i]=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<5;j++){
				wolf[i][j]=P(x[i][j],y[i][j]);
			//	printf("%d,%d: %f %f\n",i,j,x[i][j],y[i][j]);
			}
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				for(int k=0;k<5;k++)
					for(int l=0;l<5;l++){
					//	L wolf(P());
						dist[i][j]=min(dist[i][j],distanceSS(L(wolf[i][k],wolf[i][(k+1)%5]),L(wolf[j][l],wolf[j][(l+1)%5])));
					}
			}
		}
		for(int k=0;k<a;k++)
			for(int i=0;i<a;i++)
				for(int j=0;j<a;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		printf("%.8f\n",dist[b-1][c-1]);
	}
}