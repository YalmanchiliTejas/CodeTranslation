/*
 *  Lang    : C++
 *  Author  : little_angel
 */
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

inline int mul(int a, int b) {
    return a * b % mod;
}

inline void add(int &a, int b) {
    a += b;
    if (a >= mod)a -= mod;
}

string k;
int d, dp[10001][101][2];
// pos, sum, is_small

int dfs(int pos, int sum, bool small) {
    if (pos == k.length())return sum == 0;
    if (~dp[pos][sum][small])return dp[pos][sum][small];
    int res = 0;
    for (int dig = 0; dig < 10; ++dig) {
        if (dig > k[pos] - '0' && !small)break;
        add(res, dfs(pos + 1, (sum + dig) % d, small || dig < k[pos] - '0'));
    }
    return dp[pos][sum][small] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << (dfs(0, 0, false) - 1 + mod) % mod << endl;
}