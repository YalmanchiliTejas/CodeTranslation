#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int inf = 1e18 + 5;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> suff(n + 1);
    vector<int> d(n);
    d = a;
    reverse(d.begin(), d.end());
    for(int i = 0; i < n; i++)
    {
        suff[i + 1] = (suff[i] + d[i]) % MOD;
    }
    // deb(suff);
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        ans = (ans + (a[i] * (suff[n - 1 - i]) % MOD) % MOD) % MOD;
    }
    cout << ans % MOD << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
