#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define endl "\n"
using ll=long long;
using ld=long double;
using namespace std;
const ll mod= 1e9+7;
const ll INF = 1LL<<40;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll dp[2][110][20];
int main() {
  ll n,k,ans=0;
  string s;
  cin>>s;
  cin>>k;
  n=s.length();
  dp[1][0][0]=1;
  rep(i,0,n){
    rep(kn,0,k+1){
      ll x=s[i]-'0';
      dp[0][i+1][kn+1]+=dp[0][i][kn]*9;
      dp[0][i+1][kn]+=dp[0][i][kn];
      if(x!=0){
        dp[0][i+1][kn+1]+=dp[1][i][kn]*(x-1);
        dp[0][i+1][kn]+=dp[1][i][kn];
        dp[1][i+1][kn+1]=dp[1][i][kn];
      }
      if(x==0)dp[1][i+1][kn]=dp[1][i][kn];
    
    }
  }

  cout << dp[0][n][k] + dp[1][n][k] << endl;
}

