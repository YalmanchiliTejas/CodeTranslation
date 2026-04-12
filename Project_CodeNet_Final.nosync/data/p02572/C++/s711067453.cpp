#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    ll s = 0;
    ll a[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s = (s + a[i]) % MOD;
    }
    ll ans = s * s % MOD;
    for(int i = 0; i < n; i++) ans = (ans + MOD - a[i] * a[i] % MOD) % MOD;
    cout << ans * modpow(2, MOD - 2) % MOD << endl;
}
