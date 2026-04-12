#include <bits/stdc++.h>
using namespace std;

long n,m,k,ans=0,mod=1000000007,a=1,b=1,c;

long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}

int main() {
  cin >> n >> m >> k;
  for(long i=1;i<n;i++) ans=(m*m%mod*(n-i)%mod*i+ans)%mod;
  for(long i=1;i<m;i++) ans=(n*n%mod*(m-i)%mod*i+ans)%mod;
  
  for(long i=0;i<k;i++) a=a*(n*m-i)%mod;
  for(long i=0;i<k;i++) b=b*(i+1)%mod;
  c=a*modpow(b,mod-2)%mod*(k*(k-1)/2%mod)%mod;
  ans=c*modpow((n*m)*(n*m-1)/2%mod,mod-2)%mod*ans%mod;
  
  cout << ans << endl;
}