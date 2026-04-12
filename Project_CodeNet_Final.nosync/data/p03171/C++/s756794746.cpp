#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
const ull MOD = 998244353;
#ifdef LOCAL
#include "../../pp.hpp"
#define debug pp::debug
#else
#define debug(args...)
#endif

int n;
vector<long long> a;
vector<vector<pair<long long, int>>> dp;

pair<long long, int> solve(int i, int j) {
    if (i > j) return make_pair(0, -1);
    if (i == j) return make_pair(a[i], i);
    if (dp[i][j].first != -1) return dp[i][j];

    long long ans_l, ans_r;
    long long ans_l_my, ans_r_my;
    int idx_l, idx_r;
    int idx_l_my, idx_r_my;
    tie(ans_r, idx_r) = solve(i+1, j);
    tie(ans_l, idx_l) = solve(i, j-1);

    if (idx_r == i+1) {
        tie(ans_r_my, idx_r_my) = solve(i+2, j);
    } else {
        assert(idx_r == j);
        tie(ans_r_my, idx_r_my) = solve(i+1, j-1);
    }

    if (idx_l == i) {
        tie(ans_l_my, idx_l_my) = solve(i+1, j-1);
    } else {
        assert(idx_l == j-1);
        tie(ans_l_my, idx_l_my) = solve(i, j-2);
    }

    long r_val = a[i] + ans_r_my - a[idx_r];
    long l_val = a[j] + ans_l_my - a[idx_l];
    if (r_val > l_val) {
        dp[i][j] = make_pair(r_val, i);
    } else {
        dp[i][j] = make_pair(l_val, j);
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dp = vector<vector<pair<long long, int>>>(n, vector<pair<long long, int>>(n, make_pair(-1, -1)));
    a = vector<long long>(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans; int idx;
    tie(ans, idx) = solve(0, n - 1);

    cout << ans << '\n';
}
