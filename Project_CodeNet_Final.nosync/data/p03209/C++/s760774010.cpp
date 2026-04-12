#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll n, x;
ll cnt[51], dp[51];

// p          0, 1
// b(p)p(p)b    2, 3
// b(bpppb)p(bpppb)b           6, 7
void init() {
    cnt[0] = 1;
    dp[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        cnt[i] = cnt[i - 1] * 2 + 3;
        dp[i] = dp[i - 1] * 2 + 1;
    }
}
ll f(ll a, ll b) {
    if (b == 0) return 0;
    if (a == 0) return 1;
    if (b >= cnt[a]) return dp[a];
    ll res = 0;
    --b;
    if (b > cnt[a - 1]) {
        res += f(a - 1, b) + 1 + f(a - 1, b - cnt[a - 1] - 1);
    } else {
        res += f(a - 1, b);
    }
    return res;
}
int main() {
    init();
    cin >> n >> x;
    ll ans = f(n, x);
    cout << ans << endl;
    return 0;
}
