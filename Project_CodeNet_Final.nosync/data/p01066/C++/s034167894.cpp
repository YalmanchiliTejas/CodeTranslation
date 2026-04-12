#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

#define N_MAX 8

// int dat[N_MAX];
void init(vi &dat){
  dat.assign(N_MAX,-1);
}
int root(vi &dat,int x){
  return dat[x]<0 ? x : (dat[x]=root(dat,dat[x]));
}
void unite(vi &dat,int x,int y){
  x=root(dat,x);
  y=root(dat,y);
  if(x!=y){
    if(dat[x]>dat[y])swap(x,y);
    dat[x] += dat[y];
    dat[y] = x;
  }
}
bool same(vi &dat, int x,int y){
  return root(dat,x)==root(dat,y);
}
int size(vi &dat, int x){
  return -dat[root(dat,x)];
}

typedef double Real;
typedef complex<Real> P;
Real dot(P a,P b){return real(conj(a)*b);}
Real cross(P a,P b){return imag(conj(a)*b);}
#define EPS 1e-14

int n;
P p[10];
vector<pii> connect[10][10];

int dfs(const int &cnt,vi &uf){
  if(size(uf,0) == n)return cnt;

  int ret = 100;
  REP(to,n){
    if(same(uf,0,to))continue;
    REP(from,n){
      if(!same(uf,0,from))continue;
      vector<pii> con = connect[from][to];
      vi nextuf = uf;
      REP(i,con.size()) unite(nextuf,con[i].first,con[i].second);
      int d = dfs(cnt+1,nextuf);
      if(d==cnt+1)return d;
      ret = min(ret,d);
    }
  }
  return ret;
}

int main(){
  cin>>n;
  REP(i,n){
    int x,y;
    cin>>x>>y;
    p[i] = P((Real)x,(Real)y);
  }
  REP(i,n)REP(j,n){
    if(i==j)continue;
    // make connect[i][j];
    P v = p[i]-p[j];
    P cv = p[j] + v/P(2,0);
    P mirror = v*P(0,1);
    REP(x,n){
      P a = p[x];
      // reflect
      a = conj((a-cv)/mirror)*mirror+cv;
      REP(y,x){
        if(abs(p[y]-a)<EPS)connect[i][j].push_back(make_pair<int,int>(x,y));
      }
    }
  }
  vi beg;
  init(beg);
  cout<<dfs(0,beg)<<endl;
  return 0;
}