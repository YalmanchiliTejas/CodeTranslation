#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<ll> b(n);
    ll t = 0;
    ll m = 1e9;
    for (int i = n - 1; i >= 0; --i)
    {
        t += a[i];
        t %= (m + 7);
        b[i] = t;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        ans += (a[i] * b[i + 1]);
        ans %= (m + 7);
    }
    cout << ans << endl;
    return 0;
}
