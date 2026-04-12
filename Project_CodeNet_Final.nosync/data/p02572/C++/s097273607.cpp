#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

long power(long x, long y, long mod){
  long ans = 1, tmp = x;;
  while(y>0){
    if(y & 1){
      ans *= tmp%mod;
      ans %= mod;
    }
    tmp *= tmp;
    tmp %= mod;
    y >>= 1;
  }
  return ans;
}

int main(){
  long n;
  cin >> n;
  long a[n];
  long rui = 0;
  long mod = INF;
  rep(i,n){
    cin >> a[i];
    rui += a[i];
    rui %= mod;
  }
  long ans = 0;
  rep(i,n){
    long tmp = rui-a[i];
    if(tmp<0)tmp += mod;
    ans += (a[i]*tmp)%mod;
    ans %= mod;
  }
  cout << (ans*power(2,mod-2,mod))%mod << endl;
  return 0;
}