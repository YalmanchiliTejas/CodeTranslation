#include<iostream>
using namespace std;

long long int dp[3001][3001];

long long int solve(long long int a[],int n,int i,int j)
{
	if(i>j)
	{
		return(0);
	}
	if(dp[i][j]!=-1)
	{
		return(dp[i][j]);
	}
	long long int op1=a[i]+min(solve(a,n,i+2,j),solve(a,n,i+1,j-1));
	long long int op2=a[j]+min(solve(a,n,i+1,j-1),solve(a,n,i,j-2));
	return(dp[i][j]=max(op1,op2));
}
int main(int argc, char const *argv[])
{
	int n,i,j;
	cin>>n;
	long long int a[n];
	long long int sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(i=0;i<=3000;i++)
	{
		for(j=0;j<=3000;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<2*solve(a,n,0,n-1)-sum;
	return 0;
}




