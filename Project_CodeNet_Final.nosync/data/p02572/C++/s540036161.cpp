// Author: HarshKumar

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll N = 1e6 + 6, M = 1e9 + 7;
ll in(ll a, ll b = M - 2, ll m = M)
{
    ll r = 1;
    while (b)
    {
        if (b % 2)
            r = r * a % m;
        a = a * a % m;
        b /= 2;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, s = 0, ss = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll &e : a)
        cin >> e, s = (s + e) % M, ss = (ss + e * e % M) % M;
    cout << ((s * s % M - ss + M) % M * in(2) % M) % M;
}