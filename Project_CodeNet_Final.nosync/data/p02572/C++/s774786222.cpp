#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t1;
	t1=1;
	while(t1--)
	{
	

	long long int n,m,i,j,k,sum;
	
	long long int a[300000],dp[300000] {0};
	
	cin>>n;
	
	for(i=0;i<n;i++)
	cin>>a[i];
	
	dp[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		dp[i]= (dp[i+1]+a[i+1] ) % 1000000007;
		
	}
	
	sum=0;
	for(i=0;i<n-1;i++)
	{
		
		sum= (sum+ (a[i]*dp[i])%1000000007 )%1000000007;
		
	}
	
	cout<<sum<<endl;
	}



}
