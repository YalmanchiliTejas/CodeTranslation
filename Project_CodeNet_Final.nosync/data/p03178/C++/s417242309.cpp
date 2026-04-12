#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    while (a >= MOD)
        a -= MOD;
    while (a < 0)
        a += MOD;
}

int main() {
    string k; cin >> k;
    int n = k.size();
    int d; cin >> d;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (d, vector<int> (2, 0)));

    dp[0][0][1] = 1;

    for (int i = 0; i < n; i += 1)
        for (int rem = 0; rem < d; rem += 1) 
            for (int equal = 0; equal < 2; equal += 1) {
                for (int digit = 0; digit < 10; digit += 1) {
                    if (equal and digit > k[i] - '0') 
                        continue;
                    int new_rem = (rem + digit) % d;
                    add(dp[i + 1][new_rem][equal && (digit + '0' == k[i])], dp[i][rem][equal]);
                }
            }

    int ans = (dp[n][0][0] + dp[n][0][1]) % MOD;
    add(ans, -1);
    cout << ans << "\n";
}