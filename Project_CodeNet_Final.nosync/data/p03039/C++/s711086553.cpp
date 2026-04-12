#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll fat[200005], inv[200005];
ll mod = 1e9+7;

ll modpow(ll b, ll e){
    if(b == 0 or e == 0) return 1LL;
    if(e == 1) return b%mod;
    ll res = modpow(b, e/2);
    res = (res*res)%mod;
    if(e%2 == 1)
        res = (res * (b%mod))%mod;
    return res;
}

ll solve(ll n, ll k){
    ll up = fat[n];
    ll down = (inv[n-k]*inv[k])%mod;
    return (up*down)%mod;
}

int main(){
    
    fat[0] = inv[0] = 1;
    for(ll i = 1; i <= 2e5; i++){
        fat[i] = (fat[i-1] * i)%mod;
        inv[i] = modpow(fat[i], mod-2);
    }
    
    ll n, m, k; cin >> n >> m >> k;

    ll res = solve(n*m-2, k-2);
    // cout << res << endl;
    ll sumX = 0, sumY = 0;
    for(ll i = 1, aux = n-1; i <= n; i++, aux--)
        for(ll j = 1; j <= m; j++){
            sumX += m*aux*(aux+1)/2;
            sumX %= mod;
            // cout << sumX << endl;
        }
    for(ll j = 1, aux = m-1; j <= m; j++, aux--)
        for(ll i = 1; i <= n; i++){
            sumY += n*aux*(aux+1)/2;
            sumY %= mod;
        }
    
    // cout << sumX << " " << sumY << endl;
    // cout << sumX + sumY << endl;
    ll aux = (sumX + sumY)%mod;
    res = (aux * res)%mod;
    cout << res << endl;
	return 0;
}
