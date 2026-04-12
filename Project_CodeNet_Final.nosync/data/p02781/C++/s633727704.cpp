#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    // 桁, 0以外の個数, キツイか
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
    dp[0][0][true] = 1;
    for (int index = 0; index < n; index++) {
        for (int count = 0; count <= k; count++) {
            for (int num = 0; num <= 9; num++) {
                if (num == 0) {
                    dp[index + 1][count][s[index] == '0'] += dp[index][count][true];
                    dp[index + 1][count][false] += dp[index][count][false];
                } else if (count + 1 <= k) {
                    if (s[index] - '0' > num) dp[index + 1][count + 1][false] += dp[index][count][true];
                    else if (s[index] - '0' == num) dp[index + 1][count + 1][true] += dp[index][count][true];
                    dp[index + 1][count + 1][false] += dp[index][count][false];
                }
            }
        }
    }

    cout << dp[n][k][true] + dp[n][k][false] << endl;
    return 0;
}