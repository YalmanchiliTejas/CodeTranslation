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

class Solution {
public:
    int solve(vector<int>& A, int S) {
        const int MOD = 998244353;
        int n = A.size();
        const int N = 3010;
        vector<int> dp(N, 0);

        long long res = 0;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (dp[j] == 0) {
                    continue;
                }
                int s = j + A[i];
                if (s == S) {
                    // cout << i << " " << A[i] << " " << dp[j] << endl;
                    res += ((j == 0 ? (i + 1) : dp[j]) * 1LL * (n - i)) % MOD;
                }
                if (s > S) {
                    continue;
                }
                if (j == 0) {
                    dp[s] += i + 1;
                    if (dp[s] >= MOD) {
                        dp[s] -= MOD;
                    }
                } else {
                    dp[s] += dp[j];
                    if (dp[s] >= MOD) {
                        dp[s] -= MOD;
                    }
                }
            }
        }
        res %= MOD;
        return res;

    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution sol;
    int n, s;
    cin >> n >> s;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << sol.solve(A, s) << "\n";
    return 0;
}