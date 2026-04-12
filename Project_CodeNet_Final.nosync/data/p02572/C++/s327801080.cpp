#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define REP(i, start, end) for (ll i = start, i##Len = (end); i < i##Len; ++i)
#define REPR(i, start, end) for (ll i = start, i##Len = (end); i > i##Len; --i)
using ll = long long;
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    const ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, 0, n)
    cin >> a[i];

    ll left = a[0], ans = 0;
    REP(i, 1, n)
    {
        ans = (ans + left * a[i]) % mod;
        left = (left + a[i]) % mod;
    }

    cout << ans << endl;
}