#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;
const int MOD = 1e9 + 7;

int dp[N][105][2];
// dp[i][j][k] means the count of numbers which at pos i, 
// with sum of each digit modulo D equals to j
// if k == 1, then it hasn't chosen any digit that is smaller than k
// how to ensure all numbers in result is smaller than K?
char K[N];
int d;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int sub(int a, int b) {
    int res = a - b;
    if (res < 0) res += MOD;
    return res;
}

void solve() {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    // for (int i = 0; i < K[0] - '0'; ++i) dp[0][i][0] = 1;
    // dp[0][K[0] - '0'][1] = 1;
    int len = strlen(K);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < d; ++j) {
            for (bool sm_already : {false, true}) {
                for (int k = 0; k < 10; ++k) {
                    if (k > K[i] - '0' && !sm_already) {
                        break;
                    }
                    add(dp[i + 1][(j + k) % d][sm_already || (k < K[i] - '0')], dp[i][j][sm_already]);
                }
            }
        }
    }
    printf("%d\n", sub((dp[len][0][0] + dp[len][0][1]) % MOD, 1));
}

void debug() {
    for (int i = 0; K[i]; ++i, putchar('\n')) {
        for (int j = 0; j <= d; ++j) {
            printf("%10d %10d ", dp[i][j][0], dp[i][j][1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (~scanf("%s%d", K, &d)) {
        solve();
        // debug();
    }
    return 0;
}