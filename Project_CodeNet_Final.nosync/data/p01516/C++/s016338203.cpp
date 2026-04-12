#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cctype>
#include<complex>
#include<algorithm>
#include<iomanip>
#define rep(X,Y) for(int X=0;(X)<(Y);++X)
#define X first
#define Y second
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const double EPS=1e-8;
typedef complex<double> P;
namespace std{
  bool operator< (const P &a, const P &b){
    return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
  }
}

double cross(const P &a,const P &b){
  return imag(conj(a)*b);
}
double dot(const P &a,const P &b){
  return real(conj(a)*b);
}

struct L : public vector<P>{
  L(const P &a,const P &b){
    pb(a); pb(b);
  }
};

P proj(const L &l,const P &p){
  double t=dot(p-l[0],l[0]-l[1])/norm(l[0]-l[1]);
  return l[0]+t*(l[0]-l[1]);
}

int ccw(P a,P b,P c){
  b-=a; c-=a;
  if(cross(b,c)>EPS) return 1;
  if(cross(b,c)<-EPS) return -1;
  if(dot(b,c)<-EPS) return 2;
  if(norm(b)<norm(c)+EPS) return -2;
  return 0;
}

double intersectSS(const L &s,const L &t){
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0 &&
    ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0;
}

double intersectSP(const L &s,const P &p){
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0])<EPS;
}

double distSP(const L &s, const P &p){
  const P r=proj(s,p);
  if(intersectSP(s,r))return abs(r-p);
  return min(abs(s[0]-p), abs(s[1]-p));
}

double distSS(const L &s,const L &t){
  if(intersectSS(s,t)) return 0;
  return min({distSP(s,t[0]),distSP(s,t[1]),distSP(t,s[0]),distSP(t,s[1])});	 
}


int main(){
  int n,m,l;
  while(cin>>n>>m>>l,n){
    vector<vector<L>> st(n);
    cout<<fixed<<setprecision(10);
    int x,y,a,r;
    rep(i,n){
      cin>>x>>y>>a>>r;
      double th=M_PI/2+1.*a*M_PI/180;
      vector<P> ps(5);
      rep(j,5){
	ps[j]=P(x+r*cos(th),y+r*sin(th));
	th+=72.*M_PI/180;
      }
      rep(j,5){
	st[i].pb(L(ps[j],ps[(j+2)%5]));
      }
    }
    
    double d[n][n];
    fill(d[0],d[0]+n*n,1e20);
    rep(i,n)rep(j,n)rep(a,5)rep(b,5)
      d[i][j]=min(d[i][j],distSS(st[i][a],st[j][b]));
    //rep(i,n){rep(j,n)cout<<d[i][j]<<" ";cout<<endl;}
    rep(k,n)rep(i,n)rep(j,n)
      d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cout<<d[m-1][l-1]<<endl;
  }
}