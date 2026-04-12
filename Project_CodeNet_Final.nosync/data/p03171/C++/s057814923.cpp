#include<bits/stdc++.h>
using namespace std;

long long driver(vector<long long> &nums,long long i,long long j,vector<vector<long long>> &dp){
   if(i==j){
        dp[i][j] = nums[i];
        return dp[i][j];
    }
    if(i+1 == j){
        dp[i][j] = max(nums[i], nums[j]);
        return dp[i][j];
    }
    if(dp[i][j]==-1)
        dp[i][j] = max(
            (nums[i] + min(driver(nums, i+2, j, dp), driver(nums, i+1, j-1, dp))),
            (nums[j] + min(driver(nums, i+1, j-1, dp), driver(nums, i, j-2, dp)))
        );
    return dp[i][j];
}

int main(){
    long long n;
    cin>>n;
    vector<long long> nums(n,0);
    vector<vector<long long>> dp(n,vector<long long> (n,-1));
    
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    long long ans=2*driver(nums,0,n-1,dp)-sum;
    cout<<ans;
    return 0;
    
}