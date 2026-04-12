#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> arr;
vector<vector<pair<ll,ll>>> dp;

pair<ll,ll> help(int i,int j)
{
    if(i>j) return {0,0};
    if(i==j) return {arr[i],0};

    if(dp[i][j].first != -1 ) return dp[i][j];

    auto p1= help(i+1,j),p2=help(i,j-1);

    if( p1.second+arr[i]>=p2.second+arr[j] ) {
        dp[i][j]= { p1.second+arr[i], p1.first };
    }else{
        dp[i][j]= {p2.second+arr[j], p2.first};
    }
    return dp[i][j];
}

int main()
{
    int n; cin>>n;
    arr.resize(n);
    dp.resize(n,vector<pair<ll,ll>>(n,{-1,-1}));
    for(int i=0;i<n;i++) cin>>arr[i];
    auto ans=help(0,n-1);
    cout<<ans.first-ans.second;
}