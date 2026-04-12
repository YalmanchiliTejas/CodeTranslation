#include<bits/stdc++.h>
using namespace std;


long long int **dp;


long long int score(long long int a[],long long int low,long long int high)
{
	if(dp[low][high])
		return dp[low][high];
	if(low==high)
	{
		dp[low][high]= a[low];
		return dp[low][high];
	}
	else if(low+1==high)
	{
		dp[low][high]= max(a[low],a[high]);
		return dp[low][high];
	}
	
	
	long long int x=0,y=0;
	x=(a[low]+min(score(a,low+2,high),score(a,low+1,high-1)));
	y=(a[high]+min(score(a,low+1,high-1),score(a,low,high-2)));
	dp[low][high]= max(x,y);
	return dp[low][high];
}



int main()
{
	long long int n,i,j;
	cin>>n;
	long long int a[n],sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	dp=new long long int* [n];
	for(i=0;i<n;i++)
		dp[i]=new long long int [n];
	
	cout<<2*score(a,0,n-1)-sum;
	
	
	
}