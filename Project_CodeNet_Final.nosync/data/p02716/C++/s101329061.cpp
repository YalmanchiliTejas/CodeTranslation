#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<bool> vb;
 
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m;i>=n;i--)
#define all(x) x.begin(),x.end()
#define gll greater<ll>()
 
ll n;
vll a(n);

void solve(){
 cin >> n;
 a.resize(n);
 rep(i,0,n) cin >> a[i];
 ll k=n%2+1;
 vvll dp(n+1,vll(k+5,-1e18)); 
 dp[0][0]=0;
  
  rep(i,0,n){
   rep(j,0,k+1){ 
     dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
     ll now=dp[i][j];
     if((i+j)%2==0) now+=a[i];
     dp[i+1][j]=max(dp[i+1][j],now);
   }
  }
  
 
  cout << dp[n][k] << endl;
}
int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}  