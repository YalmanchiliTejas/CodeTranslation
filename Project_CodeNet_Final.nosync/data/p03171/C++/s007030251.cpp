#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mo 1000000007
long long int dp[3005][3005];

long long int solve(long long int arr[],int start,int end)
{
	if(start > end )
		return 0;

	if(dp[start][end] != 0)
	{
		return dp[start][end];
	}

	dp[start][end] =  max(arr[start] + min(solve(arr,start+2,end),solve(arr,start+1,end-1)),arr[end] + min(solve(arr,start+1,end-1),solve(arr,start,end-2)));
	return dp[start][end];
}
int main()
{
	int n;
	cin>>n;
	long long int arr[n];
	long long int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum = sum + arr[i];
	}
	memset(dp,0,sizeof(dp));
	long long int a = solve(arr,1,n);
	long long int b = sum - a;
	long long int c = a-b;
	cout<<c<<endl;
}