#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
long long int p(vector<long long int>&a,int s,int e,vector<vector<long long int>>&dp)
{
    if(s>e)
    return 0;
    if(s==e)
    return dp[s][e]=a[s];
    if(e-s==1)
    return dp[s][e]=max(a[s],a[e]);
    if(dp[s][e]!=-1)
    return dp[s][e]; 
    long long int b=a[s]+min(p(a,s+2,e,dp),p(a,s+1,e-1,dp));
    long long int c=a[e]+min(p(a,s,e-2,dp),p(a,s+1,e-1,dp));
    return dp[s][e]=max(b,c);
}
int main() {
	int n;
	cin>>n;
	long long int t=0;
	vector<long long int>nums(n);
	rep(i,n)
	{
	    cin>>nums[i];
	    t+=nums[i];
	}
	vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
 
	long long int r=p(nums,0,n-1,dp);
	cout<<r-(t-r);
	
	
}