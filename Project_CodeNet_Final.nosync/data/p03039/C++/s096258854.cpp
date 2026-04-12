#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

ll mpow(ll x,ll n){
    ll res = 1;
    while(n != 0){
        if(n&1) res = res*x % mod;
        x = x*x % mod;
        n = n >> 1; 
    }
    return res;
}
ll fac(ll i){
    static ll fatorial[200000+1]={};

    if(fatorial[i]) return fatorial[i];
    else if(i==0) return fatorial[0] = 1;
    else return fatorial[i] = fac(i-1)*i % mod;
}
ll ifac(ll i){
    static ll ifactorial[200000+1]={};

    if(ifactorial[i]) return ifactorial[i];
    else if(i==0) return ifactorial[0] = 1;
    else return ifactorial[i] = ifac(i-1)*mpow(i,mod-2) % mod;
}
ll comb(ll a,ll b){
    if(a==0 && b==0) return 1;
    if(a<b || a<0) return 0;
    ll tmp = ifac(a-b)*ifac(b) % mod;
    return tmp*fac(a) % mod;
}

ll sum_manh(ll n,ll m,ll k){
    ll res = 0;

    for(int d = 1;d <= n-1;d ++){
        res = (res + (d*(n-d)%mod)*mpow(m,2)*comb(n*m-2,k-2))%mod;
    }
    return res;
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;

    cout << (sum_manh(n,m,k) + sum_manh(m,n,k))%mod << endl;

    return 0;
}