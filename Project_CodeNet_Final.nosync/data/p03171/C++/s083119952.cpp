#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<bool>> vis;
vector<vector<int64_t>> dp;
int64_t go(int i, int j, int p) {
    if (vis[i][j])
        return dp[i][j];
    if (i == j) 
        return dp[i][j] = p * a[i];
    vis[i][j] = true;
    int64_t x = go(i + 1, j, -p) + p * a[i];
    int64_t y = go(i, j - 1, -p) + p * a[j];
    return dp[i][j] = p * x > p * y ? x : y;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    a.resize(n);
    vis.assign(n, vector<bool>(n, false));
    dp.assign(n, vector<int64_t>(n));
    for (int& it : a) cin >> it;
    // int64_t ans = go(0, n - 1, 1);
    cout << go(0, n - 1, 1) << '\n';
    return 0;
}