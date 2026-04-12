#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll inv_mod(ll a, ll MOD)
{
    ll b = MOD, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t*b;   swap(a,b);
        u -= t*v;   swap(u,v);
    }
    u %= MOD;
    if(u < 0) u+= MOD;
    return u;
}

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    const ll MOD = 1e9+7;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a.at(i);
        sum += a.at(i);
        sum %= MOD;
    }
    ll ans = 0;
    rep(i,n){
        ans += a.at(i)*sum;
        ans %= MOD;
        ans += MOD - a.at(i)*a.at(i)%MOD;
        ans %= MOD;
    }
    ans *= inv_mod(2ll, MOD);
    cout << ans%MOD << endl;


    return 0;
}