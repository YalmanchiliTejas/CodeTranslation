#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int dp[n][n];
    for(int i=0;i<n;i++) dp[i][i]=a[i];
    for(int i=1;i<n;i++) for(int j=0;j+i<n;j++) dp[j][j+i]=max(a[j]-dp[j+1][j+i],a[j+i]-dp[j][j+i-1]);
    cout<<dp[0][n-1];
}