#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 305;
const int NIL = -1;
const ll LINF = 1LL << 50;
/* global variables */
/* funciton */
/* main */
int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<ll>> dp(N+1, vector<ll>(N+1));

    for (int i = 0; i <= N; i++) dp[i][i] = 0;
    for (int len = 1; len <= N; len++) {
        for (int x = 0; x <= N - len; x++) {
            int y = x + len;
            if ((N-len) % 2 == 0) {
                dp[x][y] = max(dp[x+1][y] + a[x], dp[x][y-1] + a[y-1]);
            }
            else {
                dp[x][y] = min(dp[x+1][y] - a[x], dp[x][y-1] - a[y-1]);
            }
        }
    }
    cout << dp[0][N] << '\n';
}