#include <cassert>
#include <algorithm>
#include <tuple>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

bool all_eq(int a, int b, int c) {
    return a == b && b == c;
}

int dp[2001][2001];
int solve(int n, const int *a) {
    for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n; k++)
            dp[j][k] = -(1<<30);
    {
        int x = min(a[0], a[1]), y = max(a[0], a[1]);
        dp[0][0] = dp[0][x] = dp[0][y] = dp[x][y] = 0;
    }
    int add = 0;
    for (int i = 2; i < 3*n-1; i += 3) {
        int x = a[i], y = a[i+1], z = a[i+2];
        if (all_eq(x, y, z)) { add++; continue; }
        vector<tuple<int, int, int> > updates;
        auto transition = [&](int j, int k, int l, int m, int d) {
            updates.emplace_back(min(l, m), max(l, m), dp[min(j, k)][max(j, k)] + d);
        };
        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if (x > y) swap(x, y);
        transition(0, 0, 0, x, 0);
        transition(0, 0, 0, y, 0);
        transition(0, 0, 0, z, 0);
        transition(0, 0, x, y, 0);
        transition(0, 0, x, z, 0);
        transition(0, 0, y, z, 0);
        if (x == y) {
            assert (y < z);
            transition(0, x, 0, 0, 1);
            transition(0, x, 0, z, 1);
            for (int j = 1; j <= n; j++) {
                transition(j, x, 0, j, 1);
                transition(j, x, j, z, 1);
            }
        }
        if (y == z) {
            assert (x < y);
            transition(0, y, 0, 0, 1);
            transition(0, y, 0, x, 1);
            for (int j = 1; j <= n; j++) {
                transition(j, y, 0, j, 1);
                transition(j, y, j, x, 1);
            }
        }
        transition(x, x, 0, 0, 1);
        transition(x, x, 0, y, 1);
        transition(x, x, 0, z, 1);
        transition(x, x, y, z, 1);
        transition(y, y, 0, 0, 1);
        transition(y, y, 0, x, 1);
        transition(y, y, 0, z, 1);
        transition(y, y, x, z, 1);
        transition(z, z, 0, 0, 1);
        transition(z, z, 0, x, 1);
        transition(z, z, 0, y, 1);
        transition(z, z, x, y, 1);
        for (int j = 1; j <= n; j++) {
            transition(0, j, x, j, 0);
            transition(0, j, y, j, 0);
            transition(0, j, z, j, 0);
        }
        for (auto [j, k, m] : updates) dp[j][k] = max(dp[j][k], m);
    }
    dp[a[3*n-1]][a[3*n-1]]++;
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            ans = max(ans, dp[j][k]);
        }
    }
    return ans + add;
}

int cubic(int n, const int *a) {
    int dp[n+1][n+1];
    for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n; k++)
            dp[j][k] = -(1<<30);
    dp[a[0]][a[1]] = 0;
    for (int i = 2; i < 3*n-1; i += 3) {
        int x = a[i], y = a[i+1], z = a[i+2];
        vector<tuple<int, int, int> > updates;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                int tmp[] = {j, k, x, y, z};
                sort(tmp, tmp+5);
                do {
                    updates.emplace_back(tmp[0], tmp[1], dp[j][k] + all_eq(tmp[2], tmp[3], tmp[4]));
                } while (next_permutation(tmp, tmp+5));
            }
        }
        for (auto [j, k, m] : updates) dp[j][k] = max(dp[j][k], m);
    }
    dp[a[3*n-1]][a[3*n-1]]++;
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            ans = max(ans, dp[j][k]);
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    int a[3*n]; for (int i = 0; i < 3*n; i++) cin >> a[i];
    cout << solve(n, a) << endl;

    // int ans = solve(n, a), expect = cubic(n, a);
    // if (ans == expect) cerr << "OK\n";
    // else cerr << ans << " " << expect << endl;
}
