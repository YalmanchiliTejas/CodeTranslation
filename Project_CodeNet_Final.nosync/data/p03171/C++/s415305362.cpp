#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[3001][3001];

ll solve(int i,int j,vector<ll> &v,int turn)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(turn)
    {
        return dp[i][j]=max(v.at(i)+solve(i+1,j,v,0),v.at(j)+solve(i,j-1,v,0));
    }
    else
    {
        return dp[i][j]=min(solve(i+1,j,v,1),solve(i,j-1,v,1));
    }
}

int main()
{
    int n;
    cin>>n;
    vector<ll> v(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v.at(i);
        sum+=v.at(i);
    }
    memset(dp,-1,sizeof(dp));
    ll score_x=solve(1,n,v,1);
    // this solve function will return the optimal value of x when vector from 1 to n is traversed and
    // the game is started by the first player......
    ll score_y=sum-score_x;
    cout<<(score_x-score_y);

    return 0;
}