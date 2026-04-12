#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,s,ans,dp[10000];
const int MOD=998244353;
void pl(ll &a,ll b){a=(a+b)%MOD;}

int main(){
  cin>>n>>s;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  dp[0]=1;
  for(int i=0;i<n;i++){
    for(int j=s;j>=0;j--)pl(dp[j+v[i]],dp[j]);
    pl(dp[v[i]],i);
    pl(ans,dp[s]);
  }
  cout<<ans<<endl;
}
