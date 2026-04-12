#include<bits/stdc++.h>
using namespace std;
long long dp[3001][3001][2];
long long solve(vector<int> &v,int i, int j, bool turn)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j][turn]!=-1)
    {
        return dp[i][j][turn];
    }
    if(turn==1)
    {
        return dp[i][j][turn] =  max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
    }
    else
    {
        return dp[i][j][turn] = min(solve(v,i+1,j,1),solve(v,i,j-1,1));
    }
}
int main() 
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    memset(dp,-1,sizeof dp);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    long long  x = solve(v,1,n,1);
    long long y = (sum - x);
    cout<<x-y<<endl;
    return 0;
}
