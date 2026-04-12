#include<bits/stdc++.h>
using namespace std;

long long int dp[3001][3001][2];

long long int solve(long long int *a,long long int i,long long int j,long long int turn)
{
    if(i > j)
        return 0;

    if(dp[i][j][turn] != -1)
        return dp[i][j][turn];
    
    if(turn == 1)
    {
        return dp[i][j][turn] = max((a[i] + solve(a,i+1,j,0)),(a[j] + solve(a,i,j-1,0)));
    }
    else
    {
        return dp[i][j][turn] = min(solve(a,i+1,j,1),solve(a,i,j-1,1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    long long int *a = new long long int[n]{0};
    long long int sum = 0;
    for(long long int i=0;i<n;++i)
    {
        cin>>a[i];
        sum += a[i];
    }   
    long long int turn = 1;
    long long int X = solve(a,0,n-1,1);
    long long int Y = sum - X;
    cout<<(X - Y)<<endl;
    return 0;
}