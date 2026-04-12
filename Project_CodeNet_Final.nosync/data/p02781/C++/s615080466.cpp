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

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll d = s.size();
    if (k > d) {
        cout << 0 << endl;
        return 0;
    }
    // dp[i][j][hoge] : 下から i 桁まで決定して non-zero が j コで s 以下の個数
    // hoge == 0 : i 桁目まで s に全一致, 1 : どこかで不一致
    vector<vvll> dp(d + 1, vvll(k + 1, vll(2)));
    // 0
    dp[0][0][0] = 1;
    REP(i, d) {
        REP(j, k + 1) {
            REP(x, 2) {
                REP(nxt, 10) {
                    ll nj = j, nx = x;
                    if (nxt) nj++;
                    if (nj > k) continue;
                    if (nxt > s[i] - '0' && x == 0) continue;
                    if (nxt < s[i] - '0') nx = 1;
                    dp[i + 1][nj][nx] += dp[i][j][x];
                }
            }
        }
    }
    ll res = dp[d][k][0] + dp[d][k][1];
    cout << res << endl;
    return 0;
}