#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long * a= new long long[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long dp[n][n];
    // memset(dp,0,sizeof(dp));
    for(int l=n-1;l>=0;l--)
    {
        for(int r=l;r<n;r++)
        {
            if(l==r)dp[l][r]=a[l];
            else
        dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     cout<<dp[i][j]<<"\t";
    //     cout<<endl;
    // }
    cout<<dp[0][n-1];
}