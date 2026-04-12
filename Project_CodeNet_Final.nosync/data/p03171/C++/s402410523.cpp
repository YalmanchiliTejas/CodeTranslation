#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;

ll dp[3005][3005];

int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  rep(i,n+5)dp[i][i]=a[i];

  rep(j,n)rep(i,n){
    if (i+j>=n)continue;
    else{
      dp[i][i+j]=max(a[i+j]-dp[i][i+j-1],a[i]-dp[i+1][i+j]);
  //    cout<<a[j]-dp[i][j-1]<<" "<<a[i]-dp[i+1][j]<<endl;
    //  cout<<dp[i][i+j]<<"i"<<i<<"j"<<(i+j)<<endl;
    //  dp[i][j]=max(dp[i][j],);
    }
  }
  cout<<dp[0][n-1];
}
