#include<bits/stdc++.h>
using namespace std;

const int MAXN=3005;
long long dp[MAXN][MAXN];
int arr[MAXN];

long long solve(int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==j)
    return dp[i][j]=arr[i];
    dp[i][j]=max(arr[i]-solve(i+1,j),arr[j]-solve(i,j-1));
    return dp[i][j];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    long long y=solve(1,n);
    cout<<y<<"\n";
}
