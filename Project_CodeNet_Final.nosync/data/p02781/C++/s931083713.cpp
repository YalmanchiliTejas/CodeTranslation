#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
// const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
////////////////////////////////////////////////////////////////////////////////////////////////////////

ll dp[200][5][2];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    int N = S.size();
    int K; cin >> K;

    dp[0][0][0] = 1;
    rep(i,N) {
        int n = S[i] - '0';
        rep(j,5) {
            if (n) {
                if (j > 0) dp[i+1][j][0] += dp[i][j-1][0];
                dp[i+1][j][1] += dp[i][j][1] + dp[i][j][0];
                if (j > 0) dp[i+1][j][1] += dp[i][j-1][1]*9 + dp[i][j-1][0]*(n-1);
            } else {
                dp[i+1][j][0] += dp[i][j][0];
                dp[i+1][j][1] += dp[i][j][1];
                if (j > 0) dp[i+1][j][1] += dp[i][j-1][1]*9;
            }
        }
    }

    cout << dp[N][K][0] + dp[N][K][1] << endl;
}