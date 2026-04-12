#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_MAX / 2;

int main(){
    int N; cin >> N;
    int M = N/2;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(2, vector<ll>(3, -INF)));
    dp[0][1][0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        { 
            for (int k = 0; k < 3; k++){
                if(k+j<3) dp[i+1][1][k+j] = max(dp[i+1][1][k+j], dp[i][j][k]);
                if(j==1)  dp[i+1][0][k]   = max(dp[i+1][0][k],   dp[i][1][k] + A[i]);
            }
        }
    }
    if(N%2==0) cout << max(dp[N][1][0],dp[N][0][1]) << endl;
    else cout << max(dp[N][0][2], dp[N][1][1]) << endl;
}