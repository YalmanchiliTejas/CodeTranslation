#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)

#define sz(v) ((int) v.size())
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(all(v)), v.end())

using namespace std;

int n;
int a[3111];
long long dp[3111][3111];

long long solve(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(1, n) << "\n";
    return 0;
}
