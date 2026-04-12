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
const int MOD = 998244353;
const int N = 3000 + 3;

int n, s;
int a[N];
int dp[N][N];

int solve(int pos, int s) {
    if (s == 0)
        return n - (pos - 1) + 1;

    if (pos > n) 
        return 0;

    if (dp[pos][s] != -1) 
        return dp[pos][s];

    int ans = solve(pos + 1, s);
    if (a[pos] <= s)
        ans += solve(pos + 1, s - a[pos]);

    return dp[pos][s] = ans % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += solve(i, s);
        ans %= MOD;
    }

    cout << ans;
}