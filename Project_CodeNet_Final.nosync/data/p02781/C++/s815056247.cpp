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
    long long solve(string& N, int K) {
        int n = N.length();

        vector<vector<long long>> dp(2, vector<long long>(K + 1, 0));
        dp[0][0] = 1;
        auto ndp = dp;
        for (int i = 0; i < n; ++i) {
            for (auto& V : ndp) {
                for (auto& x :V) {
                    x = 0;
                }
            }
            int d = N[i] - '0';

            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k <= K; ++k) {
                    int l = 0;
                    int r = 9;
                    if (j == 0) {
                        r = min(r, d);
                    }
                    for (int dd = l; dd <= r; ++dd) {
                        int nj = j;
                        if (dd < d) {
                            nj = 1;
                        }
                        int nk = k;
                        if (dd != 0) {
                            ++nk;
                        }
                        if (nk <= K) {
                            ndp[nj][nk] += dp[j][k];
                        }
                    }
                }
            }

            swap(ndp, dp);
        }


        long long res = 0;
        res += dp[0][K];
        res += dp[1][K];

        return res;
    };
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string N;
    cin >> N;
    int K;
    cin >> K;
    Solution sol;
    cout << sol.solve(N, K) << "\n";

    return 0;
}