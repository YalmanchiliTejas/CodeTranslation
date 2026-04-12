#include<bits/stdc++.h>
#define N 2001
#define M 1000000007
using namespace std;
typedef long long ll;

ll n,x,dp[N][N],sum,ans,k1,k2;
ll d,D;

ll mod_power(ll a,ll b){
  ll X=a,r=1;
  while(b){
    if(b%2)r=(r*X)%M;
    b/=2;
    X=(X*X)%M;
  }
  return r;
}

ll ncr(ll a,ll b){
  b=mod_power(b,M-2);
  return (a*b)%M;
}

int main(){
  while(1){
    cin>>n>>d>>x;
    if(!n&&!d&&!x)break;
    D=d;
    if(D>=N-1)D=N-1;
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<x;i++)dp[0][i]=1;
    for(ll i=0;i<D-1;i++){
      sum=0;
      for(ll j=1;j<n;j++){
	sum=(sum+dp[i][j])%M;
	if(j>=x)sum=(sum-dp[i][j-x+1]+M)%M;
	dp[i+1][j+1]=sum;
      }
    }
    ans=0;
    k1=k2=1;
    for(ll i=0;i<D;i++){
      k1=(k1*((d-i)%M))%M;
      k2=(k2*(i+1))%M;
      if(k1<0)break;
      ans=(ans+(ncr(k1,k2)*dp[i][n])%M)%M;
    }
    cout<<ans<<endl;
  }
  return 0;
}