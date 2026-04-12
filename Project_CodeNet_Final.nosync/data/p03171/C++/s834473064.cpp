#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
#define ll long long 
using namespace std;
ll dp[3001][3001][2];
ll solve(vector<int> &v,int i,int j,int turn)
{
    if(i>j) return 0;
    if(dp[i][j][turn]!=-1)
    {
        return dp[i][j][turn];
    }
    if(turn==1)
    {
        return dp[i][j][turn]=max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
    }
    else
    {
        return dp[i][j][turn]=min(solve(v,i+1,j,1),solve(v,i,j-1,1));
    }
}
int main()
{
    int n;
    cin>>n;
    ll sum=0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    memset(dp,-1,sizeof(dp));
    ll sc_x=solve(v,1,n,1);
    ll sc_y=sum-sc_x;
    cout<<sc_x-sc_y<<'\n';
    return 0;
}