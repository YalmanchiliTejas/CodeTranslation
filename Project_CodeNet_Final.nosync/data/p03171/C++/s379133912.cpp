#include<bits/stdc++.h>
using namespace std;
#define faster cin.tie(0);ios_base::sync_with_stdio(0)
#define ll long long

int n,k;
ll arr[3004];


// fun(i,j)=arr[i]+fun(i+1,j),arr[j]+fun(i,j-1);

ll dp[3004][3004];

ll find(int i,int j)
{
	if(i>j) return 0;

	
	
	if(dp[i][j]!=-1) return dp[i][j];
	
	// player 1 picks left
	ll cost1=arr[i]+min(find(i+1,j-1),find(i+2,j));

	// player 2 picks right
	ll cost2=arr[j]+min(find(i+1,j-1),find(i,j-2));

	return dp[i][j]=max(cost1,cost2);
	
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n;cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++) 
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	// cout<<sum<<endl;
	ll x=find(0,n-1);
	ll y=sum-x;
	cout<<(x-y)<<endl;
	
}
	
