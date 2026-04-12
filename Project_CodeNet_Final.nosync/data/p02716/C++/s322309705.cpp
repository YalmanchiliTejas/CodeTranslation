#include <iostream>
#include <algorithm>

#define INF 1000000000000000

using namespace std;

int main(){
    int N;
    cin >> N;
    long A[N];
    for(int i=0; i<N; i++) cin >> A[i];
    long dp[N][3][2];

    // initialize
    for(int j=0; j<3; j++){
        for(int s=0; s<2; s++) dp[0][j][s] = -INF;
    }
    dp[0][0][0] = 0;
    dp[0][1][1] = A[0];

    long base[N];
    base[0] = 0;

    for(int i=1; i<N; i++){

        base[i] = N / 2 - (N - i) / 2;
        for(int j=base[i]; j<=(i+2)/2; j++){
            if(j  <= (i+1)/2) dp[i][j - base[i]][0] = max(dp[i-1][j - base[i-1]][0], dp[i-1][j - base[i-1]][1]);
            else dp[i][j - base[i]][0] = -INF;
            if(j-1 <= (i+1)/2) dp[i][j - base[i]][1] = dp[i-1][j-1-base[i-1]][0] + A[i];
            else dp[i][j - base[i]][1] = -INF;
        }
    }
    cout << max(dp[N-1][N/2 - base[N-1]][0], dp[N-1][N/2 - base[N-1]][1]) << endl;
    return 0;
}