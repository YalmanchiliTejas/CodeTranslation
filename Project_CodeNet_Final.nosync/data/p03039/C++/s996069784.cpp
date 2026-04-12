#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

vector<ll> fct, invfct; 

ll mod_pow(ll n, ll p, ll mod){
    if(p==0) return 1;
    ll res = mod_pow(n*n%mod, p/2, mod);
    if(p%2==1) res = res * n % mod;
    return res;
}

ll Comb(ll n, ll k, ll mod){
    ll res = fct[n];
    res = res * invfct[n-k] % mod;
    res = res * invfct[k] % mod;
    // cerr << n << " " << k << " " << res << endl;
    return res;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    ll mod = 1e9+7;
    fct = vector<ll>(N*M+1,1);
    for(ll i=1; i<=N*M; i++){
        fct[i] = i * fct[i-1] % mod;
    }

    invfct = vector<ll>(N*M+1,1);
    invfct[N*M] = mod_pow(fct[N*M], mod-2, mod) % mod;
    // cout << N*M << " " << invfct[N*M] << endl;
    for(ll i=N*M-1; i>=1; i--){
        invfct[i] = (i+1)*invfct[i+1] % mod;
        //  cout << i << " " << invfct[i] << endl;
    }
    
    ll w = Comb(N*M-2, K-2, mod);
    while(w<0) w+=mod;
    w %= mod;
    // cout << w << endl;

    ll ans = 0;
    for(ll dx=1; dx<M; dx++){
        ll tmp = (N*N*(M-dx)) % mod;
        // cout << dx << " " << tmp << endl;
        tmp = tmp*dx%mod;
        ans = (ans + tmp) % mod;
    }
    for(ll dy=1; dy<N; dy++){
        ll tmp = (M*M*(N-dy)) % mod;
        tmp = tmp*dy%mod;
        ans = (ans + tmp) % mod;
    }
    cout << (ans*w)%mod << endl;
}
