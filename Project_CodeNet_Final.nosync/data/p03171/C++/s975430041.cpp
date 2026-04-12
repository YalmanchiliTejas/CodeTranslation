#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
long dp[maxn][maxn];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            dp[l][r] = max(a[l] - (l + 1 <= r ? dp[l + 1][r] : 0), a[r] - (r - 1 >= l ? dp[l][r - 1]: 0));
        }
    }
    cout << dp[0][n - 1] << endl;
}