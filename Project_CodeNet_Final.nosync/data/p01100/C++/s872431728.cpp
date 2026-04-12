#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

int n,m;
bool mat[101][101],rmat[101][101];
int cnt[101];
bool vis[101];

void dfs(int v){
  vis[v]=true;
  rep(i,n){
    if(!mat[v][i]||vis[i])continue;
    dfs(i);
  }
}
void rdfs(int v){
  vis[v]=true;
  rep(i,n){
    if(!rmat[v][i]||vis[i])continue;
    rdfs(i);
  }
}

int dfs2(int v,int dst){
  if(cnt[v]==dst)return v;
  vis[v]=true;
  rep(i,n){
    if(!rmat[v][i]||vis[i])continue;
    int tmp=dfs2(i,dst);
    if(tmp!=-1){
      mat[v][i]=true;
      mat[i][v]=false;
      rmat[i][v]=true;
      rmat[v][i]=false;
      return tmp;
    }
  }
  return -1;
}
int rdfs2(int v,int dst){
  if(cnt[v]==dst)return v;
  vis[v]=true;
  rep(i,n){
    if(!mat[v][i]||vis[i])continue;
    int tmp=rdfs2(i,dst);
    if(tmp!=-1){
      mat[v][i]=false;
      mat[i][v]=true;
      rmat[i][v]=false;
      rmat[v][i]=true;
      return tmp;
    }
  }
  return -1;
}

int main(){
  while(1){
    cin>>n>>m;
    if(n==0&&m==0)break;
    rep(i,n)rep(j,n)mat[i][j]=rmat[i][j]=false;
    rep(i,n)cnt[i]=0;
    rep(i,m){
      int a,b;
      cin>>a>>b;
      a--;b--;
      mat[b][a]=rmat[a][b]=true;
      cnt[b]++;
    }
    bool update=true;
    while(update){
      update=false;
      int mx=-1,mn=100000000;
      rep(i,n){
        maxch(mx,cnt[i]);
        minch(mn,cnt[i]);
      }

      {
        rep(i,n)vis[i]=false;
        rep(i,n)if(cnt[i]==mx)dfs(i);
        rep(i,n){
          if(!vis[i]||cnt[i]>=mx-1)continue;
          rep(j,n)vis[j]=false;
          int dst=dfs2(i,mx);
          cnt[dst]--; cnt[i]++;
          update=true;
          break;
        }
      }
      if(!update){
        rep(i,n)vis[i]=false;
        rep(i,n)if(cnt[i]==mn)rdfs(i);
        rep(i,n){
          if(!vis[i]||cnt[i]<=mn+1)continue;
          rep(j,n)vis[j]=false;
          int dst=rdfs2(i,mn);
          cnt[dst]++; cnt[i]--;
          update=true;
          break;
        }
      }
    }
    int mx=-1,mn=10000000;
    rep(i,n){
      maxch(mx,cnt[i]);
      minch(mn,cnt[i]);
    }
    cout<<mn<<" "<<mx<<endl;
  }
  return 0;
}

