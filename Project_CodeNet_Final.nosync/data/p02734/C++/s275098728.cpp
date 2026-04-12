#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int v[N];
long long dp[N];
const int MOD=998244353;
int main()
{
  int n,s;
  cin>>n>>s;
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }
  long long  ans=0;
  for(int i=1;i<=n;i++){
    dp[0]=i%MOD;
    if(v[i]<=s){
      ans+=(1LL*dp[s-v[i]]*(n-i+1)%MOD)%MOD;
      ans%=MOD;
      for(int ss=s-v[i];ss>=0;ss--){
        dp[ss+v[i]]+=dp[ss];
        dp[ss+v[i]]%=MOD;
      }
    }
  }
  cout<<ans;
  return 0;
}
