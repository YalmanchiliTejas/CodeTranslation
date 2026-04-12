#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const ll mod = 1e9+7;
const int MAX = 2e5+1;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * (ll)i % mod;
        inv[i] = mod - inv[mod%i] * (mod / (ll)i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main(){
    COMinit();
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            ans += (i*(i-1)/2 + (n-i+1)*(n-i)/2)*m + (j*(j-1)/2 + (m-j+1)*(m-j)/2)*n;
        }
    }
    (ans /= 2) %= mod;
    cout << ans*COM(n*m-2,k-2) % mod << endl;
    return 0;
}
