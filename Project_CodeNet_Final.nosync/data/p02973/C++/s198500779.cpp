#include<bits/stdc++.h>
using namespace std;

const long INF = 1e9+2;

int main(){
    long N;
    long A[100010];
    long dp[100010];

    cin >> N;
    fill(dp, dp+N, INF);
    for(long i=0;i<N;i++) cin >> A[i];
    reverse(A, A+N);
    for(int i=0;i<N;i++){
        *upper_bound(dp, dp+N, A[i]) = A[i];
    }
    cout << lower_bound(dp, dp+N, INF) - dp;
    return 0;
}