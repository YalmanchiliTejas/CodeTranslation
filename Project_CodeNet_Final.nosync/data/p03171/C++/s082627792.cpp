#include<iostream>

using namespace::std;

long long int t,ar[3005],dp[3005][3005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int i=0;i<n;i++)
        dp[i][0]=ar[i];
    for(int j=1;j<n;j++)
        for(int i=0;i<n-j;i++)
            dp[i][j]=max(ar[i+j]-dp[i][j-1],ar[i]-dp[i+1][j-1]);
            
    cout<<dp[0][n-1]<<'\n';
}