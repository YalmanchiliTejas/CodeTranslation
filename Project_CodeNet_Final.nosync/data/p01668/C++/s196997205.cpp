#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int M = 1e9 + 7;

int solve(string A, string C) {
    int const n = A.size();
    int const m = C.size();
    reverse(A.begin(), A.end());
    reverse(C.begin(), C.end());
    vector<vector<int>> match(m + 1, vector<int>(10));
    for(int d = 0; d <= 9; ++d) {
        char ch = '0' + d;
        for(int i = 0; i <= m; ++i) {
            int len = 0;
            for(int j = min(i + 1, m); j >= 1; --j) {
                if(C.substr(0, j) == C.substr(i - j + 1, j - 1) + ch) {
                    len = j;
                    break;
                }
            }
            match[i][d] = len;
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(2));
    vector<vector<int>> dp0(m + 1, vector<int>(2)); // leading zero
    vector<vector<vector<int>>> dp2(n + 1, vector<vector<int>>(2, vector<int>(2)));
    dp[0][0] = 1;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        vector<vector<int>> nxt(m + 1, vector<int>(2)), nxt0(m + 1, vector<int>(2));
        for(int k = 0; k < 2; ++k) {
            for(int d = 0; d <= 9; ++d) {
                char ch = '0' + d;
                bool nk = k && ch == A[i] || ch > A[i];
                if(d == 0) {
                    (dp2[i + 1][nk][1] += dp2[i][k][0]) %= M;
                    (dp2[i + 1][nk][1] += dp2[i][k][1]) %= M;
                } else {
                    (dp2[i + 1][nk][0] += dp2[i][k][0]) %= M;
                    (dp2[i + 1][nk][0] += dp2[i][k][1]) %= M;
                }
            }
        }
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k < 2; ++k) {
                for(int d = 0; d <= 9; ++d) {
                    char ch = '0' + d;
                    bool nk = k && ch == A[i] || ch > A[i];
                    int nj = match[j][d];
                    if(d == 0) {
                        (nxt0[nj][nk] += dp[j][k]) %= M;
                        (nxt0[nj][nk] += dp0[j][k]) %= M;
                    } else {
                        (nxt[nj][nk] += dp[j][k]) %= M;
                        (nxt[nj][nk] += dp0[j][k]) %= M;
                    }
                }
            }
        }
        (dp2[i + 1][0][0] += nxt[m][0]) %= M;
        (dp2[i + 1][0][1] += nxt0[m][0]) %= M;
        (dp2[i + 1][1][0] += nxt[m][1]) %= M;
        (dp2[i + 1][1][1] += nxt0[m][1]) %= M;
        dp = move(nxt);
        dp0 = move(nxt0);
    }

    for(int i = 1; i <= n; ++i) {
        (res += dp2[i][0][0]) %= M;
        if(i != n) {
            (res += dp2[i][1][0]) %= M;
        }
    }
    if(C == "0") {
        (res += 1) % M;
    }
    return res;
}

string decrement(string A) {
    for(int i = A.size() - 1; i >= 0; --i) {
        if(A[i] > '0') {
            A[i]--;
            break;
        } else {
            A[i] = '9';
        }
    }
    if(A[0] == '0' && A.size() > 1) {
        return A.substr(1);
    } else {
        return A;
    }
}

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    if(A != "0") {
        cout << (solve(B, C) - solve(decrement(A), C) + M) % M << endl;
    } else {
        cout << solve(B, C) << endl;
    }
}
