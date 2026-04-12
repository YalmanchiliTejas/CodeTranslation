#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 3000 + 5, mod = 998244353;
int dp[N][N][2], s, a[N], n;
int solve(int idx, int sum, int st) {
    if (sum > s) return 0;
    if (st == 2) return (sum == s);
    if (idx == n) return 0;
    int &ret = dp[idx][sum][st];
    if (~ret) return ret;
    if (st == 0) {
        ret = solve(idx, sum, 1);
        ret += solve(idx + 1, sum, 0) % mod;
        ret %= mod;
    } else if (st == 1) {
        ret = solve(idx + 1, sum, st);
        ret += solve(idx + 1, sum + a[idx], st) % mod;
        ret %= mod;
        ret += solve(idx + 1, sum + a[idx], 2) % mod;
        ret %= mod;
        ret += solve(idx, sum, 2);
        ret %= mod;
    }
    return ret;
}
int main() {
    memset(dp ,-1, sizeof dp);
    cin >> n >> s;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cout << solve(0, 0, 0);
    return 0;
}
