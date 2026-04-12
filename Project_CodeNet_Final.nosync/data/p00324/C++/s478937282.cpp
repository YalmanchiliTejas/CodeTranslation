#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    map<ll, ll> p;
    p[0] = 0;
    ll now = 0, ans = 0;
    for(int i = 1; i <= n; ++i) {
        ll d; cin >> d;
        now += d;
        if(p.count(now) == 0) p[now] = i;
        ans = max(ans, i - p[now]);
    }
    cout << ans << endl;
}

