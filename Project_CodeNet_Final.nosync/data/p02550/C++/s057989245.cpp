#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll n, x, m;

ll order[1000009];
ll sum[1000009];

ll solve(ll n, ll x, ll m) {
    ll s = 0;
    ll loop_b = -1, loop_e = -1;
    for (ll i = 1; i <= n; i++) {
        if (order[x] != 0) {
            loop_b = order[x];
            loop_e = i;
            break;
        }
        s += x;
        order[x] = i;
        sum[i] = s;
        x = (x * x) % m;
    }
    ll ans = s;
    if (loop_b != -1) {
        ll cycle_len = loop_e - loop_b;
        ll a = (n - loop_e + 1) % cycle_len;
        ll cycle_sum = sum[loop_e - 1] - sum[loop_b - 1];
        ll cycle_num = ((n - loop_e + 1) / cycle_len);
        ans += cycle_sum * cycle_num + (sum[loop_b + a - 1] - sum[loop_b - 1]);
    }
    return ans;
}
ll _solve(ll n, ll x, ll m) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += x;
        x = (x * x) % m;
    }
    return ans;
}
int main() {
    cin >> n >> x >> m;
    printf("%lld\n", solve(n, x, m));
    return 0;
}