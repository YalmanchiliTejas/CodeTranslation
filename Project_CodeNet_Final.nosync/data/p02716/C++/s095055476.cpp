/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/
 
#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x
 
using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ll MODBASE = 1000000007LL;
const int MAXN = 200010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;

int n, a[MAXN];
ll dp[MAXN][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    int sp = 1 + n % 2;
    FOR(i,0,n) FOR(j,0,sp) dp[i][j] = -1e18;
    dp[0][0] = 0;
    FOR(i,0,n)
        FOR(j,0,sp)
            if (dp[i][j] != -1000000000000000000LL) {
                if (i == 0) {
                    // not choose space
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1]);
                    int remainSp = sp - j;
                    // choose space
                    FOR(k,1,remainSp) dp[i+k+1][j+k] = max(dp[i+k+1][j+k], dp[i][j] + a[i+k+1]);
                }
                else {
                    // not choose space
                    dp[i+2][j] = max(dp[i+2][j], dp[i][j] + a[i+2]);
                    int remainSp = sp - j;
                    // choose space
                    FOR(k,1,remainSp) dp[i+k+2][j+k] = max(dp[i+k+2][j+k], dp[i][j] + a[i+k+2]);
                }
            }
    ll res = -1e18;
    if (sp == 2) {
        res = max(res, dp[n-2][0]);
        res = max(res, dp[n-1][1]);
        res = max(res, dp[n][2]);
    }
    else {
        res = max(res, dp[n][1]);
        res = max(res, dp[n-1][0]);
    }
    cout << res;
    return 0;
}
