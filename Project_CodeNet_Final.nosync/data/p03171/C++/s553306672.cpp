#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) { cin >> a[i]; }

    vector<vll> dp(n + 1, vll(n + 1, 0));

    rep(k, 1, n + 1) {
        rep(i, 0, n - k + 1) {
            bool first = (n + k) % 2 == 0;
            if (k == 1) {
                dp[i][i + k] = a[i] * (first ? 1 : -1);
            }
            else if (first) {
                dp[i][i + k] = max(dp[i + 1][i + k] + a[i], dp[i][i + k - 1] + a[i + k - 1]);
            } else {
                dp[i][i + k] = min(dp[i + 1][i + k] - a[i], dp[i][i + k - 1] - a[i + k - 1]);
            }
        }
    }

    cout << dp[0][n] << endl;
    return 0;
}