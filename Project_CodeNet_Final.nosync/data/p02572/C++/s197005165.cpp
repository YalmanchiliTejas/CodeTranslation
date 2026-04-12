#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += a[i]*((sum-a[i]+MOD)%MOD)%MOD;
        ans %= MOD;
    }
    cout << ans*modinv(2,MOD)%MOD << endl;
    

    
}