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

int dp[2][101][2];
// {dp, new_dp}, sum, is_small

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string k;
    int d, f = 0;
    cin >> k >> d;
    int n = k.length();

    dp[0][0][0] = 1;
    for (int pos = 0; pos < n; ++pos) {
        for (int sum = 0; sum < d; ++sum) {
            for (bool small:{false, true}) {
                for (int dig = 0; dig < 10; ++dig) {
                    if (dig > k[pos] - '0' && !small)break;
                    add(dp[f ^ 1][(sum + dig) % d][small || dig < k[pos] - '0'], dp[f][sum][small]);
                }
            }
        }
        for (int sum = 0; sum < d; ++sum)
            for (bool small:{false, true})
                dp[f][sum][small] = 0;
        f ^= 1;
    }
    cout << (dp[f][0][false] + dp[f][0][true] - 1 + mod) % mod << endl;
}