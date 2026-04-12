#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

Int dp[3001][3001];

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (Int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (Int i = 0; i + 1 < n; i++) {
        if (n % 2 == 0) {
            dp[i][i + 1] = max(a[i], a[i + 1]) - min(a[i], a[i + 1]);
        } else {
            dp[i][i + 1] = min(a[i], a[i + 1]) - max(a[i], a[i + 1]);
        }
    }
    for (Int len = 2; len < n; len++) {
        for (Int i = 0; i + len < n; i++) {         
            if ((n + len) % 2 == 1) {
                Int a = dp[i + 1][i + len] + dp[i][i];
                Int b = dp[i][i + len - 1] + dp[i + len][i + len];
                dp[i][i + len] = max(a, b);
            } else {
                Int a = dp[i + 1][i + len] - dp[i][i];
                Int b = dp[i][i + len - 1] - dp[i + len][i + len];
                dp[i][i + len] = min(a, b);
            }
            //cerr << dp[i][i + len] << " ";
        }
        //cerr << endl;
    }
    dump(dp[0][n - 1]);
    return 0;
}