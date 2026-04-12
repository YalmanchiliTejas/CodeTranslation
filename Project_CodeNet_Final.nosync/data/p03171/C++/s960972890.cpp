#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
const ll INF = 1LL<<60;
const int INT_INF = 1e9;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int N;
ll a[3010];
ll dp[3010][3010];

int main() {
    cin >> N;
    rep(i, N) cin >> a[i];

    // 初期化
    rep(i, N) dp[i][i] = 0;

    // DP loop
    for (int len = 1; len <= N; len++) {
        for (int i = 0; i + len <= N; i++) {
            int j = i + len;
            if ((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            } else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][N] << endl;
}
