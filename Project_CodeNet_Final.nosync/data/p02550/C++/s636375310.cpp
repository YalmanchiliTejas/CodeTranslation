#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, x, m;
    cin >> n >> x >> m;
    vector<int> a;
    map<int, int> mp;
    int cnt = 0;
    ll tot = 0;
    while(mp.count(x) == 0) {
        a.push_back(x);
        tot += x;
        mp[x] = cnt++;
        x = (x * x) % m;
    }

    if(n <= cnt) {
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i];
        }
        cout << ans << endl;
        return 0;
    }

    ll cycle = 0;
    int rest = cnt - mp[x];
    for (int i = mp[x]; i < cnt; ++i) {
        cycle += a[i];
    }
    n -= cnt;
    ll ans = tot;
    ans += (n / rest) * cycle;
    n %= rest;
    int si = mp[x];
    for (int i = 0; i < n; ++i) {
        ans += a[si + i];
    }
    cout << ans << endl;
}
