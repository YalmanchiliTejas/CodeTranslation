#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

 ll func(vector<ll>&nums,ll start,ll end,vector<vector<ll> >&dp){
        
        if(start==end)return dp[start][end]=nums[start];
        if(start+1==end)return dp[start][end]= max(nums[start],nums[end]);
        
        if(dp[start][end]!=-1)return dp[start][end];
        
    return dp[start][end]=
        max(nums[start]+
            min(func(nums,start+2,end,dp),func(nums,start+1,end-1,dp)),
        nums[end]+
            min(func(nums,start+1,end-1,dp),func(nums,start,end-2,dp)));
        
    }
    

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    vector<ll>nums(n);
    for(ll &x:nums)cin>>x;
        
    ll sum=0;
                
    for(ll x:nums)sum+=x;
                
    vector<vector<ll> >dp(n+1,vector<ll>(n+1,-1));
                
    ll first=func(nums,0,n-1,dp);

    cout<<2*first - sum;

    return 0;

}