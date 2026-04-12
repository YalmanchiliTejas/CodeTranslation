#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long const mod = 1e9+7;
    
    long dp[n][3];
    for(int i=0;i<n;i++){
        dp[i][0] = -1<<30;
        dp[i][1] = -1<<30;
        dp[i][2] = -1<<30;
    }
    if(n==2)cout<<max(a[0],a[1])<<endl;
    else if(n==3)cout<<max(a[0],max(a[1],a[2]))<<endl;
    else{
        dp[0][0] = a[0];
        
        dp[1][1] = a[1];
        
        dp[2][0] = a[0]+a[2];
        dp[2][2] = a[2];

        dp[3][1] = max(a[1],a[0])+a[3];

        for(int i=4;i<n;i++){
            dp[i][0] = dp[i-2][0]+a[i];
            dp[i][1] = max(dp[i-2][1],dp[i-3][0]) + a[i];
            dp[i][2] = max(max(dp[i-2][2],dp[i-3][1]),dp[i-4][0]) + a[i];
        }
        if(n%2==1)cout << max(max(dp[n-3][0],dp[n-2][1]),dp[n-1][2])<<endl;
        else cout<< max(dp[n-2][0],dp[n-1][1]) << endl;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=2;j++){
        //         printf("%ld %ld %ld\n",i,j,dp[i][j]);
        //     }
        // }
    }
}
