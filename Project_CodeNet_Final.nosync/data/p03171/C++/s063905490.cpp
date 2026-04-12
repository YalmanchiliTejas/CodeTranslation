#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll optimal_strategy(ll start , ll end , vector<vector<ll>>& dp , vector<ll>& arr)
{   //  cout<<start<<" "<<end<<endl;
    if(start < 0  || end >= arr.size()) return 0;
   // cout<<start<<" "<<end<<" "<<arr[start]<<" "<<arr[end]<<" "<<dp[start][end]<<endl;
    if(start == end)
    {
        dp[start][end] = arr[start];
        return dp[start][end];
    }
    if(end == (start + 1))
    {
        dp[start][end]  = max(arr[start],arr[end]);
        return dp[start][end];
    }
   //  cout<<start<<" "<<end<<" "<<arr[start]<<" "<<arr[end]<<" "<<dp[start][end]<<endl;
    if(dp[start][end] != INT_MIN) return dp[start][end];
    dp[start][end] = max ( arr[start] + min( optimal_strategy(start+2,end,dp,arr) , optimal_strategy(start+1,end-1,dp,arr) ) , arr[end] + min( optimal_strategy(start+1,end-1,dp,arr) , optimal_strategy(start,end-2,dp,arr) ) ); 
    return dp[start][end];
}
int main()
{  
    
    int n;
    cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INT_MIN));
    vector<ll> arr(n);
    ll total_sum = 0;
    for(ll i = 0 ; i< n;i++)
    {
        cin>>arr[i];
        total_sum += arr[i];
    }
    ll ans = optimal_strategy(0,n-1,dp,arr) ; 
    cout<< 2*ans - total_sum <<endl;
    return 0;
    
        
}

