#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

typedef long long ll;
const ll MOD = 998244353;

using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll dp[3001][3001][3];

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;
    if(A[0] <= S){
        dp[0][A[0]][1] = 1;
        dp[0][A[0]][2] = 1;
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < S+1; j++){
            if(j+A[i] <= S){
                dp[i][j+A[i]][1] = (dp[i][j+A[i]][1] + dp[i-1][j][0] + dp[i-1][j][1])%MOD;
                dp[i][j+A[i]][2] = (dp[i][j+A[i]][2] + dp[i-1][j][0] + dp[i-1][j][1])%MOD;
            }
            dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][0])%MOD;
            dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][1] + dp[i-1][j][0])%MOD;
            dp[i][j][2] = (dp[i][j][2] + dp[i-1][j][2] + dp[i-1][j][1] + dp[i-1][j][0])%MOD;
        }
    }

    cout << dp[N-1][S][2]%MOD << endl;

    return 0;
}