#include <bits/stdc++.h>
using ll = long long;
const int NMAX = 3030;
ll dp[NMAX][NMAX];
int main() {
for(int n; std::cin >> n; ) {
    std::vector<int> a(n);
    for (auto &it : a) std::cin >> it;
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0, j = len-1; j < n; i++,j++) {
            dp[i][j] = std::max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    std::cout << dp[0][n-1] << std::endl;
}
    return 0;
}