#include <bits/stdc++.h>

using namespace std;

int calcAny(int n, int cnt) {
    if (cnt > n) {
        return 0;
    }
    int res = 1;
    int div = 1;
    for (int i = 0; i < cnt; i++) {
        div *= i+1;
        res *= 9*(n-i);
    }
    return res / div;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    vector<vector<int>> dp(k+1, vector<int>(n+1));
    dp[0].assign(n+1, 1);
    for (int d = 1; d <= k; d++) {
        for (int i = n-1; i >= 0; i--) {
            int cur = 0;
            int ls = s[i] - '0';
            if (ls > 0) {
                int rem = n-1-i;
                cur = (ls-1)*calcAny(rem, d-1) + calcAny(rem, d) + dp[d-1][i+1];
            } else {
                cur = dp[d][i+1];
            }
            dp[d][i] = cur;
        }
    }
    cout << dp[k][0] << endl;
}


