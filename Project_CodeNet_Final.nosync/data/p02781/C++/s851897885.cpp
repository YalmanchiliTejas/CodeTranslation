#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

ll dp[101][5][2];
int main(void) {
    string s;
    ll m;
    cin >> s >> m;
    ll n = s.size();

    dp[0][0][0] = 1;
    REP(i, n) REP(j, m+1) REP(k, 2) {
        ll lim = k==1 ? 9 : s[i]-'0';
        REP(d, lim+1) {
            ll nj = min(4LL, j+(d!=0));
            dp[i+1][nj][k||d<lim] += dp[i][j][k];
        }
    }
    cout << dp[n][m][0]+dp[n][m][1] << endl;

    return 0;
}