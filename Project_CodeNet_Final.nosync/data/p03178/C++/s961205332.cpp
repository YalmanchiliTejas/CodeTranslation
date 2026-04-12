#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void add_self(int& a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

int main(int argc, char *argv[])
{
    string K;
    int D;
    cin >> K >> D;
    int len = K.size();
    vector<vector<int>> dp(D, vector<int>(2));
    dp[0][0] = 1;
    for (int where = 0; where < len; where++) {
        auto dp_new = vector<vector<int>>(D, vector<int>(2));
        int limit = K[where] - '0';
        for (int sum = 0; sum < D; sum++) {
            for (int digit = 0; digit < limit; digit++) {
                add_self(dp_new[(sum + digit) % D][1], dp[sum][1] + dp[sum][0]);
            }
            add_self(dp_new[(sum + limit) % D][0], dp[sum][0]);
            add_self(dp_new[(sum + limit) % D][1], dp[sum][1]);
            for (int digit = limit + 1; digit <= 9; digit++) {
                add_self(dp_new[(sum + digit) % D][1], dp[sum][1]);
            }
        }
        dp = dp_new;
    }
    int res = dp[0][0];
    add_self(res, dp[0][1]);
    res -= 1;
    if (res < 0) res += M;
    cout << res << endl;
    return 0;
}
