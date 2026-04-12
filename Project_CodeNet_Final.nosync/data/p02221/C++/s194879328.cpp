#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int len = 1 << n;

    vector<vector<int>> dp(len, vector<int>(n + 1));
    for (int i = 0; i < len; i++)cin >> dp[i][0];

    for (int times = 1; times <= n; times++) {
        for (int i = 0; i < len; i++) {
            int j = i + (1 << (times - 1));
            j %= len;

            int front = dp[i][times - 1], back = dp[j][times - 1];
            dp[i][times] = s[abs(front - back) - 1] == '0' ? min(front, back) : max(front, back);
        }
    }

    for (int i = 0; i < len; i++) cout << dp[i][n] << endl;
    return 0;
}

