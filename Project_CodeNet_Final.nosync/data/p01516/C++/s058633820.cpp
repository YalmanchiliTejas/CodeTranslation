#include <complex>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-8;
typedef complex<double> P;

double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(){}
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

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
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

const double PI = 3.14159265358979323846264;

double deg2rad(double deg) {
  return deg*PI/180;
}

P rotate(P p, P c, double d) {
  return c+(p-c)*P(cos(d),sin(d));
}


#include <cstdio>

const int INF = 1000000000;
L star[200][5];
double d[200][200];

double diststar(int i,int j){
  double ans = 1000000;
  for (int ii=0; ii<5; ii++)
    for (int ji=0; ji<5; ji++)
      ans = min(ans,distanceSS(star[i][ii],star[j][ji]));
  return ans;
}

int main() {
  int n,m,l;
  while(scanf("%d %d %d",&n,&m,&l),n) {
    for(int i=0; i<n; i++) {
      double x,y,a,r;
      scanf("%lf %lf %lf %lf",&x,&y,&a,&r);
      P c(x,y),up(x,y+r);
      for (int j=0; j<5; j++) {
	P f = rotate(up,c,deg2rad(j*144+a));
	P t = rotate(up,c,deg2rad(((j+1)%5)*144+a));
	star[i][j] = L(f,t);
      }
    }

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
	d[i][j] = (i==j?0:diststar(i,j));

    for (int k=0; k<n; k++)
      for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	  d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

    printf("%.15f\n",d[m-1][l-1]);
  }
}