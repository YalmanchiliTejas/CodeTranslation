#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll pow(ll x,ll y){
  if(y==0) return 1;
  ll res=pow(x,y/2);
  res*=res;
  res%=mod;
  if(y%2==1) res*=x;
  return res%mod;
}
ll gyaku(ll x){
  return pow(x,mod-2);
}
vector<ll> frac,gfrac;
void set_frac(ll n){
  frac.push_back(1);
  gfrac.push_back(1);
  for(ll i=1;i<=n;i++){
    frac.push_back(frac[i-1]*i%mod);
    gfrac.push_back(gyaku(frac[i]));
  }
}
ll nCr(ll n,ll r){
  ll res=frac[n]*gfrac[r]%mod;
  res*=gfrac[n-r];
  return res%mod;
}
ll dp[1005][1005]={0};
int main(){
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  set_frac(n+100);
  dp[0][0]=1;
  for(int j=0;j<=b;j++){
    for(int i=0;i<=n;i++){
      ll num=dp[i][j];
      dp[i][j+1]+=dp[i][j];
      dp[i][j+1]%=mod;
      if(a<=(j+1)&&(j+1)<=b){
        for(int l=1;l<=d;l++){
          if(i+(j+1)*l<=n){
            num*=nCr(n-i-(l-1)*(j+1),j+1);
            num%=mod;
            if(c<=l&&l<=d){
              dp[i+l*(j+1)][j+1]+=(num*gfrac[l])%mod;
              dp[i+l*(j+1)][j+1]%=mod;
            }
          }
        }
      }
    }
  }
  cout<<dp[n][b]<<'\n';
}
