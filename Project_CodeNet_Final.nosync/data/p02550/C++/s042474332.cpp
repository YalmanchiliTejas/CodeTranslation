#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
int x, m;
const int maxN = 1e5 + 10;
int was[maxN];
int cur[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    memset(was, -1, sizeof was);
    cin >> n;
    cin >> x >> m;
    cur[0] = x;
    int from = -1;
    int to = -1;
    was[x] = 0;
    for (int i = 1; ; i++) {
        cur[i] = (1LL * cur[i - 1] * cur[i - 1]) % m;
        if (was[cur[i]] != -1) {
            from = was[cur[i]];
            to = i - 1;
            break;
        }
        else {
            was[cur[i]] = i;
        }
    }
    ll sum_per = 0;
    for (int i = from; i <= to; i++) sum_per += cur[i];
    // to + tot_cyc * (to - from + 1)
    if (n - 1 <= to) {
        ll all = 0;
        for (int i = 0; i < n; i++) all += cur[i];
        cout << all;
        return 0;
    }
    ll tot_cyc = (n - 1 - to) / (to - from + 1);
    ll ans = (tot_cyc + 1) * sum_per;
    for (int j = 0; j < from; j++) ans += cur[j];
    ll p1 = (tot_cyc + 1) * (to - from + 1) + from;
    for (ll j = 0; j < n - p1; j++) {
        ans += cur[j + from];
    }
    cout << ans;
    return 0;
}