#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
long long int dp[3001][3001][2];
int l;
long long int solve(long long int *arr,int i,int j,int turn)
{
    if(i>j || i>l || j<0)
    {
        return 0;
    }
    if(dp[i][j][turn]!= -1)
    {
        return dp[i][j][turn];
    }
    if(turn==1)
    {
        dp[i][j][turn] = max(arr[i]+solve(arr,i+1,j,0),arr[j]+solve(arr,i,j-1,0));
    }
    else
    {
        dp[i][j][turn] = min(solve(arr,i+1,j,1),solve(arr,i,j-1,1));
    }
    return dp[i][j][turn];
}
int main()
{
    int n;
    cin>>n;
    memset (dp,-1,sizeof(dp));
    long long int arr[3001];
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    l=n;
    long long int X = solve(arr,1,n,0);
    long long int Y = sum-X;
    cout<<Y-X<<endl;
    return 0;
}
