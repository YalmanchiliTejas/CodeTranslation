#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()

using LL = long long;
using LD = long double;
using pii = pair<int, int>;
using vii = vector<pii>;

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 3e3 + 5;

int n, a[N];
int dp[N][N];

int solve(int l, int r) {
    if (l == r) {
        return a[l]; // or a[r]
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int ans1 = a[l] - solve(l + 1, r);
    int ans2 = a[r] - solve(l, r - 1);

    return dp[l][r] = max(ans1, ans2);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, n - 1) << "\n";
    return 0;
}
