#include<bits/stdc++.h>
 
using namespace std;
 
long dp[10005][101][2];
 
int main(void) {
    long d;
    string s;
    cin >> s >> d;
    constexpr long MOD = 1e9 + 7;
 
    dp[0][0][1] = 1;
 
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<d; j++) {
            for(int k=0; k<=9; k++) {
                dp[i+1][(j+k)%d][0] += dp[i][j][0];
                dp[i+1][(j+k)%d][0] %= MOD;
            }
            for(int k=0; k<s[i]-'0'; k++) {
                dp[i+1][(j+k)%d][0] += dp[i][j][1];
                dp[i+1][(j+k)%d][0] %= MOD;
            }
            {
                int k = s[i]-'0';
                dp[i+1][(j+k)%d][1] += dp[i][j][1];
                dp[i+1][(j+k)%d][1] %= MOD;
            }
        }
    }
 
    cout << (dp[s.size()][0][1] + dp[s.size()][0][0]-1+MOD)%MOD << endl;
}
