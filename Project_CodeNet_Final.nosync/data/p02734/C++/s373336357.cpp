#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m;i>=n;i--)

ll n,s;
vll a;

const ll mod=998244353;

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  cin >> n >> s;
  a.resize(n);
  ll m=0;
  rep(i,0,n) {
    cin >> a[i];
    m=max(m,a[i]);
  }
  
  vector<vvll> dp(n+1,vvll(s+m+1,vll(3,0)));
  
  dp[0][0][0]=1;
  
  rep(i,0,n){
   rep(j,0,s+1){
     (dp[i+1][j][0]+=dp[i][j][0])%=mod;
     (dp[i+1][j+a[i]][1]+=dp[i][j][0]*(i+1))%=mod;
     (dp[i+1][j+a[i]][2]+=dp[i][j][0]*(i+1)*(n-i))%=mod;
  
     
     (dp[i+1][j][1]+=dp[i][j][1])%=mod;
     (dp[i+1][j+a[i]][1]+=dp[i][j][1])%=mod;
     (dp[i+1][j+a[i]][2]+=dp[i][j][1]*(n-i))%=mod;
     
      (dp[i+1][j][2]+=dp[i][j][2])%=mod;
   }
  }
  cout << dp[n][s][2] << endl;
}