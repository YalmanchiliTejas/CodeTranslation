#include <bits/stdc++.h>
using namespace std;

void chmax(int64_t& a, int64_t b){
    a = max(a, b);
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    static int64_t dp[200001][6];
    for(int i=0; i<=N; i++) for(int j=0; j<3; j++) dp[i][j] = -1e18;
    for(int i=0; i<=2; i++) if(i<N) dp[i][i] = A[i];
    for(int i=0; i<N; i++) for(int j=0; j<3; j++){
        for(int d=0; j+d<3; d++){
            int bef = i-2-d;
            if(bef < 0) continue;
            chmax(dp[i][j+d], dp[bef][j] + A[i]);
        }
    }
    int64_t ans = -1e18;
    int D = 1 + N%2;
    for(int d=0; d<=D; d++){
        int i = N-1-d;
        if(i >= 0) chmax(ans, dp[i][D-d]);
    }
    cout << ans << endl;
    return 0;
}
