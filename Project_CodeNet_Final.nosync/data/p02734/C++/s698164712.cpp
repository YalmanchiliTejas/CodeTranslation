#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
int n,s,a[N];
LL dp[3333][3333];
const LL mod=998244353;
int main() {
  ios::sync_with_stdio(false);
  cin>>n>>s;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  if(a[1]!=s)dp[1][a[1]]=1;LL ans=0;
  if(a[1]==s)ans=n;
  for(int i=2;i<=n;i++){
    if(a[i]<s)dp[i][a[i]]+=i;
    dp[i][a[i]]%=mod;
    if(s>a[i]){
      ans+=dp[i-1][s-a[i]]*(n-i+1)%mod;
//      cout<<i<<' '<<dp[i-1][s-a[i]]<<endl;
    }
    else if(s==a[i])ans+=1ll*(n-i+1)*i%mod;
    for(int j=a[i];j<s;j++){
      dp[i][j]+=dp[i-1][j-a[i]];
      dp[i][j]%=mod;
    }
    for(int j=1;j<s;j++){
      dp[i][j]+=dp[i-1][j];
      dp[i][j]%=mod;
    }
    //cout<<i<<' '<<dp[i][s]*(n-i+1)<<'\n';
    ans%=mod;
  }
  cout<<ans<<'\n';
  return 0;
}
