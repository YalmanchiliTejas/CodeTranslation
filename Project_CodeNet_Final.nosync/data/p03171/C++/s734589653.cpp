#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define size 3000
#define ll long long int
ll arr[size];


int main()
{
	int n;
	cin>>n;
	ll sum[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(i==0)
			sum[0]=arr[0];
		else
			sum[i]=sum[i-1]+arr[i];
	}
	ll dp[n][n];
	//ll dp2[n][n];
	for(int t=0;t<n;t++)
	{
		for(int j=t;j<n;j++)
		{
			int i=j-t;
			if(i==j)
				dp[i][j]=arr[i];
			else
			{
				if(i!=0)
					dp[i][j]=sum[j]-sum[i-1]-min(dp[i+1][j],dp[i][j-1]);
				else
					dp[i][j]=sum[j]-min(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout<<dp[i][j]<<"  ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<(2*dp[0][n-1])-sum[n-1]<<endl;



}
