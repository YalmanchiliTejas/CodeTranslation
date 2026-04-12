#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    deque<ll> b;
    rep(i, n) { cin >> a[i]; }
    rep(i, n)
    {
        if (i % 2 == n % 2) {
            b.push_back(a[i]);
        } else {
            b.push_front(a[i]);
        }
    }
    rep(i, n)
    {
        printf("%lld ", b[i]);
    }
    return 0;
}