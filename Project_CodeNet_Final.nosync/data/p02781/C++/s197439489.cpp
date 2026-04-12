#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;
int k, l;
int n[101];
int dp[2][101][4];

int main(){
    cin >> s >> k;
    l = s.size();
    for (int i = 0; i < l; ++i) n[i] = s[i] - '0';
    memset(dp, sizeof(dp), 0);
    dp[0][0][0] = 1;   // For sure
    dp[0][0][1] = n[0]-1;
    dp[1][0][1] = 1;   // Not for sure
    for (int i = 1; i < l; ++i){
        dp[0][i][0] = dp[0][i-1][0];
        if (n[i] == 0) dp[1][i][0] = dp[1][i-1][0];
        else dp[0][i][0] += dp[1][i-1][0];
        for (int j = 1; j <= k; ++j){
            dp[0][i][j] = dp[0][i-1][j] + dp[0][i-1][j-1]*9;
            if (n[i] == 0){
                dp[1][i][j] = dp[1][i-1][j];
            }
            else{
                dp[0][i][j] += dp[1][i-1][j] + dp[1][i-1][j-1]*(n[i] - 1);
                dp[1][i][j] = dp[1][i-1][j-1];
            }
        }
    }
    cout << (dp[0][l-1][k] + dp[1][l-1][k]);
}