#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    long long int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(i=n-1;i>=0;i--)
        for(j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j] = a[i];
            else
            {
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
            }
        }
    cout<<dp[0][n-1];
}