#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, -1));
    auto f = [&](auto g, i64 l, i64 r) -> i64 {
        if (l < 0 || l > n || r < 0 || r > n) return 0;
        if (l == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = (n - (r - l)) % 2
            ? min(g(g, l + 1, r) - a[l], g(g, l, r - 1) - a[r - 1])
            : max(g(g, l + 1, r) + a[l], g(g, l, r - 1) + a[r - 1]);
    };
    cout << f(f, 0, n) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
