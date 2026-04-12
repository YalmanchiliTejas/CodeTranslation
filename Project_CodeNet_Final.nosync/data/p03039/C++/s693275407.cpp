#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll mod = 1e9+7;

ll modpower(ll a, ll r){ //a^r
    ll x = 1;
    while (r > 0) {
        if (r & 1) x = x * a % mod;
        r >>= 1;
        a = a * a % mod;
    }
    return x;
}

ll modinv(ll a){
    return modpower(a, mod-2);
}

ll modconv(ll n, ll k){
	ll res = 1;
	for (ll i = n; i >= n-k+1; i--) res = res * i % mod;
	for (ll i = 1; i <= k; i++) res = res * modinv(i) % mod;
	return res;
}

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    
    ll ans = 0;
    ans += N*N %mod *M %mod *(M-1) %mod *(M+1)%mod*modinv(6)%mod*modconv(N*M-2, K-2)%mod;
    ans += M*M %mod *N %mod *(N-1) %mod *(N+1)%mod*modinv(6)%mod*modconv(N*M-2, K-2)%mod;
    cout << ans%mod << endl;
    return 0;
}