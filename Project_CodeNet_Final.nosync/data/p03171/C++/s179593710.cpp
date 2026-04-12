#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

vector<vector<vector<long long>>> dp;

long long solve(int start, int end, int turn) {
    if (start > end)
        return 0;
    if (dp[start][end][turn] == 3000000000001)
        dp[start][end][turn] = turn ? max(solve(start + 1, end, 0) + a[start], solve(start, end - 1, 0) + a[end])
                                    : min(solve(start + 1, end, 1) - a[start], solve(start, end - 1, 1) - a[end]);

    return dp[start][end][turn];
}

int main() {
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp.resize(n, vector<vector<long long>>(n, vector<long long>(2, 3000000000001)));
    cout << solve(0, n - 1, 1);
}