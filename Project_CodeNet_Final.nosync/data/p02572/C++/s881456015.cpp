#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define mod 1000000007LL
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res + m) * ( a + m) % m;
        a = a * a % m;
        b >>= 1;
    }
    return (res + m) % m;
}

long long mul(long long a, long long b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return ((a + mod) * (b + mod))%mod;
}
long long add(long long a, long long b){
    a += mod;
    b += mod;
    return (a + b)%mod;
}
ll inv(ll x){
    return binpow(x, mod - 2, mod);
}
#define int ll
ll cnt(string &a, string & b)
{
    ll ans = 0;
    for (ll i = 0; i < a.length();i++)
        ans += (a[i] != b[i]);
    return ans;
}
signed main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n;i++)
        cin >> a[i];
    ll b[n];
    b[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0;i--)
    {
        b[i] = add(b[i + 1], a[i]);
    }
    ll sum = 0;
    for (ll i = 0; i < n - 1;i++)
    {
        sum += mul(a[i], b[i + 1]);
        sum %= mod;
    }
    cout<<sum;
}