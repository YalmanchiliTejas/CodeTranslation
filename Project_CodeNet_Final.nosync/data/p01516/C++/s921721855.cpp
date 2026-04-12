#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <complex>
#include <queue>
#include <sstream>

using namespace std;

typedef double R;
typedef complex<R> P;
typedef pair<P,P> L;
typedef pair<P,R> C;
typedef vector<P> Poly;

const double PI = acos(-1);
#define x real()
#define y imag()

const R EPS = 1e-9;


inline bool near(const P& p,const P& q){ return abs(p-q)<EPS;}

R dot(const P& p,const P& q){ return p.x*q.x+p.y*q.y;}
R det(const P& p,const P& q){ return p.x*q.y-p.y*q.x;}

enum LPposit{
  P_CD = -2, //counter direction
  P_CW = -1, //clock wise
  P_OS = 0, //on segment
  P_CCW = 1, //counter clock wise
  P_D = 2 //direction
};

inline R ccw_b(const P& p,const P& q,const P& r){  return det(q-p,r-p);}

LPposit ccw(const P& p, const P& q, const P& r){
  R c = ccw_b(p,q,r);
  if(c<-EPS) return P_CW;
  if(c>EPS) return P_CCW;
  if(dot(q-p,r-p)<-EPS) return P_CD;
  if(dot(p-q,r-q)<-EPS) return P_D;
  return P_OS;
}

inline R Sabs(const L& l){ return abs(l.first-l.second);}
inline R LPdist(const L& l,const P& p){ return abs(ccw_b(l.first,l.second,p))/Sabs(l);}

R SPdist(L l,P p){
  R a = abs(l.first-p);
  R b = abs(l.second-p);
  R c = Sabs(l);
  if(b*b+c*c>a*a && a*a+c*c>b*b) return LPdist(l,p);
  return min(a,b);
}

bool crossS(const L& p,const L& q){
  return
    ccw(p.first,p.second,q.first)*ccw(p.first,p.second,q.second)<=0 &&
    ccw(q.first,q.second,p.first)*ccw(q.first,q.second,p.second)<=0;
}

R SSdist(const L& a,const L& b){
  if(crossS(a,b)) return 0;
  double tmp = min(SPdist(a,b.first),SPdist(a,b.second));
  return min(tmp, min(SPdist(b,a.first), SPdist(b,a.second)));
}


P intersect(const L& p,const L& q){
  P vp = p.second-p.first;
  P vq = q.second-q.first;
  P c(det(vp,p.first), det(vq,q.first));
  return P(det(c, P(vp.x, vq.x)), det(c, P(vp.y, vq.y))) / det(vp, vq);
}

R area(const Poly& p){
  R ret = 0;
  int n = p.size();
  for(int i=0;i<n;++i) ret+=det(p[i],p[(i+1)%n]);
  return abs(ret)/2;
}

/* ?????¨??´???????????? */
vector<P> CLintersect(const L& l,const C& c){
  vector<P> ret;
  R di = LPdist(l,c.first);
  R r = c.second;
  if(di+EPS > r) return ret;
  P v = l.second-l.first;
  v/=abs(v);
  P rv = v*P(0,1);
  rv*=di;
  if(LPdist(l,c.first+rv) > di+EPS) rv=-rv;
  v*=sqrt(r*r-di*di);
  ret.push_back(c.first+rv-v);
  ret.push_back(c.first+rv+v);
  return ret;
}

//circle, segment
vector<P> CSintersect(const L& l,const C& c){
  vector<P> u = CLintersect(l,c);
  vector<P> ret;
  for(int i=0;i<u.size();++i){
    if(l.first.x <= u[i].x && u[i].x<=l.second.x &&
       l.first.y <= u[i].y && u[i].y<=l.second.y)
      ret.push_back(u[i]);
  }
  return ret;
}

vector<P> CCintersect(C c,C d){
  vector<P> ret;
  const R dist = abs(c.first-d.first);
  const R cr = c.second;
  const R dr = d.second;

  if(dist > cr+dr) return ret;
  if(dist < abs(cr-dr)) return ret;

  const R s = (cr+dr+dist)/2;
  const R area = sqrt(s*(s-cr)*(s-dr)*(s-dist));
  const R h = 2*area/dist;

  P v = d.first - c.first; v/=abs(v);
  const P m = c.first+sqrt(cr*cr-h*h)*v;
  const P n = v*P(0,1);

  ret.push_back(m+n*h);
  ret.push_back(m-n*h);
  return ret;
}

/* ?????? */
namespace std{
  bool operator < (const P& a,const P& b){
    return a.x!=b.x?a.x<b.x : a.y<b.y;
  }
}
Poly convexHull(vector<P> ps){
  int n = ps.size();
  sort(ps.begin(),ps.end());
  Poly ret(2*n);
  int m=0;
  for(int i=0;i<n;++i){
    while(m>=2 && ccw(ret[m-2],ret[m-1],ps[i])<0) --m;
    ret[m++] = ps[i];
  }
  int t = m;
  for(int i=n-2;i>=0;--i){
    while(m>=t && ccw(ret[m-2], ret[m-1], ps[i])<0) --m;
    ret[m++] = ps[i];
  }

  ret.resize(m-1);
  return ret;
}

int inConvex(const Poly& ps, P p){
  int n = ps.size();
  int c = ccw(ps[n-1],p,ps[0]);
  for(int i=0;i+1<n;++i)
    if(ccw(ps[i],p,ps[i+1])!=c) return false;
  return true;
}

int n;
R G[101][101];
const R INF = 1<<29;

R dist(const Poly& a,const Poly& b){
  R ret = INF;
  for(int i=0;i<5;++i)
    for(int j=0;j<5;++j)
      ret = min(ret, SSdist(L(a[i],a[(i+1)%5]),L(b[j],b[(j+1)%5])));
  return ret;
}

R dijkstra(int s,int t){
  double cost[101]={};
  bool used[101]={};
  for(int i=0;i<n;++i)
    cost[i]=INF,used[i]=false;
  cost[s]=0;
  while(true){
    double mincst = INF;
    int id = -1;
    for(int i=0;i<n;++i){
      if(!used[i] && mincst > cost[i]){
	id = i;
	mincst = cost[i];
      }
    }
    if(id==-1) break;
    used[id] = true;
    for(int i=0;i<n;++i)
      cost[i] = min(cost[i], cost[id]+G[id][i]);
  }
  return cost[t];
}

int main(){
  const P rot = polar(1.0 ,0.8*PI);
  int s,t;
  while(cin>>n>>s>>t,n||s||t){
    s--;t--;
    vector<Poly> star(n);
    for(int i=0;i<n;++i){
      double a,b,c,d;
      cin >> a >> b >> c >> d;
      P up = P(0,1)*d;
      up*=polar(1.0,PI*c/180);
      for(int j=0;j<5;++j){
	star[i].push_back(up+P(a,b));
	up*=rot;
      }
    }

    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
	G[i][j] = G[j][i] = dist(star[i], star[j]);
    
    cout << fixed << setprecision(10) << dijkstra(s,t) << endl;
  }
  return 0;
}