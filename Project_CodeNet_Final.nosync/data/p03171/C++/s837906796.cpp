#include <bits/stdc++.h>
using namespace std;

short n;
int a[3030];

long long dp[3030][3030][2] = {0};
bitset<3030> seen[2][3030];

long long solve(short start, short end, bool turn) {
    if (start > end)
        return 0;

    if (not seen[turn][start][end]) {
        seen[turn][start][end] = true;
        dp[start][end][turn] = turn ? max(solve(start + 1, end, 0) + a[start], solve(start, end - 1, 0) + a[end])
                                    : min(solve(start + 1, end, 1) - a[start], solve(start, end - 1, 1) - a[end]);
    }

    return dp[start][end][turn];
}

int main() {
    cin >> n;
    for (short i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve(0, n - 1, 1);
}
