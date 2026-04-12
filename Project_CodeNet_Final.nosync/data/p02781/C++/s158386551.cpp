#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll dp[101][2][4];

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i, n) {
        int x = s[i] - '0';
        rep(j, 2) {
            rep(l, 4) {
                rep(m, (j ? 10 : x + 1)) {
                    if (l + (m != 0) >= 4) continue;
                    dp[i + 1][j || m < x][l + (m != 0)] += dp[i][j][l];
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
