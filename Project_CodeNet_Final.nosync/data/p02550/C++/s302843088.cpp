#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char newl = '\n';

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> memo(m + 10, x % m);
    vector<ll> sums(m + 11, 0);
    map<ll, int> ids;
    ids[memo[0]] = 0;
    ll ans = 0;
    for (ll i = 1; i <= m + 9; i++) {
        sums[i] = sums[i - 1] + memo[i - 1];
        if (i == n) {
            ans = sums[i];
            break;
        }

        memo[i] = memo[i - 1] * memo[i - 1] % m;
        if (ids.find(memo[i]) != ids.end()) {
            n -= ids[memo[i]];
            ll hoge = i - ids[memo[i]];
            ll loop_num = n / hoge;
            ans = sums[ids[memo[i]]] + loop_num * (sums[i] - sums[ids[memo[i]]]) + (sums[ids[memo[i]] + n % hoge] - sums[ids[memo[i]]]);
            break;
        }
        ids[memo[i]] = i;
    }
    cout << ans << newl;

    return 0;
}