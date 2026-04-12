// Author: HarshKumar

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll N = 1e6 + 6, M = 1e9 + 7;
ll f(ll x, ll n)
{
    ll t = (1LL << (n + 1)) - 3;
    ll y = (t + 1) / 2;
    if (n == 1)
        return 1;
    if (x == 1)
        return 0;
    if (x == t)
        return ((1LL << n) - 1);
    if (x == y)
        return (1LL << (n - 1));
    if (x > y)
        return ((1LL << (n - 1)) + f(x - y, n - 1));
    else
        return (f(x - 1, n - 1));
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    cout << f(x, n + 1);
    return 0;
}