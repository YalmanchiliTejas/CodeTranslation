#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int P = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, S;
    cin >> N >> S;
    vector<int> nums(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> nums[i];
    }
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(S+1, vector<int>(3, 0)));
    dp[0][0][1] = 1;
    for(int i = 1 ; i < N+1 ; ++i){
        dp[i][0][0] = 1;
        dp[i][0][1] = 1 + dp[i-1][0][1];
        dp[1][0][1] = 1;
        for(int j = 1 ; j < S+1; ++j){
            dp[i][j][1] = dp[i-1][j][1];
            if(j-nums[i-1] >= 0){
                dp[i][j][1] += dp[i-1][j-nums[i-1]][1];
                dp[i][j][1] += dp[i-1][j-nums[i-1]][0];
                dp[i][j][1] %= P;
            }
            dp[i][j][2] = dp[i-1][j][2] + dp[i][j][1];
            dp[i][j][2] %= P;
        }
    }
    
    int ret = 0;
    ret = dp[N][S][2];
/*
    for(int i = 0 ; i < N+1; ++i){
        cout << dp[i][S][2] << endl; 
        ret += dp[i][S][2];
        ret %= P;
    }
*/
    cout << ret << endl;

    return 0;
}