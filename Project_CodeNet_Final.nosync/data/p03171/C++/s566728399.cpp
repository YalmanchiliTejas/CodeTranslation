#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=1e18;
const ll MOD=1e9+7;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll n;
ll dp[3010][3010];
ll a[3010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  cin >> n;
  rep(i,n)cin >> a[i];
  rep(i,n)dp[i][i]=0;
  
  for(int width=1;width<=n;width++){
    for(int l=0;l+width<=n;l++){
      int r=l+width;
      if(width%2==n%2){
        dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
      }
      else{
        dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
      }
    }
  }
  cout << dp[0][n] << endl;
      
  return 0;
}