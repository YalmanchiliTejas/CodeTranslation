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
vector<vector<long long>> dp;

long long solve(int i, int j) {
    if (i == j) return a[i];
    if (i + 1 == j) return max(a[i], a[j]);
    if (dp[i][j] != -1) return dp[i][j];

    long long ans = a[i] + min(solve(i+2, j), solve(i+1, j-1));
    ans = max(ans, a[j] + min(solve(i, j-2), solve(i+1, j-1)));
    dp[i][j] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dp = vector<vector<long long>>(n, vector<long long>(n, -1));
    a = vector<long long>(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long x = solve(0, n-1);
    long long y = accumulate(a.begin(), a.end(), 0LL) - x;
    cout << x - y << '\n';
}
