#include<bits/stdc++.h>
using namespace std;

long long int dp[200005][3];
int main(){
int N;
cin >> N;
long long int a[N];
int i,j;
for(i=0;i<N;i++)cin >> a[i];
if(N%2==0){
    dp[0][0]=a[0];
    dp[1][1]=a[1];
    for(i=2;i<N;i+=2){
        for(j=0;j<2;j++){
            dp[i][j]=dp[i-2][j]+a[i];
            dp[i+1][j]=dp[i-1][j]+a[i+1];
        }
        dp[i+1][1]=max(dp[i-2][0]+a[i+1],dp[i+1][1]);
    }
    long long int ans=max(dp[N-2][0],dp[N-1][1]);
    cout << ans << endl;
}
else{
    dp[0][0]=a[0];
    dp[1][1]=a[1];
    for(i=2;i<N;i+=2){
        for(j=0;j<3;j++){
            dp[i][j]=dp[i-2][j]+a[i];
            dp[i+1][j]=dp[i-1][j]+a[i+1];
        }
        dp[i+1][1]=max(dp[i-2][0]+a[i+1],dp[i+1][1]);
        if(i>=4){
            dp[i][2]=max(max(dp[i-4][0]+a[i],dp[i-3][1]+a[i]),dp[i][2]);
    }}
    long long int ans=max(max(dp[N-3][0],dp[N-2][1]),dp[N-1][2]);
    cout << ans << endl;    
}
}