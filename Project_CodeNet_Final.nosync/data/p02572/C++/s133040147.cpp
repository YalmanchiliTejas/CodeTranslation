#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

using namespace std;

ll m = 1e9 + 7;

ll mod(ll a, ll b)
{
    return ((a % b) + b) % b;
}

ll modmulti(ll a, ll b)
{
    return mod(mod(a, m) * mod(b, m), m);
}

ll modsum(ll a, ll b)
{
    return mod(mod(a, m) + mod(b, m), m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull ans = 0, n;
    cin >> n;
    vector<ull> v(n + 1);
    vector<ull> s(n + 1);
    for (ull i = 1; i <= n; i++)
    {
        cin >> v[i];
        s[i] = modsum(s[i - 1], v[i]);
        if (s[i] >= m)
            s[i] %= m;
    }
    for (ull i = 1; i <= n - 1; i++)
    {
        ans = modsum( ans, modmulti(v[i], s[n] - s[i]) );
        if (ans >= m)
            ans %= m;
    }
    cout << ans << endl;
}