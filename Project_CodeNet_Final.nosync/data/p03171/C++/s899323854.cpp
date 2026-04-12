#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    pair<long long int,long long int> dp[n][n];
    for(int i=0;i<n;i++)
    {
        pair<long long int,long long int>x = {a[i],0};
        dp[i][i] = x;
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    int k = 1;
    while(k<n)
    {
        int j = k;
        int i = 0;
        while(j<n && i<n)
        {
            pair<long long int,long long int>x;
            long long int a1,b1;
            a1 = max(a[i] + dp[i+1][j].second, a[j] + dp[i][j-1].second);
            b1 = ((a[i] + dp[i+1][j].second ) > (a[j] + dp[i][j-1].second)) ? dp[i+1][j].first : dp[i][j-1].first;
            x = {a1,b1};
            dp[i][j] = x;
            j++;
            i++;
        }
        k++;
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         cout<<"{"<<dp[i][j].first<<","<<dp[i][j].second<<"}  ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][n-1].first - dp[0][n-1].second;
}