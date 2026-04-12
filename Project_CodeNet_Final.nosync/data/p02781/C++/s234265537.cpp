#include <bits/stdc++.h>


#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const int MOD = 1e9 + 7;
 
int K;
string N;
ll dp[10005][2][5];
 
int main() {
    cin >> N >> K;
    int n = N.size();
 
    dp[0][0][0] = 1;
 
    REP(i, n) {
        REP(k, K + 1) {
            // i桁目まででNより小さいならi+1桁目は何でも良い
            dp[i + 1][1][k + 1] += dp[i][1][k] * 9;  // i+1桁目が0以外
            dp[i + 1][1][k] += dp[i][1][k];          // i+1桁目が0
 
            int ni = (N[i] - '0');
 
            // i桁目までNと同じで、i+1桁目はNより小さい数の時
            if (ni > 0) {
                dp[i + 1][1][k + 1] += dp[i][0][k] * (ni - 1);  // i+1桁目が0以外
                dp[i + 1][1][k] += dp[i][0][k];                 // i+1桁目が0
            }
 
            //  i桁目までNと同じで、i+1桁目もNと同じ数の時
            if (ni > 0) {
                dp[i + 1][0][k + 1] = dp[i][0][k];  // i+1桁目が0以外
            } else {
                dp[i + 1][0][k] = dp[i][0][k];  // i+1桁目が0
            }
        }
    }
 
    cout << dp[n][0][K] + dp[n][1][K] << endl;
 
    return 0;
}
