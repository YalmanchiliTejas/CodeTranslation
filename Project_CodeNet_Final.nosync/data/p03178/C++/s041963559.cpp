#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll mod=1000000007;
string K;
ll D;
ll dp[100005][2][105];
int main(){
  cin>>K>>D;
  ll N=K.size();
  dp[0][0][0]=1;
  for(ll i=0;i<N;i++){
  ll k=K[i]-'0';
    for(int j=0;j<D;j++){
    for(int l=0;l<10;l++)
      dp[i+1][1][(j+l)%D]=(dp[i+1][1][(j+l)%D]+dp[i][1][j])%mod;
    }
    for(int j=0;j<D;j++){
    for(int l=0;l<k;l++)
      dp[i+1][1][(j+l)%D]=(dp[i+1][1][(j+l)%D]+dp[i][0][j])%mod;
    }
    for(int j=0;j<D;j++){
      dp[i+1][0][(j+k)%D]=(dp[i+1][0][(j+k)%D]+dp[i][0][j])%mod;
    }
  
  }cout<<(dp[N][1][0]+dp[N][0][0]-1+mod)%mod<<endl;
  return 0;
}