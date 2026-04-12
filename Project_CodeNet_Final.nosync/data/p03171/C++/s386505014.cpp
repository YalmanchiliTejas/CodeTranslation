#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll inf = 1e18;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    function<ll(int, int, int)> rec = [&] (int l, int r, int turn) {
        if(l > r) return 0LL;
        if(dp[l][r] != inf) return dp[l][r];
        ll res = (turn == 0 ? -inf : inf);
        if(turn == 0) {
            res = max({res, rec(l + 1, r, !turn) + a[l], rec(l, r - 1, !turn) + a[r]});
        } else {
            res = min({res, rec(l + 1, r, !turn) - a[l], rec(l, r - 1, !turn) - a[r]});
        }

        return dp[l][r] = res;
    };

    cout << rec(0, n - 1, 0) << endl;
}
