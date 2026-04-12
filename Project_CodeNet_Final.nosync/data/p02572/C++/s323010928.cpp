#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for(ll i = 0; i < n; i++)
        cin >> v[i];
    
    vector<ll> p(n);
    p[n-1] = v[n-1];

    for(ll i = n-2; i >= 0; i--){
        p[i] = p[i+1] + v[i];
    }

    ll ans = 0;

    for(ll i = 0; i < n-1; i++){
        ans += ((v[i] % mod) * (p[i+1] % mod)) % mod;
        ans %= mod;
    }

    cout << ans << "\n";
}