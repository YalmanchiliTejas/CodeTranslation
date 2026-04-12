#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = (ll)(1e9 + 7);

ll powe(ll x, ll y)
{
    ll temp = 1;
    while (y)
    {
        if (y & 1)
            temp *= x, temp %= mod;
        y = y >> 1;
        x *= x;
        x %= mod;
    }
    return temp;
}

int main()
{
    ll sum = 0;
    ll sq = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
        sq += (a[i] * a[i]) % mod;
        sq %= mod;
    }
    sum *= sum;
    sum %= mod;
    cout << (((sum - sq + mod) % mod) * powe(2, mod - 2)) % mod << "\n";
}