// Created by sz
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n,m,k;

using ll = long long;
const int mod = 1e9 + 7;
int fac[N], finv[N];

ll quick_pow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init_fac_mod(int nima){
    //only when mod is prime
    fac[0] = finv[0] = 1;
    for(int i = 1; i <= nima; ++i)
        fac[i]=(ll)fac[i-1]*i%mod;
    finv[nima] = quick_pow(fac[nima], mod-2);
    for(int i = nima-1; i; --i)
        finv[i] = (ll)finv[i+1]*(i+1)%mod;
}

int c(int n, int m){
    //n!/(m!(n-m)!)
    return (ll)fac[n] * finv[m] % mod * finv[n - m]% mod;
}

int c_2(int n, int m){
    ll res = 1;
    for (int i = 0; i < m; i++){
        (res *= n-i)%= mod;
        (res/= i+1)%= mod;
    }
    return res;
}



int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    
    
    ll d = 0;
    for (int i = 1; i < n; i++){
        d += (ll)i*(n-i)%mod*m%mod*m%mod;
        d%= mod;
    }
    
    for (int i = 1; i < m; i++){
        d += (ll)i*(m-i)%mod*n%mod*n%mod;
        d %= mod;
    }
    
    init_fac_mod(n*m-2);
    cout<<d*c(n*m-2, k-2)%mod<<endl;
    
    
    
    
    
    return 0;
}

