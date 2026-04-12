#include<bits/stdc++.h>
#define ll long long 
using namespace std;


ll arr[3010],n;
ll dp[3010][3010],sum;

ll solve(int i,int j)
{
	if(i>j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	
	ll a=min(solve(i+2,j),solve(i+1,j-1))+arr[i];
	ll b=min(solve(i+1,j-1),solve(i,j-2))+arr[j];
//	cout<<a<<" "<<b<<endl;
	return dp[i][j]=max(a,b);
	
	
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	sum+=arr[i];	
	}
    
    ll res=solve(0,n-1);

    cout<<2LL*res-sum<<endl;
    
	return 0;
}