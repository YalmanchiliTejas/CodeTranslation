#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long mod=998244353;
const int N=3010;
int n,s;
int a[N];
long long dp[N][N][3];//dp[i][s][t],从前i个里选，总和为s，状态为t
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>a[i];
    dp[0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            (dp[i+1][j][0] += dp[i][j][0]) %= mod;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
            (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
            if(j + a[i] <= s){
                (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
                (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
            }
        }
    }
    

    cout<<dp[n][s][2]<<endl;
    return 0;
}

