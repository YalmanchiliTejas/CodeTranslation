#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;

    ll ans = 0;

    ll now = x;
    vector<ll> sum;

    map<ll, int> mp;

    if (x == 1) {
        cout << x * n << endl;
        return 0;
    }

    sum.push_back(0);

    rep(i, n) {
        sum.push_back(now);
        if (mp.count(x) == 0)
            mp[x] = i + 1;
        else {
            ll sa = n - i;
            ll phase = i - mp[x] + 1;
            ll plus = sum[sum.size() - 1] - sum[mp[x]];

            //cout << plus << endl;

            ans += sa / phase * plus;
            sa -= sa / phase * phase;

            ans += sum[mp[x] + sa - 1] - sum[mp[x] - 1];
            break;
        }

        ans += x;

        x *= x;
        x %= m;

        now += x;

        if (x == 0)
            break;
    }

    cout << ans << endl;

    return 0;
}
