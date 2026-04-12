
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define p 1000000007
#define pb push_back
ll dp[3001][3001];

ll points(ll i,ll j,vector<ll> &v,int turn)
{
    if(i>j)
    {
        return 0;
    }
    else if(i==j)
    {
        return dp[i][j]=(turn==1?v.at(i):0);
    }
    else
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(turn==1)
        {
            
            return dp[i][j]=max(v.at(i)+points(i+1,j,v,0),v.at(j)+points(i,j-1,v,0));
        }
        else if(turn==0)
        {
            
            return dp[i][j]=min(points(i+1,j,v,1),points(i,j-1,v,1));
        }
    }
}

ll solve(ll n,vector<ll> &v)
{
    memset(dp,-1,sizeof(dp));
    return points(1,n,v,1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    ll sum=0;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v.at(i);
        sum+=v.at(i);
    }
    //cout<<sum<<"\n";
    //cout<<solve(n,v)<<"\n";
    cout<<(2*solve(n,v)-sum)<<"\n";
    return 0;
}