#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint N;
    cin >> N;
    vector<lint> A(N);
    REP(i, N) cin >> A[i];
    vector<vector<vector<lint>>> dp(N, vector<vector<lint>>(4, vector<lint>(4, -1e15)));
    dp[0][0][0] = A[0];
    dp[0][1][1] = 0;
    FOR(i, 1, N) {
        REP(j, 4) {
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1]+A[i]);
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][2]+A[i]);
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][3]+A[i]);
        }
        REP(j, 4) {
            if(i == N-1) {
                if(j != 3) dp[i][j+1][1] = dp[i-1][j][0];
            } else {
                dp[i][j][1] = dp[i-1][j][0];
            }
            
        }
        REP(j, 3) {
            if(i == N-1) {
                if(j != 2) {
                    dp[i][j+2][2] = dp[i-1][j][1];
                    dp[i][j+2][3] = dp[i-1][j][2];  
                }
            } else {
                dp[i][j+1][2] = dp[i-1][j][1];
                dp[i][j+1][3] = dp[i-1][j][2];  
            }
             
        }
    }
    lint ans = -1e15;
    if(N%2 == 0) {
        REP(k, 4) {
            ans = max(ans, dp[N-1][1][k]);
        }
        
    } else {
        REP(k, 4) {
            ans = max(ans, dp[N-1][2][k]);
        }
        
    }
    cout << ans << endl;
}