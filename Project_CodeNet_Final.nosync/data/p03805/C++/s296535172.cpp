#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;
const ll m=1LL<<32;

int main(){

  ll n,m;cin>>n>>m;
  bool line[n][n];CLR(line,false);
  rep(i,0,m){
    ll a,b;cin>>a>>b;
    a--,b--;
    line[a][b]=line[b][a]=true;
  }

  ll dp[(1<<n)][n];
  CLR(dp,0);
  ll count=0;
  dp[1][0]=1;
  rep(i,0,(1<<n)){
    rep(j,0,n){
      if(dp[i][j]==0)continue;
      rep(k,0,n){
        if((i>>k)%2==1)continue;
        if(!line[j][k])continue;
        // out(bitset<8>(i)<<":"<<j<<":"<<k);
        count++;
        dp[i|(1<<k)][k]+=dp[i][j];
      }
    }
  }

  ll all=(1<<n)-1;
  ll ans=0;
  rep(i,1,n){
    if(dp[all][i]==-INF)continue;
    ans+=dp[all][i];
  }
  out(ans);

  return 0;
}
