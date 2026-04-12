#include <bits/stdc++.h>

using namespace std;

const int MAX = 3005;
int64_t dp[MAX][MAX];
vector<int> vals(MAX, 0);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> vals[i];

    for (int L = n - 1; L >= 0; L--) {
        for (int R = L; R < n; R++) {
            if (L != R) {
                dp[L][R] = max(vals[L] - dp[L + 1][R], vals[R] - dp[L][R - 1]);
            }
            else {
                dp[L][R] = vals[L];
            }
        }
    }

    cout << dp[0][n - 1];
    return 0;
}

