#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=998244353;
    int n,s;
    cin>>n>>s;
    int a[n];
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(s+1,vector<long long>(3)));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<=s;j++){
            dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0])%mod;
            dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][0]+dp[i][j][1])%mod;
            dp[i+1][j][2]=(dp[i+1][j][2]+dp[i][j][1]+dp[i][j][2])%mod;
            if(j+a[i]<=s){
                dp[i+1][j+a[i]][1]=(dp[i+1][j+a[i]][1]+dp[i][j][0]+dp[i][j][1])%mod;
                dp[i+1][j+a[i]][2]=(dp[i+1][j+a[i]][2]+dp[i][j][0]+dp[i][j][1])%mod;
            }
        }
    }
    cout<<dp[n][s][2]<<endl;
    return 0;
}