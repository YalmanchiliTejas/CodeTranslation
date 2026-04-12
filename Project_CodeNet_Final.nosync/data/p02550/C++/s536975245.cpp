#include <bits/stdc++.h>
#define ll long long
#define EPS 1e-9
#define rank asadf
using namespace std;

const int MAXN = 3e5 + 111;
const int MOD = 998244353;

int was[MAXN];

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    int x, m;
    cin >> n >> x >> m;
    if (n <= 3 * m) {
        ll ans = 0;
        ll cur = x;
        for (int i = 0; i < n; ++i) {
            ans += cur;
            cur = (cur * 1LL * cur) % m;
        }
        cout << ans;
        return 0;
    }
    int cur = x;
    int pre = 0, cycle = 0;
    ll sum_pre = 0, sum_cycle = 0;
    int cycle_start = -1;
    while (true) {
        if (was[cur] == 2) {
            cycle_start = cur;
            break;
        }
        ++was[cur];
        cur = (cur * 1LL * cur) % m;
    }
    for (int i = 0; i < m; ++i) {
        if (was[i] == 1) {
            ++pre;
            sum_pre += i;
        }
        if (was[i] == 2) {
            ++cycle;
            sum_cycle += i;
        }    
    }
    ll times = (n - pre) / cycle;
    ll ans = sum_pre + sum_cycle * times;
    cur = cycle_start;
    for (ll i = pre + cycle * times; i < n; ++i) {
        ans += cur;
        cur = (cur * 1LL * cur) % m;
    }
    cout << ans;
    return 0;
}
