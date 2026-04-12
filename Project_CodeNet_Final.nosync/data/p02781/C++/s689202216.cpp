#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main(){
    string s;
    cin >> s;
    int K;
    cin >> K;
    int L = (int)s.size();
    vector<vector<vector<ll>>> dp(L+1, vector<vector<ll>>(K+1, vector<ll>(2, 0)));
    dp[1][0][0] = 0;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][1] = s[0] - '1';
    for(int i = 2; i <= L; i++){
        for(int j = 0; j <= K; j++){
            if(s[i-1] - '0' == 0){
                dp[i][j][0] = dp[i-1][j][0];
            } else dp[i][j][1] = dp[i-1][j][0];
            dp[i][j][1] += dp[i-1][j][1];
            if(j != 0){
                dp[i][j][1] += dp[i-1][j-1][1] * 9;
                if(s[i-1] - '0' != 0){
                    dp[i][j][1] += dp[i-1][j-1][0] * (s[i-1] - '1');
                    dp[i][j][0] += dp[i-1][j-1][0];
                }
            }
        }
    }
    cout << dp[L][K][0] + dp[L][K][1] << endl;
    return 0;
}
