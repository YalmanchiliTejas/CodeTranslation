// https://kmjp.hatenablog.jp/entry/2020/04/12/1030
#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

ll dp[202020][2][3];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    
    // dp[i][x][y] := i: i要素目までの選び方を考えた時、x: i要素目を選ばなかったかどうか、y: これまで連続で選ばなかった箇所の数
    rep(i, n + 1) {
        rep(x, 2) {
            rep(y, 3) {
                dp[i][x][y] = -1 * LINF;
            }
        }
    }

    dp[0][1][0] = 0;

    rep(i, n) {
        ll x;
        cin >> x;
        rep(j, 2) {
            rep(k, 3) {
                // not take
                if (k + j < 3) dp[i + 1][1][k + j] = max(dp[i + 1][1][k + j], dp[i][j][k]);
                // take
                if (j == 1) dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][j][k] + x);
            }
        }
    }

    if (n % 2 == 0) cout << max(dp[n][1][0], dp[n][0][1]) << endl;
    else cout << max(dp[n][0][2], dp[n][1][1]) << endl;


    return 0;
}