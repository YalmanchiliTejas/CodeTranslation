#include<iostream>
#include<cstring>
using namespace std;
int arr[3001],n;
long long dp[3001][3001];
long long solve(int i,int j)
{ if(i>j)
 return 0;
 if(dp[i][j]!=-1)
   return dp[i][j];
 dp[i][j]=max(arr[i]+min(solve(i+2,j),solve(i+1,j-1)),arr[j]+min(solve(i+1,j-1),solve(i,j-2)));
return dp[i][j];
	
}
int main()
{ memset(dp,-1,sizeof(dp));
cin>>n;
long long sum=0;
for(int i=0;i<n;i++)
	{
	 cin>>arr[i];
	  sum+=arr[i];
    }
long long 	int x=solve(0,n-1);
	long long int y=sum-solve(0,n-1);
	cout<<x-y;
	
}