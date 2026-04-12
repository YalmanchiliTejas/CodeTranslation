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
 
const int INF = MOD;
 
int n,m,q;
vector<pii> g[125252];             // グラフ
int depth[125252];        // 根付き木の深さ
int anc[125252][20];      // anc[i][k] := iの2^k個上の祖先
int query[125252][20];
 
int data[125252];
int init(){
  REP(i,125252)data[i]=-1;
}
int root(int x){
  return data[x]<0?x:data[x]=root(data[x]);
}
void unite(int a,int b){
  a=root(a);b=root(b);
  if(a!=b){
    if(data[a]>data[b])swap(a,b);
    data[a] += data[b];
    data[b] = a;
  }
}
int size(int x){
  return -data[root(x)];
}
 
int main(){
  scanf("%d%d",&n,&m);
  ll ans = 0;
  {
    set< pair<int,pii> > S;
    init();
    REP(i,m){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      --a;
      --b;
      S.insert(make_pair(c,pii(a,b)));
    }
    while(size(0)!=n){
      pair<int,pii> P = *S.begin(); S.erase(S.begin());
      int c = P.first;
      int a = P.second.first;
      int b = P.second.second;
      if(root(a)!=root(b)){
        unite(a,b);
        g[a].push_back(pii(b,c));
        g[b].push_back(pii(a,c));
        ans += c;
        // DEBUG(a);
        // DEBUG(b);
      }
    }
  }
 
  queue<int> Q;
 
  // 根付き木にする
  // そしてダブリングの準備
  REP(i,n) depth[i]=INF;
  REP(i,n)REP(k,20) anc[i][k]=query[i][k]=INF;
  depth[0] = 0;
  Q.push(0);
  while(!Q.empty()){
    int pos = Q.front(); Q.pop();
    int d = depth[pos];
    REP(i,g[pos].size()){
      int to = g[pos][i].first;
      int c = -g[pos][i].second;
      if(depth[to]!=INF)continue;
      depth[to] = d+1;
      Q.push(to);
      // ダブリング準備
      anc[to][0] = pos;
      query[to][0] = c;
      int id = 1;
      int cur = pos;
      while(anc[cur][id-1]!=INF){
        int next = anc[cur][id-1];
        anc[to][id] = next;
        query[to][id] = min(query[to][id-1], query[cur][id-1]);
        cur = next;
        ++id;
      }
    }
  }
  scanf("%d",&q);
 
  while(q--){
    int s,t;
    scanf("%d%d",&s,&t);
    --s; --t;
    ll x = INF;
    // LCAを取る
    int a,b;
    a = s;
    b = t;
    if(depth[a]>depth[b])swap(a,b);
    // 同じ高さにズラす
    int diff = depth[b]-depth[a];
    int k = 0;
    while(diff){
      if(diff&1){
        CHMIN(x,(ll)query[b][k]);
        b = anc[b][k];
      }
      diff>>=1;
      ++k;
    }
    k = 19;
    while(k>=0){
      if(anc[a][k]!=INF && anc[a][k]!=anc[b][k]){
        CHMIN(x,(ll)query[a][k]);
        CHMIN(x,(ll)query[b][k]);
        a = anc[a][k];
        b = anc[b][k];
      }
      --k;
    }
    int lca = a;
    if(a!=b){
      CHMIN(x,(ll)query[a][0]);
      CHMIN(x,(ll)query[b][0]);
      lca = anc[a][0];
    }
    printf("%lld\n",ans+x);
  }
  return 0;
}
