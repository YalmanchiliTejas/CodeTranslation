#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()

const int MAX = 111;

string N;
int num[MAX];
int K;

ll dp[MAX][4][2]; // dp[n][k][l] : 上からn桁決めて0以外の桁がk個ある、l=1のときN以下であることが確定している

ll solve() {
    REP (i, N.size()) num[i] = N[i] - '0';

    dp[0][0][1] = 1; // 先頭が0
    dp[0][1][1] = num[0] - 1; // 先頭がN[0]以下
    dp[0][1][0] = 1; // 先頭がN[0]なら不定

    // REP (i, N.size()) dp[i][0][1] = 1; // 先頭が0なら確定

    FOR (i, 1, N.size()) {
        dp[i][0][1] = 1;
        FOR (k, 1, 4) {
            dp[i][k][1] += dp[i-1][k][1]; // 下回ることが確定してて0を追加
            dp[i][k][1] += dp[i-1][k-1][1] * 9; // 下回ることが確定してて1~9を追加
            
            if (num[i] == 0) {
                dp[i][k][0] += dp[i-1][k][0]; // kが増えずに確定もしない
            } else {
                dp[i][k][1] += dp[i-1][k][0]; // 下回ることが確定してなくて0を追加して下回ることが確定
                dp[i][k][1] += dp[i-1][k-1][0] * (num[i]-1); // 下回ることが確定してなくて1以上を追加して下回ることが確定
                dp[i][k][0] += dp[i-1][k-1][0]; // kが増えるが確定しない
            }
        }
    }

    /*
    REP (x, 2) {
        if (x == 1) cout << "decided: " << endl;
        else cout << "undecided: " << endl;
        REP (k, 4) {
            cout << "k = " << k << " : ";
            REP (i, N.size()) {
                cout << dp[i][k][x] << " ";
            }
            cout << endl;
        }
    }
    */

    return dp[N.size()-1][K][0] + dp[N.size()-1][K][1];
}

int main() {
    cin >> N >> K;
    cout << solve() << endl;
}