#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll moduloMul(ll a, ll b)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ll n, *a, i, ans, sum;
    cin >> n;
    a = new ll[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 1, sum = 0; i < n; i++)
        sum = sum + a[i];
    for (i = 0, ans = 0; i < n - 1; i++)
    {
        ans = (ans + moduloMul(a[i], sum)) % mod;
        sum = sum - a[i + 1];
    }
    cout << ans << endl;
}