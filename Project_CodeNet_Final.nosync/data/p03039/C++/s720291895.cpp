#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;

const long mod = 1e9 + 7;

long powmod(long x, long n){
  long ret = 1;
  while(n > 0){
    if(n&1) ret *= x, ret %= mod, n -= 1;
    else x *= x, x %= mod, n >>= 1;
  }
  return ret;
}

vector<long> fact;
vector<long> revfact;

void setfact(int n){
  fact.resize(n+1); revfact.resize(n+1);
  fact[0] = 1;
  rep(i, n) fact[i+1] = fact[i] * (i+1) % mod;
  
  revfact[n] = powmod(fact[n], mod-2);
  for(int i=n-1; i>=0; i--) revfact[i] = revfact[i+1] * (i+1) % mod;
}

long getC(int n, int r){
  return fact[n] * revfact[r] % mod * revfact[n-r] % mod;
}

int main(){
    long n, m, k; cin >> n >> m >> k;
    setfact(n*m);
    long ans = 0;
    rep(i, m) ans = (ans + n*n%mod*(m-i)%mod*i%mod) % mod;
    rep(i, n) ans = (ans + m*m%mod*(n-i)%mod*i%mod) % mod;
    cout << ans * getC(n*m-2, k-2) % mod;
}