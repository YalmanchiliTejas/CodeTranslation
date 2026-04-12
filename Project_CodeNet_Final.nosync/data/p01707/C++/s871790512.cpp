#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll mul(ll a,ll b){
  return (a*b)%mod;
}
ll pow(ll x,ll n){
  if(n==0)return 1;
  ll res=pow(mul(x,x),n/2);
  if(n%2==1)res=mul(res,x);
  return res;
}
ll divi(ll a,ll b){
  return mul(a,pow(b,mod-2));
}
ll add(ll a,ll b){
  return (a+b)%mod;
}

ll N,D,X;
ll dp[2005][2005];

int main(){
  while(1){
    cin>>N>>D>>X;
    if(N==0&&D==0&&X==0)break;
    
    ll ans=0,cnt=D%mod;

    dp[0][0]=1;
    for(int i=1;i<=min(N,D);i++){
      ll sum=0;
      for(int j=1;j<=N;j++){
        sum=add(sum,dp[i-1][j-1]);
        if(j-X>=0)sum=add(sum,mod-dp[i-1][j-X]);
        dp[i][j]=sum;
      }
      ans=add(ans,mul(dp[i][N],cnt));
      //cout<<" "<<cnt<<endl;
      cnt=mul(cnt,(D-i)%mod);
      cnt=divi(cnt,i+1);

    }

    cout<<ans<<endl;
  }
  return 0;
}