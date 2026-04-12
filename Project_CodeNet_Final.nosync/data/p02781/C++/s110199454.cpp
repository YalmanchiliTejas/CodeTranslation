#include <bits/stdc++.h>
using namespace std;
char s[102];
long long dp[102][5][2];
int main(){
    int n, k;
    scanf("%s%d", s+1, &k);
    n = strlen(s+1);
    int cur = 0;
    for(int i=1;i<=n;i++){
        if(i == 1){
            for(int j=1;j<s[i]-'0';j++) dp[i][1][0]++;
            dp[i][0][0]++;
            dp[i][1][1]++;
        }
        else{
            for(int j=1;j<s[i]-'0';j++){
                for(int k=0;k<=3;k++){
                    dp[i][k+1][0] += dp[i-1][k][1];
                }
            }
            if(cur <= k){
                if(s[i] == '0'){
                    dp[i][cur][1] += dp[i-1][cur][1];
                }
                else{
                    dp[i][cur][0] += dp[i-1][cur][1];
                    dp[i][cur+1][1] += dp[i-1][cur][1];
                }
            }

            for(int j=1;j<=9;j++){
                for(int k=0;k<=3;k++){
                    dp[i][k+1][0] += dp[i-1][k][0];
                }
            }
            for(int k=0;k<=3;k++){
                dp[i][k][0] += dp[i-1][k][0];
            }
        }
        if(s[i] != '0') cur++;
    }
    printf("%lld\n", dp[n][k][0] + dp[n][k][1]);
}