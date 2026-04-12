#include <bits/stdc++.h>
using namespace std;

constexpr int64_t mod = 1'000'000'007;
int64_t mpow(int64_t x, int64_t y){
    if(y==0) return 1;
    if(y==1) return x%mod;
    if(y%2==0) return mpow(x*x%mod, y/2);
    return mpow(x*x%mod, y/2)%mod * x % mod;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout.precision(12);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    int64_t fact[200001], finv[200001];
    fact[0] = 1;
    for(int i=1;i<=200000;i++) fact[i] = i*fact[i-1]%mod;
    finv[200000] = mpow(fact[200000], mod-2);
    for(int i=199999;i>=0;i--) finv[i] = finv[i+1]*(i+1)%mod;

    int64_t n, m, k;
    cin >> n >> m >> k;

    int64_t sum1 = 0, sum2 = 0, sum3 = 0;
    for(int64_t x=1;x<=n;x++) sum1 = (sum1 + (n-x)*(n-x+1)/2%mod) % mod;
    sum1 = sum1 * m % mod * m % mod;
    for(int64_t l=1;l<=m-1;l++) sum2 = (sum2 + l*(l+1)%mod) % mod;
    int64_t p = n*(n-1)/2%mod;
    sum2 = p * sum2 % mod;
    for(int64_t y=1;y<=m;y++) sum3 = (sum3 + (m-y)*(m-y+1)/2%mod) % mod;
    sum3 = sum3 * n % mod;
    cout << (sum1+sum2+sum3) % mod * fact[n*m-2] % mod * finv[k-2] % mod * finv[n*m-k] % mod << endl;
    
    return 0;
}