#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int N;
vector<int64_t> A(200000);
int64_t INF = -1e15;
void even_solve(){
    int M = N/2;

    //dp[i][j] = i番目の偶数A[2*i+1]で最後がA[2*i+1-j]の時の最大値
    vector<vector<int64_t>> dp(M,vector<int64_t>(2,INF));
    dp[0][0] = A[1];
    dp[0][1] = A[0];

    for(int i=0;i<M-1;i++){
        dp[i+1][1] = dp[i][1] + A[2*i+2];
        dp[i+1][0] = max(dp[i][1],dp[i][0]) + A[2*i+3];
    }
    cout << max(dp[M-1][0],dp[M-1][1]) << endl;
}

void odd_solve(){
    int M = N/2 +1;//奇数の個数

    //dp[i][j] = i番目の奇数a[2*i]で最後がA[2*i-j]のときの最大値
    vector<vector<int64_t>> dp(M,vector<int64_t>(3,INF));
    //初期条件、N>=2よりM>=2
    dp[1][0] = A.at(2);
    dp[1][1] = A.at(1);
    dp[1][2] = A.at(0);

    for(int i=1; i<M-1;i++){
        int64_t mx2 = dp[i][2];
        int64_t mx1 = max(mx2,dp[i][1]);
        int64_t mx0 = max(mx1,dp[i][0]);

        //dp漸化式
        dp[i+1][2] = mx2 + A[2*i];
        dp[i+1][1] = mx1 + A[2*i+1];
        dp[i+1][0] = mx0 + A[2*i+2];

    }
    cout << max(dp[M-1][0],max(dp[M-1][1],dp[M-1][2])) << endl;
}
    

void solve(){
    if(N%2) odd_solve();
    else even_solve();
}

int main(){
    cin >> N;
    rep(i,N){cin >> A.at(i);}
    solve();
}   