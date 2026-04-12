#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return (t * t) % mod;
    } else {
        return (modpow(m, n - 1) * m) % mod;
    }
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

int main() {
    long long n, k, ans = 0;
    cin >> n;
    vector<long long> as(n);
    REP(i, n) { cin >> as[i]; }
    vector<vector<long long>> dp(n / 2, vector<long long>(2));
    dp[0][0] = as[0];
    dp[0][1] = as[1];
    for (long long i = 1; i < n / 2; i++) {
        REP(j, 2) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + as[2 * i];
            }
            if (j == 1) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][0]) + as[2 * i + 1];
            }
        }
    }
    if (n % 2 == 0) {
        cout << max(dp[n / 2 - 1][0], dp[n / 2 - 1][1]) << endl;
    } else {
        long long big = max(dp[n / 2 - 1][0], dp[n / 2 - 1][1]);
        long long take = 0;
        REP(i, n / 2) {
            take += as[n - 1 - i * 2];
            if (i == n / 2 - 1) {
                if (take > big) {
                    big = take;
                }
                continue;
            }
            if (take + max(dp[(n - 2 * i - 2) / 2 - 1][0], dp[(n - 2 * i - 2) / 2 - 1][1]) > big) {
                big = take + max(dp[(n - 2 * i - 2) / 2 - 1][0], dp[(n - 2 * i - 2) / 2 - 1][1]);
            }
        }
        cout << big << endl;
    }
}