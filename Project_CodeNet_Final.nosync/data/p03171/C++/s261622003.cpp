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
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll n;
ll a[3001];
ll dp[3001][3001];

ll dfs(ll l,ll r){
  if(dp[l][r]!=-INF)return dp[l][r];
  if(l==r)return 0;
  ll res=max(-dfs(l+1,r)+a[l],-dfs(l,r-1)+a[r-1]);
  return dp[l][r]=res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  rep(i,n)cin>>a[i];
  rep(i,3001)rep(j,3001)dp[i][j]=-INF;
  cout<<dfs(0,n)<<endl;

  return 0;
}
