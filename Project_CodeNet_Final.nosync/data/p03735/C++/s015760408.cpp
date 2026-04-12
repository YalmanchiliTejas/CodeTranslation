#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
typedef pair<ll, ll> pll;
pll d[N];
set<pll> red;
set<pll> blue;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        d[i] = pll(min(x, y), max(x, y));
    }
    sort(d, d + n);
    for (int i = 0; i < n; i++) {
        red.insert(pll(d[i].first, i));
        blue.insert(pll(d[i].second, i));
    }
    ll res = (red.rbegin()->first - red.begin()->first) * (blue.rbegin()->first - blue.begin()->first);
    for (int i = 0; i < n; i++) {
        red.erase(pll(d[i].first, i));
        blue.erase(pll(d[i].second, i));
        red.insert(pll(d[i].second, i));
        blue.insert(pll(d[i].first, i));
        res = min(res, (red.rbegin()->first - red.begin()->first) * (blue.rbegin()->first - blue.begin()->first));
    }
    cout << res << endl;
    return 0;
}
