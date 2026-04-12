#include<bits/stdc++.h>
using namespace std;
long long inf=1000000000000000000;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    long long dp[n+1][3][2];
    for(int i=0;i<=n;i++)for(int j=0;j<3;j++)for(int k=0;k<2;k++)dp[i][j][k]=-inf;
    dp[0][0][0]=0;
    //i番目まで見て、選べるはずの要素をj個捨て、次に数を{k=0:選べる、k=1:選べない}
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            //選べる
            if(j<2)dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][0]);//捨てる
            dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+a[i]);//選ぶ
            //選べない
            dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][1]);
        }
    }
    if(n%2)cout<<max({dp[n][1][0],dp[n][1][1],dp[n][2][0],dp[n][2][1]})<<endl;
    else cout<<max({dp[n][0][0],dp[n][0][1],dp[n][1][0],dp[n][1][1]})<<endl;
    return 0;
}