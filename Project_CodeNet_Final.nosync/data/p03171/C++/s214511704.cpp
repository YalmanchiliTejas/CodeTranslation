#include<bits/stdc++.h>
using namespace std;
int n;
long long int arr[3001];
long long int dp[3001][3001];
long long int ans=0;
long long int fun(long long int arr[],int i,int j,int k)
{
	if(i<0||j<0||i>n||j>n||i>j)
	return 0;
	else if(dp[i][j]!=-1)
	return dp[i][j];
	else
	{
		if(k%2==0)
		{
			ans=max(arr[i]+fun(arr,i+1,j,k+1),arr[j]+fun(arr,i,j-1,k+1));
		}
		else
		{
			ans=min(-arr[i]+fun(arr,i+1,j,k+1),-arr[j]+fun(arr,i,j-1,k+1));
		}
	}
	dp[i][j]=ans;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	int i,j,k;
	for(i=0;i<n;i++)
	cin >> arr[i];
	memset(dp,-1,sizeof(dp));
	cout << fun(arr,0,n-1,0);
	return 0;
}