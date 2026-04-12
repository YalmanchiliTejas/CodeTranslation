#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
typedef pair<ll, ll> pll;
#define pb push_back
typedef long double ld;
#define fi first
#define se second
#define PI 3.14159265358979323846264338327950288419716939937510
#define mp make_pair
ll inf = 1e18;
ll p = 1e9 + 7;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll pwr(ll x, ll y)
{
    ll res = 1;
    x = x ;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) ;
        y = y >> 1;
        x = (x * x) ;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, y, x,  z, w, g, key,  k, n, m, a, b;
    ll t2, t3, t4, t1, t5, t6;
    string s, t;

    cin >> n;
    ll arr[n];
    ll sum = 0;
    ll sq = 0;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sq = (sq + arr[i] * arr[i]) % p;

    }
    sum %= p;
    sum = (sum * sum) % p;
    ll ans = ((sum - sq + p) % p) * modInverse(2, p);
    ans %= p;
    ans = (ans + p) % p;
    cout << ans;

    return 0;
}