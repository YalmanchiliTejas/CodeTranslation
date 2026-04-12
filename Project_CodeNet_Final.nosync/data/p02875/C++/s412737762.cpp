#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mpower(ll a,ll b,ll c){
  int z;
  if(b==0){
    z=1;
    z%=c;
    return z;
  }
  if(b==1){
    z=a;
    z%=c;
    return z;
  }
  else{
    return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
  }
}

const int MAX = 10000500;
const int MOD = 998244353;
ll fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
 
// 二項係数計算
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
 
int main(){
  COMinit();
  ll mod=998244353;
  ll x;
  cin>>x;
  ll ans=mpower(3,x,mod);
  ll p=0,q=1;
  ll mpow[x+1];//mpow[i]=2^x
  mpow[0]=1;
  for(int i=1;i<=x;i++){
    mpow[i]=mpow[i-1]*2;
    mpow[i]%=mod;
  }
  for(int i=x/2+1;i<=x;i++){
    q=COM(x,i);
    q*=mpow[x-i];
    q%=mod;
    p+=q;
    p%=mod;
  }
  ans-=2*p;
  while(ans<0){
    ans+=mod;
  }
  cout<<ans<<endl;
}