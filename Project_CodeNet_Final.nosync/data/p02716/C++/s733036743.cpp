#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

const ll mod = 1e9 + 7;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vll a(n);
    REP(i, n) cin >> a[i];

    if (n % 2 == 0) {
        vvll dp(n, vll(2, -1e15));
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        REP(i, n) {
            if (i < 2) continue;
            dp[i][0] = max(dp[i][0], dp[i - 2][0] + a[i]);
            dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i]);
            if (i - 3 >= 0) {
                dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i]);
            }
        }
        ll res = max(dp[n - 2][0], dp[n - 1][1]);
        cout << res << endl;
        return 0;
    }

    // dp[i][j] : i 文字目まで見て j 回パスしたときの和の最大値
    vvll dp(n, vll(3, -1e15));
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    REP(i, n) {
        if (i < 2) continue;
        REP(j, 3) {
            dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i]);
        }
        if (i - 3 >= 0) {
            dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i]);
            dp[i][2] = max(dp[i][2], dp[i - 3][1] + a[i]);
        }
        if (i - 4 >= 0) {
            dp[i][2] = max(dp[i][2], dp[i - 4][0] + a[i]);
        }
    }
    ll res = max(dp[n - 3][0], max(dp[n - 2][1], dp[n - 1][2]));
    cout << res << endl;
    return 0;
}