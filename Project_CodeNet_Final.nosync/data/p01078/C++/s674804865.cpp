#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n,k;

Real cross(P a,P b){
  return imag(a*conj(b));
}
// http://www.deqnotes.net/acmicpc/2d_geometry/lines
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  Real d1 = abs(cross(b, a1-b1));
  Real d2 = abs(cross(b, a2-b1));
  Real t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

int main(){
  scanf("%d%d",&n,&k);
  double a_ph = 0.0;
  double b_ph = (double)k/n;
  double c_ph = 1.0/n;
  double d_ph = (double)(n+1-k)/n;
  a_ph *= 2.0*M_PI;
  b_ph *= 2.0*M_PI;
  c_ph *= 2.0*M_PI;
  d_ph *= 2.0*M_PI;
  P a(cos(a_ph),sin(a_ph));
  P b(cos(b_ph),sin(b_ph));
  P c(cos(c_ph),sin(c_ph));
  P d(cos(d_ph),sin(d_ph));
  P o(0,0);
  P e = intersection_ls(a,o,c,d);
  P f = intersection_ls(c,o,a,b);
  P g = intersection_ls(a,b,c,d);
  double unit = (abs(cross(f-a,o-a))+abs(cross(f-c,g-c)))/2.0;
  double ans = unit*n;
  printf("%.10lf\n",ans);
  return 0;
}