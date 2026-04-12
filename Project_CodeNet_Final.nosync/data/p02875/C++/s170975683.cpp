#include <bits/stdc++.h>
using namespace std;
constexpr int64_t mod = 998244353;

int64_t fact[10000001], finv[10000001];
int64_t mpow(int64_t x, int64_t y){
    if(y==0) return 1;
    if(y==1) return x%mod;
    if(y%2==0) return mpow(x*x%mod, y/2);
    return mpow(x*x%mod, y/2)%mod * x % mod;
}
int64_t comb(int64_t n, int64_t r){
    if(r<0 || r>n) return 0;
    return fact[n]*finv[r]%mod*finv[n-r]%mod;
}
int main(){
    int n;
    cin >> n;
    fact[0] = 1;
    for(int i=1;i<=n;++i) fact[i] = fact[i-1] * i % mod;
    finv[n] = mpow(fact[n], mod-2);
    for(int i=n-1;i>=0;--i) finv[i] = finv[i+1] * (i+1) % mod;

    int64_t ans = mpow(3, n);
    for(int i=n/2+1;i<=n;++i) ans = ((ans+mod) - comb(n,i)*mpow(2,n-i+1)%mod) % mod;
    
    cout << ans << endl;
    return 0;
}