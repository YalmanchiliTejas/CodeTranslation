#include<bits/stdc++.h>
using namespace std;

#define int long long 

int sol(int start,int end,vector<int> &v,vector<vector<int>> &dp)
{

    if(start>end) return numeric_limits<int>::min();

    if(start+1==end) return max(v[start],v[end]);
    if(start==end) return v[start];

    int &r=dp[start][end];
    if(r!=-1) return r;

    int res=0;
    res=v[start]+min(sol(start+2,end,v,dp),sol(start+1,end-1,v,dp));
    res=max(res,v[end]+min(sol(start+1,end-1,v,dp),sol(start,end-2,v,dp)));
    return r=res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int sum=0;
    for(auto u:v) sum+=u;

    vector<vector<int>> dp(n,vector<int> (n,-1));
    
    int ans=sol(0,n-1,v,dp)-(sum-sol(0,n-1,v,dp));
    cout<<ans<<"\n";
    return 0;
}