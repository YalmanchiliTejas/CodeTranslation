#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

ll mod_pow(ll n, ll p, ll mod){
    if(p==0) return 1;
    ll res = mod_pow(n*n%mod, p/2, mod);
    if(p%2==1) res = res * n % mod;
    return res;
}

int main(void){
    // Your code here!
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<ll> fct(N*M-1, 1);
    for(ll i = 1; i <= N*M-2; i++) {
        fct[i] = i * fct[i-1] % mod;
    }
    
    vector<ll> invfct(N*M-1, 1);
    invfct[N*M-2] = mod_pow(fct[N*M-2], mod-2, mod) % mod;  
    
    for(ll i = N*M-3; i >= 1; i--) {
        invfct[i] = (i+1) * invfct[i+1] % mod;
    }
    
    ll W = (fct[N*M-2] * invfct[K-2] % mod) * invfct[N*M-K] % mod;
    
    ll sumdx = 0;
    for(ll dx=1; dx < M; dx++) {
        ll A = N*N*(M-dx) % mod;
        sumdx += dx * A %mod;
        sumdx = sumdx % mod;
    }
    
    ll sumdy = 0;
    for(ll dy=1; dy < N; dy++){
        ll B = M*M*(N-dy) % mod;
        sumdy += dy * B % mod;
        sumdy = sumdy % mod;
    }
    
    cout << (sumdx+sumdy) * W % mod << endl; 
}
