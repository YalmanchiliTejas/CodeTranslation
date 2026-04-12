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
    long long solve(vector<int>& A) {
        int n = A.size();

        const long long INF = 1LL << 50;
        int m = 3;
        int mx = n % 2 == 0 ? 2 : 3;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(m, vector<long long>(mx + 1, -INF)));
        auto ndp = dp;
        dp[0][0][1] = 0;
        dp[0][0][0] = A[0];
        for (int i = 1; i < n; ++i) {
            for (auto& VV : ndp) {
                for (auto& V : VV) {
                    fill(V.begin(), V.end(), -INF);
                }
            }

            for (int a = 0; a < m; ++a) {
                for (int b = 0; b < m; ++b) {
                    for (int k = 0; k <= mx; ++k) {
                        // if (dp[j][k] < 0) {
                        //     continue;
                        // }
                        for (int l = 0; l < 2; ++l) {
                            int nk = 0;
                            int w = 0;
                            if (l == 0) {
                                nk = k + 1;
                            } else {
                                if (k == 0) {
                                    nk = 123;
                                }
                                w = A[i];
                            }
                            if (nk > mx) {
                                continue;
                            }
                            int na = a;
                            if (nk == 2) {
                                ++na;
                            }
                            if (na >= m) {
                                continue;
                            }
                            int nb = b;
                            if (nk == 3) {
                                ++nb;
                            }
                            if (nb >= m) {
                                continue;
                            }
                            ndp[na][nb][nk] = max(ndp[na][nb][nk], dp[a][b][k] + w);
                        }
                    }
                }
            }
            swap(ndp, dp);
        }

        long long res = -INF;
        if (n % 2 == 0) {
            // cout << dp[0][0][1] << " " << dp[0][0][0] << " " << dp[1][0][0] << endl;
            res = max(dp[0][0][1], dp[0][0][0]); 
            res = max(res, dp[1][0][0]);
        } else {
            res = max(res, dp[0][0][1]);
            res = max(res, dp[1][0][0]);
            res = max(res, dp[1][0][1]);
            res = max(res, dp[1][0][2]);
            res = max(res, dp[2][0][0]);
            res = max(res, dp[1][1][0]);
        }

        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.solve(A) << "\n";

    return 0;
}