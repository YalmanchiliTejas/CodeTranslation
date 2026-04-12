#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

const int64_t MOD = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int d;
    cin >> d;

    vector<vector<int64_t>> dp(s.size() + 1, vector<int64_t>(d));
    int r;
    irep(i, s.size())
    {
        if (i == 0) {
            r = 0;
            rep(j, d)
            {
                dp[i][j] = 0;
            }
        } else {
            rep(j, d)
            {
                if (j == 0) {
                    dp[i][j] = 0;
                    rep(k, 10)
                    {
                        dp[i][j] += dp[i - 1][(j - k % d + d) % d];
                        dp[i][j] %= MOD;
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + (dp[i - 1][j] - dp[i - 1][(j - 10 % d + d) % d] + MOD) % MOD;
                    dp[i][j] %= MOD;
                }
            }
            int e = s[i - 1] - '0';
            rep(j, e)
            {
                dp[i][(r + j) % d]++;
                dp[i][(r + j) % d] %= MOD;
            }

            r = (r + e) % d;
        }
    }

    int64_t result = (dp[s.size()][0] + (r == 0 ? 1 : 0) - 1 + MOD) % MOD;
    cout << result << endl;

    return 0;
}