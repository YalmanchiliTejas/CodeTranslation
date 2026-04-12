#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    long long dp[n][n];
    for(int i=0;i<n;i++)dp[i][i]=arr[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            dp[j][j+i] = max(arr[j+i]-dp[j][j+i-1],arr[j]-dp[j+1][j+i]);
        }
    }
    printf("%lld",dp[0][n-1]);
    return 0;
}