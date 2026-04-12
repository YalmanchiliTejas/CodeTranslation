#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) t[i] = s[i] + s[n - 1 - i];

    forx(c, 1, n)
    {
        ll d = 0, e = 0;
        if ((n - 1) % c == 0)
        {
            rep(k, n - 1)
            {
                if (c * (k + 1) >= (n - 1) / 2)
                    break;
                e += t[c * (k + 1)];
                d = max(d, e);
            }
        }
        else
            rep(k, n - 1)
            {
                if (c * (k + 2) > n)
                    break;
                e += t[c * (k + 1)];
                d = max(d, e);
            }
        ans = max(ans, d);
    }

    cout << ans << endl;

    return 0;
}