#include <bits/stdc++.h>
using namespace std;

int N, A[3000];

int64_t dp[3001][3001][2];
const int64_t INF = 1e18;

int64_t rec(int i, int j, int k){
    if(i > j) return 0;
    if(dp[i][j][k] != INF) return dp[i][j][k];

    int64_t result;
    if(k == 0){
        result = max(rec(i+1, j, 1-k) + A[i], rec(i, j-1, 1-k) + A[j]);
    }else{
        result = min(rec(i+1, j, 1-k) - A[i], rec(i, j-1, 1-k) - A[j]);
    }
    dp[i][j][k] = result;
    return result;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<=3000; i++) for(int j=0; j<=3000; j++) for(int k=0; k<2; k++) dp[i][j][k] = INF;
    cout << rec(0, N-1, 0) << endl;
    return 0;
}