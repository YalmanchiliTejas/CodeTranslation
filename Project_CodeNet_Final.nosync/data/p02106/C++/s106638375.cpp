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

int n,q;
vi g[125252];
int f[125252][10];
int color[125252];
pair<pii,pii> queries[125252];

const int B = 500;

bool used[125252];
int cnt[125252][10];
vi gg[125252];

void gyudfs(int p,int bef,int par){
  if(used[p]){
    if(p!=0)gg[par].push_back(p);
    par = p;
  }
  cnt[par][color[p]]++;
  for(int to : g[p])if(to!=bef){
    gyudfs(to,p,par);
  }
}

void baadfs(int p,int bef,int par){
  if(used[p]){
    par = p;
  }
  color[p] = f[par][color[p]];
  for(int to : g[p])if(to!=bef){
    baadfs(to,p,par);
  }
}

int countdfs(int p,int x,int y){
  int ret = 0;
  FOR(i,x,y+1)ret += cnt[p][i];
  for(int to : gg[p]){
    ret += countdfs(to,x,y);
  }
  return ret;
}

void changedfs(int p,int x,int y){
  if(x!=y){
    cnt[p][y] += cnt[p][x];
    cnt[p][x] = 0;
  }
  // update f
  REP(i,10)if(f[p][i]==x){
    f[p][i] = y;
  }
  for(int to : gg[p]){
    changedfs(to,x,y);
  }
}

int main(){
  scanf("%d%d",&n,&q);
  REP(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  REP(i,q){
    int t,r,x,y;
    scanf("%d%d%d%d",&t,&r,&x,&y);
    queries[i] = make_pair(pii(t,r),pii(x,y));
  }
  int qhead = 0, qtail = 0;
  while(qtail < q){
    qtail += B;
    CHMIN(qtail, q);
    // init
    REP(i,n)REP(j,10)f[i][j] = j,cnt[i][j]=0;
    REP(i,n)used[i]=false, gg[i].clear();
    // shukuyaku
    FOR(i,qhead,qtail){
      int r=queries[i].first.second;
      used[r] = true;
    }
    used[0] = true;
    // REP(i,n)used[i]=true;
    gyudfs(0,-1,0);
    // query
    FOR(i,qhead,qtail){
      int t=queries[i].first.first;
      int r=queries[i].first.second;
      int x=queries[i].second.first;
      int y=queries[i].second.second;
      if(t==1){
        // count
        int ans = countdfs(r,x,y);
        printf("%d\n",ans);
      }else{
        // change
        changedfs(r,x,y);
      }
    }
    // modosu
    baadfs(0,-1,0);
    qhead = qtail;
  }
  return 0;
}