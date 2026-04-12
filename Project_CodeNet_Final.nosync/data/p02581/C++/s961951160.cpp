#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    vector<int> A(3 * n, 0);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> A[i];
        --A[i];
    }

    const int INF = 1 << 20;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -INF));
    
    auto update = [&](int i, int j, int x) {
        dp[i][j] = dp[j][i] = max(x, max(dp[j][i], dp[i][j]));
        dp[i][n] = dp[n][i] = max(x, max(dp[i][n], dp[n][i]));
        dp[j][n] = dp[n][j] = max(x, max(dp[j][n], dp[n][j]));
        dp[n][n] = max(dp[n][n], x);
    };

    update(A[0], A[1], 0);

    int base = 0;
    for (int i = 2; i + 3 <= 3 * n; i += 3) {
        vector<int> B{A[i], A[i + 1], A[i + 2]};
        vector<vector<int>> DP{dp[A[i]], dp[A[i + 1]], dp[A[i + 2]]};
        auto dpn = dp[n];

        if (A[i] == A[i + 1] && A[i + 1] == A[i + 2]) {
            ++base;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    DP[j][i] -= 1;
                }
                dpn[i] -= 1;
            }
        }

        for (int _ = 0; _ < 3; ++_) {
            {
                //[i, j, a, b, c] - [j, a, b] = [i, c]
                for (int i = 0; i <= n; ++i) {
                    int mx = dpn[i];
                    if (B[0] == B[1]) {
                        mx = max(mx, DP[0][i] + 1);
                    } 
                    update(i, B[2], mx);
                }
            }

            {
                //[i, j, a, b, c] - [i, j, a] = [b, c]
                int mx = dpn[n];
                mx = max(mx, DP[0][B[0]] + 1);
                update(B[1], B[2], mx);
            }
            rotate(B.begin(), B.begin() + 1, B.end());
            rotate(DP.begin(), DP.begin() + 1, DP.end());
        }
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int ans = dp[i][j];
            if (i == j && A.back() == i) {
                ++ans;
            }
            res = max(res, ans);
        }
    }

    res += base;

    cout << res << '\n';

    return 0;
}