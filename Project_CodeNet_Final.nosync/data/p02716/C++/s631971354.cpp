#include <iostream>
using namespace std;
typedef long long ll;
ll dp[200001][3][2],n,a;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        dp[i+1][0][1]=dp[i][0][0]+a;
        dp[i+1][1][1]=dp[i][1][0]+a;
        dp[i+1][2][1]=dp[i][2][0]+a;
        dp[i+1][0][0]=dp[i][0][1];
        dp[i+1][1][0]=max(dp[i][0][0],dp[i][1][1]);
        dp[i+1][2][0]=max(dp[i][1][0],dp[i][2][1]);
    }
    if(n%2==0)cout<<max(dp[n][0][0],dp[n][1][1]);
    if(n%2==1)cout<<max(dp[n][1][0],dp[n][2][1]);
}
