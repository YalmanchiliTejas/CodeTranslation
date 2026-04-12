#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX_N 100000
#define MAX_P 200005
ll fact[MAX_P];
ll extgcd(ll a,ll b,ll& x,ll& y){
  ll d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
ll mod_inverse(ll a,ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}
#define MAX_D 2222
ll dp[MAX_D][MAX_D];
int main(){
  ll n,d,x;
  while(cin>>n>>d>>x,n||d||x){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    ll p=1,ans=0;
    for(int i=0;i<min(d,n);i++){
      ll sum[MAX_D];
      memset(sum,0,sizeof(sum));
      for(int j=0;j<n;j++) sum[j+1]=(sum[j]+dp[i][j])%MOD;
      for(int k=1;k<=n;k++){
	dp[i+1][k]+=(MOD+sum[k]-sum[max(0LL,k-x+1)])%MOD;
	dp[i+1][k]%=MOD;
      }
      p*=(d-i)%MOD;
      p%=MOD;
      p*=mod_inverse(i+1,MOD);
      p%=MOD;
      ans+=dp[i+1][n]*p;
      ans%=MOD;
    }
    /*//
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
	cout<<dp[i][j]<<" \n"[j==n];
    //*/
    cout<<ans<<endl;
  }
  return 0;
}