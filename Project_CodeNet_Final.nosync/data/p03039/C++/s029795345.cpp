#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int MAX = 510000;

long long ans=0;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}

// 二項係数計算
long long COM(int n,int k){
  if(n<k)return 0;
  if(n<0||k<0)return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main(){
  long long n,m,k;
  cin>>n>>m>>k;
  
  for(int i=0;i<n;i++){
    ans+=i*(n-i)*m*m%mod;
    ans%=mod;
  }
  for(int i=0;i<m;i++){
    ans+=i*(m-i)*n*n%mod;
    ans%=mod;
  }
  
  COMinit();
  ans*=COM(n*m-2,k-2)%mod;
  ans%=mod;

  cout<<ans<<endl;

  return(0);
}
