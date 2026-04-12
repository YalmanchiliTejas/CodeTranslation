#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll dp[3005][3005]={0};
int main(){
  ll n,s;
  cin>>n>>s;
  ll ans=0;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    if(a<=s) {
      if(a==s){
        ans+=i*(n-i+1);
        ans%=mod;
      }
      dp[i][a]+=i;
      dp[i][a]%=mod;
    }
    for(int j=0;j<=s;j++){
      if(j>0) dp[i][j]+=dp[i-1][j];
      dp[i][j]%=mod;
      if(j+a<=s){
        dp[i][j+a]+=dp[i-1][j];
        dp[i][j+a]%=mod;
      }
      if(j+a==s){
        ans+=dp[i-1][j]*(n+1-i);
        ans%=mod;
      }
    }
  }
  cout<<ans<<endl;
}
