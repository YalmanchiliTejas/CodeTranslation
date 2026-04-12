#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) FORR(i, (n) - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define REPS(c, s) for (char c : s)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REV(c) reverse(ALL(c))
#define sz(v) (int)v.size()
#define endl '\n'
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline void prn(vector<T>& v) {int n = sz(v); REP(i, n) cout << v[i] << ' ';}
template<class T> inline void printv(vector<T>& v) {int n = sz(v); REP(i, n) cout << v[i] << (i == n - 1 ? endl : ' ');}
template<class T> inline void printvv(vector<vector<T>>& v) {for (auto u : v) printv(u);}
template<class T> inline void printlnv(vector<T>& v) {int n = sz(v); REP(i, n) cout << v[i] << endl;}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
 
void solve();
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);
    solve();
    return 0;
}

void solve() {
    string s;
    int d;
    cin >> s >> d;
    int n = sz(s);

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(d, vector<ll>(2)));
    dp[0][0][0] = 1;

    REP(i, n) REP(j, d) REP(k, 10) {
        int nd = s[i] - '0';
        int r = (j + k) % d;
        dp[i + 1][r][1] += dp[i][j][1];
        dp[i + 1][r][1] %= MOD;
        // border
        if (k == nd) {
            dp[i + 1][r][0] += dp[i][j][0];
            dp[i + 1][r][0] %= MOD;
        }
        // under
        if (k < nd) {
            dp[i + 1][r][1] += dp[i][j][0];
            dp[i + 1][r][1] %= MOD;
        }
    }
    // REP(i, n + 1) {
    //     cout << i << ": " << endl;
    //     printvv(dp[i]);
    // }

    // 0 の分がカウントされているので1引く
    ll ans = dp[n][0][0] + dp[n][0][1] - 1;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}
