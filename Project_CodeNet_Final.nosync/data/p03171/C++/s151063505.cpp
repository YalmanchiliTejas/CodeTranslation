#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long int dp[n][n],graph[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=a[i];
        graph[i][i]=0;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(i!=j)
               {
                   dp[j][i]=max(a[i]+graph[j][i-1],a[j]+graph[j+1][i]);
                   graph[j][i]=min(dp[j][i-1],dp[j+1][i]);
               }
        }
    }
    
    cout<<dp[0][n-1]-graph[0][n-1]<<"\n";
    
    return 0;
}