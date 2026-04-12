#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MSIZE = 10101;
const long long mod = 1e9 + 7;

long long dp[MSIZE][101];

void  Precalc(int d) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i < MSIZE; i++) {
        for (int c = 0; c < 10; c++) {
            for (int p = 0; p < d; p++) {
                int n = (c + p) % d;
                dp[i][n] += dp[i - 1][p];
                dp[i][n] %= mod;
            }
        }
    }

}

long long Get(int len, int cur, int d) {
    return dp[len][(d - (cur % d)) % d];
}

long long Get(string& arr, int d, int i, int n, int cur) {
    if (i == n) return (cur % d == 0);
    long long ans = 0;
    for (int dig = 0; dig < arr[i]; dig++) {
        ans += Get(n - 1 - i, cur + dig, d);
        ans %= mod;
    }
    ans += Get(arr, d, i + 1, n, cur + arr[i]);
    ans %= mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    string k;
    cin >> k;
    int d;
    cin >> d;
    Precalc(d);
    for (char& ch : k) ch -= '0';
    cout << (mod - 1 + Get(k, d, 0, k.size(), 0)) % mod << endl;
}

