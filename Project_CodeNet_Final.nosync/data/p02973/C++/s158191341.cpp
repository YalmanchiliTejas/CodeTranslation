#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
Int INF = 1e18;
double EPS = 0.00000001;
//Int mod = 998244353;

Int dp[100005];

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = n - 1; i >= 0; i--) cin >> a[i];
    fill(dp, dp + n + 5, INF);
    for (Int i = 0; i < n; i++) {
        *upper_bound(dp, dp + n, a[i]) = a[i];
    }
    dump(lower_bound(dp, dp + n, INF) - dp);
    return 0;
}