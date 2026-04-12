/* https://www.hamayanhamayan.com/entry/2019/01/09/004223 */
/* メモ化再帰は区間DP？ */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
#define MOD 1e9+7

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain; 

int N;
/* dp[i][j]: 区間i, jからのx-y */ 
ll memo [3002][3002];
bool flag[3002][3002];

vector<ll> a(3002);

ll dp(int l, int r) 
{
    if (l > r) return 0;
    if (flag[l][r]) return memo[l][r];
    flag[l][r] = true;

    /* 先手か後手かの判断 */
    int diff = N - (r - l + 1);

    ll res;
    if(diff % 2 == 0) {
        /* 先手 */
        res = -INF_LL;
        res = max(res, dp(l+1, r) + a[l]);
        res = max(res, dp(l, r-1) + a[r]);
    } else {
        /* 後手 */
        res = INF_LL;
        res = min(res, dp(l+1, r) - a[l]);
        res = min(res, dp(l, r-1) - a[r]);
    }

    return memo[l][r] = res;
}

int main()
{
    cin >> N;
    REP(i, N) cin >> a[i];

    cout << dp(0, N-1) << endl;

    return 0;
}
