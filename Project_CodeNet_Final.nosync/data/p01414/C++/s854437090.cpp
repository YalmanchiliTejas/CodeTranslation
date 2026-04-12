#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int col[4][4];
    vector<int> h(n);
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> w[i];
    }
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; ++j) {
            if (s[j] == 'R') col[i][j] = 0;
            if (s[j] == 'G') col[i][j] = 1;
            if (s[j] == 'B') col[i][j] = 2;
        }
    }
    int match[4][5][4][5][3] = {};
    int mask[4][5][4][5] = {};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = i + 1; k < 5; ++k) {
                for (int l = j + 1; l < 5; ++l) {
                    for (int r = i; r < k; ++r) {
                        for (int s = j; s < l; ++s) {
                            mask[i][j][k][l] |= 1 << r * 4 + s;
                            match[i][j][k][l][col[r][s]] |= 1 << r * 4 + s;
                        }
                    }
                }
            }
        }
    }
    int dp[1 << 16];
    fill(dp, dp + (1 << 16), 32);
    queue<int> q;
    dp[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            for (int j = 1 - h[i]; j < 4; ++j) {
                int m1 = max(j, 0), m3 = min(j + h[i], 4);
                for (int k = 1 - w[i]; k < 4; ++k) {
                    int m2 = max(k, 0), m4 = min(k + w[i], 4);
                    for (int c = 0; c < 3; ++c) {
                        int t = (p & ~mask[m1][m2][m3][m4]) | match[m1][m2][m3][m4][c];
                        if (dp[t] > dp[p] + 1) {
                            dp[t] = dp[p] + 1;
                            if (t == (1 << 16) - 1)
                            {
                                cout << dp[t] << "\n";
                                return 0;
                            }
                            q.push(t);
                        }
                    }
                }
            }
        }
    }
}