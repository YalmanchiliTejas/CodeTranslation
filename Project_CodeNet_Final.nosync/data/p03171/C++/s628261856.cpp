#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

pair<ll, ll> dp[4000][4000];
vector<ll> a(4000);

pair<ll, ll> solve1(ll l, ll r);
pair<ll, ll> solve2(ll l, ll r);

pair<ll, ll> solve1(ll l, ll r) {
    if (l == r) {
        return {a[l], 0};
    }
    if (dp[l][r] != make_pair(0ll, 0ll)) {
        return dp[l][r];
    }
    auto c = solve2(l + 1, r);
    auto d = solve2(l, r - 1);
    c.first += a[l];
    d.first += a[r];
    if (c.first - c.second >= d.first - d.second) {
        dp[l][r] = c;
    } else {
        dp[l][r] = d;
    }
    return dp[l][r];
}

pair<ll, ll> solve2(ll l, ll r) {
    if (l == r) {
        return {0, a[l]};
    }
    if (dp[l][r] != make_pair(0ll, 0ll)) {
        return dp[l][r];
    }
    auto c = solve1(l + 1, r);
    auto d = solve1(l, r - 1);
    c.second += a[l];
    d.second += a[r];
    if (c.first - c.second <= d.first - d.second) {
        dp[l][r] = c;
    } else {
        dp[l][r] = d;
    }
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cout.precision(20); cout << fixed;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto ans = solve1(0, n - 1);
    cout << ans.first - ans.second;
}
