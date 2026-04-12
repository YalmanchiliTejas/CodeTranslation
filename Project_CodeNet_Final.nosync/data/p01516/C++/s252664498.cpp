#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()


#define x(p) real(p)
#define y(p) imag(p)

const double eps=1e-8;
const double inf=1e12;
typedef complex<double> P;

namespace std{
  bool operator<(const P& a,const P& b){
    return x(a)==x(b)?y(a)<y(b):x(a)<x(b);
  }
}
double cross(const P& a,const P& b){
  return y(conj(a)*b);
}
double dot(const P& a,const P& b){
  return x(conj(a)*b);
}
struct L : public vector<P> { // line and segment
  L(const P& a,const P &b){
    push_back(a);
    push_back(b);
  }
};

P projection(const L& l,const P& p){
  P b=l[1]-l[0],c=p-l[0];
  return l[0]+b*x(c/b);
}
P reflection(const L& l,const P& p){
  return p+2.0*(projection(l,p)-p);
}
P rotation(const P& a,double r){
  return P(x(a)*cos(r)-y(a)*sin(r),x(a)*sin(r)+y(a)*cos(r));
}

//// counter-clockwise
int ccw(P a,P b,P c) {
  b=b-a;c=c-a;
  if(cross(b,c)>0) return +1;       // counter clockwise
  if(cross(b,c)<0) return -1;       // clockwise
  if(dot(b,c)<0)   return +2;       // c--a--b on line
  if(norm(b)<norm(c)) return -2;       // a--b--c on line
  return 0;
}

bool intersectLL(const L& l,const L& m){
  return abs(cross(l[1]-l[0],m[1]-m[0]))>eps;
}
bool intersectSS(const L& s,const L& t){
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0&&ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0;
}
bool intersectSP(const L& s,const P& p){
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0])<eps;
}
double distanceSP(const L& s,const P& p) {
  const P r=projection(s,p);
  return intersectSP(s,r)?abs(r-p):min(abs(s[0]-p),abs(s[1]-p));
}
double distanceSS(const L& s,const L& t) {
  return intersectSS(s,t)?0:min(min(distanceSP(s,t[0]),distanceSP(s,t[1])),
                                min(distanceSP(t,s[0]),distanceSP(t,s[1])));
}

P ps[111][5];
double dist[111][111];
const double PI=acos(-1);

int main(){
	cin.sync_with_stdio(false);
  while(1){
    int n,m,l;
    cin>>n>>m>>l;
    l--;m--;
    if(n==0)break;
    rep(i,n){
      double x,y,a,r;
      cin>>x>>y>>a>>r;
      P cent(x,y),p0(0,r);
      rep(j,5){
        ps[i][j]=rotation(p0,(((a+(double)j*72.0)/180.0)*PI))+cent;
      }
    }
    rep(i,n)rep(j,n)dist[i][j]=i==j?0:inf;
    rep(i,n)rep(j,n)rep(id,5)rep(jd,5){
      if(i==j)continue;
      minch(dist[i][j],distanceSS(L(ps[i][id],ps[i][(id+2)%5]),L(ps[j][jd],ps[j][(jd+2)%5])));
    }
    rep(k,n)rep(i,n)rep(j,n)minch(dist[i][j],dist[i][k]+dist[k][j]);
    printf("%.20f\n", dist[l][m]);
  }
	return 0;
}