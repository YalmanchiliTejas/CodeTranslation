#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int nax = 10123;
char k[nax];
const int mod = 1e9 + 7;

void add_self(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

signed main() {
    scanf("%s", k);
    int D;
    scanf("%d", &D);
    int len = strlen(k);
    vector<vector<int>> dp(D, vector<int>(2));
    // dp[sum][smaller_already] - the number of ways to choose digits so far
    // such that the sum of digits modulo D is 'sum' and 'smaller_already'
    // says whether we already chosen some digit smaller than in K
    dp[0][0] = 1;
    for (int where = 0; where < len; where++) {
        vector<vector<int>> new_dp(D, vector<int>(2));
        for (int sum = 0; sum < D; sum++) {
            for (bool sm_already : {false, true}) {
                for (int digit = 0; digit < 10; digit++) {
                    if (digit > k[where] - '0' && !sm_already) {
                        break;
                    }
                    add_self(new_dp[(sum + digit) % D][sm_already || (digit < k[where] - '0')],
                        dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }
    int answer = (dp[0][false] + dp[0][true]) % mod;
    --answer;
    if (answer == -1) {
        answer = mod - 1;
    }
    printf("%d\n", answer);
    return false;
}