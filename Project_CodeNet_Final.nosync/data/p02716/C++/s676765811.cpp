#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

const Int INF = 1e15;

int main(){
    int N; cin >> N;
    vector<Int> A(N+1);
    rep1(i,N) cin >> A[i];

    // dp[i][0]: A[1]~A[i]からi/2個とるときの最大値
    // dp[i][1]: A[1]~A[i]からi/2+1個とるときの最大値(i:奇数)
    vector<vector<Int>> dp(200010, vector<Int>(2, -INF));

    dp[1][0] = 0;
    dp[1][1] = A[1];
    dp[2][0] = max(A[1], A[2]);

    for(int i=3; i<=N; i++){
        Int last = A[i];
        if(i % 2 == 0){
            dp[i][0] = max(dp[i-1][1], last + dp[i-2][0]);
        } else {
            dp[i][0] = max(dp[i-1][0], last + dp[i-2][0]);
            dp[i][1] = last + dp[i-2][1];
        }
    }

    cout << dp[N][0] << endl;
}