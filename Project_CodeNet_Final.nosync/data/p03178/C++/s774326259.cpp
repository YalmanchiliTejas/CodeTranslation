#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string k; cin >> k;
    int n = k.length();
    int d; cin >> d;
    long long dp[2][d];
    for (int i = 0; i < d; i++) dp[0][i] = 0;
    int pfx = 0;
    for (int i = 0; i < n; i++) {
        for (int ki = 0; ki < d; ki++) {
            dp[(i % 2) ^ 1][ki] = 0;
        }
        for (int j = 0; j < (i == n - 1 ? k[i] - '0' + 1 : k[i] - '0'); j++) {
            dp[(i % 2) ^ 1][(pfx + j) % d] += 1;
            dp[(i % 2) ^ 1][(pfx + j) % d] %= MOD;
        }
        for (int j = 0; j < 10; j++) {
            for (int ki = 0; ki < d; ki++) {
                dp[(i % 2) ^ 1][(ki + j) % d] += dp[i % 2][ki];
                dp[(i % 2) ^ 1][(ki + j) % d] %= MOD;
            }
        }
        pfx += k[i] - '0'; pfx %= d;
    }
    cout << (dp[n % 2][0] + MOD - 1) % MOD;
    return 0;
}
