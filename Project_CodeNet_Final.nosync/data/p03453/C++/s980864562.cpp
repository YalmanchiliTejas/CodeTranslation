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

int n,m;
int s,t;
vector<pii> g[125252];
int uu[252521], vv[252521], dd[252521];

const ll INF = 1e18;
ll dist1[125252], dist2[125252];
ll dp1[125252], dp2[125252];

int main(){
  if(false){
    n = 10;
    m = 2*n - 4;
    printf("%d %d\n",n,m);
    s = n-1; t = n;
    printf("%d %d\n",s,t);
    printf("%d 1 1\n", s);
    printf("%d 2 1\n", s);
    REP(i,n/2-2){
      printf("%d %d 1\n",2*i+1,2*(i+1)+1);
      printf("%d %d 1\n",2*i+1,2*(i+1)+2);
      printf("%d %d 1\n",2*i+2,2*(i+1)+1);
      printf("%d %d 1\n",2*i+2,2*(i+1)+2);
    }
    printf("%d %d 1\n",n-3,t);
    printf("%d %d 1\n",n-2,t);
    return 0;
  }
  scanf("%d%d",&n,&m);
  scanf("%d%d",&s,&t); s--;t--;
  REP(i,m){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    u--; v--;
    g[u].push_back(pii(v,d));
    g[v].push_back(pii(u,d));
    uu[i] = u;
    vv[i] = v;
    dd[i] = d;
  }
  priority_queue<pll> Q;
  // from s
  REP(i,n)dist1[i] = INF;
  dist1[s] = 0;
  dp1[s] = 1;
  Q.push(pll(-dist1[s], s));
  while(!Q.empty()){
    pll P = Q.top(); Q.pop();
    int p = P.second;
    if(-P.first != dist1[p])continue;
    for(pii R : g[p]){
      int to = R.first;
      ll nd = dist1[p] + R.second;
      if(nd == dist1[to])dp1[to] = (dp1[to] + dp1[p]) % MOD;
      if(nd >= dist1[to])continue;
      dist1[to] = nd;
      dp1[to] = dp1[p];
      Q.push(pll(-nd, to));
    }
  }
  // from t
  REP(i,n)dist2[i] = INF;
  dist2[t] = 0;
  dp2[t] = 1;
  Q.push(pll(-dist2[t], t));
  while(!Q.empty()){
    pll P = Q.top(); Q.pop();
    int p = P.second;
    if(-P.first != dist2[p])continue;
    for(pii R : g[p]){
      int to = R.first;
      ll nd = dist2[p] + R.second;
      if(nd == dist2[to])dp2[to] = (dp2[to] + dp2[p]) % MOD;
      if(nd >= dist2[to])continue;
      dist2[to] = nd;
      dp2[to] = dp2[p];
      Q.push(pll(-nd, to));
    }
  }
  ll T = dist1[t];
  ll sum = dp1[t] * dp1[t] % MOD;
  // DEBUG(T);
  // DEBUG(dp1[t]);
  // DEBUG(dp2[t]);
  ll sub = 0;
  if(T%2 == 0){
    // collide on vertex
    REP(i,n){
      if(dist1[i] == T/2 && dist2[i] == T/2){
        ll xx = dp1[i] * dp2[i] % MOD;
        sub += xx * xx % MOD;
        sub %= MOD;
      }
    }
  }
  // collide on edge
  REP(i,m){
    int u = uu[i];
    int v = vv[i];
    ll d = dd[i];
    if(dist1[u] > dist1[v])swap(u,v);
    if(dist1[u] + d + dist2[v] == T){
      if(2ll*dist1[u] < T){
        if(2ll*dist2[v] < T){
          ll xx = dp1[u] * dp2[v] % MOD;
          sub += xx * xx % MOD;
          sub %= MOD;
        }
      }
    }
  }
  ll ans = (sum - sub + MOD) % MOD;
  printf("%lld\n",ans);
  return 0;
}
