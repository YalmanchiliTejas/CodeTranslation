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

int h,w;
int a[252][252];
vector<pii> g[52525];
int bef[52525];
int dist[52525];
int used[52525];

#define ID(i,j) ((i)*w+j)
#define REV(i,j,v) int i=v/w, j=v%w

const int NICO = 125252;
const int INF = 830252521;

int main(){
  scanf("%d%d",&h,&w);
  REP(i,h)REP(j,w)scanf("%d",&a[i][j]);
  // start : (0,0)
  // goal : (h,w)

  // first flow
  REP(i,h)REP(j,w){
    if(i<h-1){
      g[ID(i,j)].push_back(pii(ID(i+1,j),NICO-a[i+1][j]));
    }
    if(j<w-1){
      g[ID(i,j)].push_back(pii(ID(i,j+1),NICO-a[i][j+1]));
    }
  }
  REP(i,w*h)dist[i] = INF;
  priority_queue<pii> Q;
  dist[0] = 0;
  Q.push(pii(-0,0));
  while(!Q.empty()){
    pii P = Q.top(); Q.pop();
    int d = -P.first;
    int id = P.second;
    for(pii X:g[id]){
      int to = X.first;
      int cost = X.second;
      if(d+cost < dist[to]){
        dist[to] = d+cost;
        bef[to] = id;
        Q.push(pii(-dist[to],to));
      }
    }
  }
  ll first_attempt = (ll)(w+h-2)*NICO-dist[w*h-1];
  // second construct
  int cur = w*h-1;
  REP(i,w*h)used[i] = -1;
  REP(i,w*h)g[i].clear();
  while(cur!=0){
    // DEBUG(cur);
    int par = bef[cur];
    used[par] = cur;
    REV(i,j,cur);
    g[cur].push_back(pii(par,a[i][j]-NICO));
    if(i>0 && par == ID(i-1,j)){
      if(j>0){
        g[ID(i,j-1)].push_back(pii(par,0));
      }
    }else{
      if(i>0){
        g[ID(i-1,j)].push_back(pii(par,0));
      }
    }
    a[i][j] = 0;
    cur = par;
  }
  REP(i,h)REP(j,w){
    if(i<h-1 && used[ID(i,j)]!=ID(i+1,j)){
      g[ID(i,j)].push_back(pii(ID(i+1,j),NICO-a[i+1][j]));
    }
    if(j<w-1 && used[ID(i,j)]!=ID(i,j+1)){
      g[ID(i,j)].push_back(pii(ID(i,j+1),NICO-a[i][j+1]));
    }
  }
  REP(i,w*h)dist[i] = INF;
  dist[0] = 0;
  Q.push(pii(-0,0));
  while(!Q.empty()){
    pii P = Q.top(); Q.pop();
    int d = -P.first;
    int id = P.second;
    for(pii X:g[id]){
      int to = X.first;
      int cost = X.second;
      if(d+cost < dist[to]){
        dist[to] = d+cost;
        bef[to] = id;
        Q.push(pii(-dist[to],to));
      }
    }
  }
  // cur = w*h-1;
  // while(cur!=0){
  //   DEBUG(cur);
  //   cur = bef[cur];
  // }
  ll second_attempt = (ll)(w+h-2)*NICO-dist[w*h-1];
  // DEBUG(first_attempt);
  // DEBUG(second_attempt);
  printf("%lld\n",first_attempt+second_attempt - a[h-1][w-1]+a[0][0]);
  return 0;
}
