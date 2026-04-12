#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // init
    vector<vector<ll>> dp(N+1, vector<ll>(N+1));
    for (int i = 0; i < N; i++) dp[i][i] = 0;

    // DP
    for (int len = 1; len <= N; len++) {  // 間の配列の長さ
        for (int i = 0; i + len <= N; i++) {  // start
            int j = i + len;  // end
            // 先攻
            if ((N - len) % 2 == 0)
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            // 後攻
            else
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
        }
    }
    cout << dp[0][N] << '\n';
}
