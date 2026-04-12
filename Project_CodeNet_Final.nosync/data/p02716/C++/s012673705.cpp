#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

i64 dp[200001][3][2];

int main() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    int k = 1 + (n % 2 == 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) {
        for (int t = 0; t <= 1; ++t) {
            for (int s = 0; s <= k; ++s) {
                if (i != 0 || t != 0 || s != 0) {
                    dp[i][s][t] = -1e15;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int t = 0; t <= 1; ++t) {
            for (int s = 0; s <= k; ++s) {
                if (t) {
                    dp[i][s][1] = max(dp[i][s][1], dp[i - 1][s][0] + a[i - 1]);
                } else {
                    dp[i][s][0] = max(dp[i][s][0], dp[i - 1][s][1]);
                    if (s > 0) {
                        dp[i][s][0] = max(dp[i][s][0], dp[i - 1][s - 1][0]);
                        if (i == 1 && s == 1) {
                            dp[i][s][0] = max(dp[i][s][0], i64(0));
                        }
                    }
                }
            }
        }
    }
    i64 ans = max(dp[n][k - 1][0], dp[n][k][1]);
    cout << ans << endl;
    return 0;
}