#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    string s;
    int K;
    cin >> s >> K;
    int l = s.size();
    vector<vector<long long>> dp;
    dp.assign(l, vector<long long>(4));
    int count = 0;
    rep(i, 0, l) {
        int t = s[i] - '0';
        // cout << "ddd:" << t << "  count" << count << endl;
        if(i == 0) {
            dp[i][0] = 1;
            dp[i][1] = t;
            count++;

            continue;
        }
        int tb = s[i - 1] - '0';
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 1][0] * 9;
        dp[i][2] = dp[i - 1][2] + dp[i - 1][1] * 9;
        if(count == 1) {
            dp[i][2] -= 9 - t;
        }
        dp[i][3] = dp[i - 1][3] + dp[i - 1][2] * 9;
        if(count == 2) {
            dp[i][3] -= 9 - t;
        }
        if(t != 0) {
            count++;
        }
    }
    cout << dp[l - 1][K] << endl;
}
