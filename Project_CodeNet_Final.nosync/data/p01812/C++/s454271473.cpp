#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

int n,m,k;
int d[111];
int vs[111][111];
int dp[1<<17];
int idx[111];

int main(){
	cin.sync_with_stdio(false);
  cin>>n>>m>>k;
  memset(idx,-1,sizeof(idx));
  rep(i,m){
    cin>>d[i];
    d[i]--;
    idx[d[i]]=i;
  }
  rep(i,n)rep(j,k){
    cin>>vs[i][j];
    vs[i][j]--;
  }
  memset(dp,-1,sizeof(dp));
  queue<P> que;
  que.push(P((1<<m)-1,0));
  while(que.size()){
    int S=que.front().fi; int nd=que.front().se; que.pop();
    if(dp[S]!=-1)continue;
    dp[S]=nd;
    rep(i,k){
      int T=0;
      rep(j,m){
        if(((S>>j)&1)==0)continue;
        int nv=vs[d[j]][i];
        if(idx[nv]!=-1){
          T|=(1<<idx[nv]);
        }
      }
      que.push(P(T,nd+1));
    }
  }
  cout<<dp[0]<<endl;
  return 0;
}