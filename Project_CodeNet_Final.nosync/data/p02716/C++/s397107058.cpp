#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll arr[200001];
ll dp[200001][3];
ll knap1(int i ,int c)
{
    if(i>=n)
        return 0;
    if(dp[i][c]!=-1)
        return dp[i][c];
    if(c==0)
        return dp[i][c]=max(arr[i]+knap1(i+2,0),max(arr[i+1]+knap1(i+3,1),arr[i+2]+knap1(i+4,2)));
    if(c==1)
        return dp[i][c]=max(arr[i]+knap1(i+2,1),arr[i+1]+knap1(i+3,2));
    else
        return dp[i][c]=arr[i]+knap1(i+2,2);
}
ll knap(int i ,int c)
{
    if(i>=n)
        return 0;
    if(dp[i][c]!=-1)
        return dp[i][c];
    if(c==0)
        return dp[i][c]=max(arr[i]+knap(i+2,0),arr[i+1]+knap(i+3,1));
    else
        return dp[i][c]=arr[i]+knap(i+2,1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    //ll sum=0;
    if(n%2==0)
        cout<<knap(0,0);
    else
        cout<<knap1(0,0);
    return 0;
}
