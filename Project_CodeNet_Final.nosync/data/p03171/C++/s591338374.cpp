#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define function function2
#define int long long int
int memo[3001][3001];
int function(int arr[],int i,int j,int status)
{
	if(i>j)
	  return 0;
	if(memo[i][j]!=-1)
	   return memo[i][j];
	else
	{
		if(status==0)
		{
			int x=arr[i]+function(arr,i+1,j,1-status);
			int y=arr[j]+function(arr,i,j-1,1-status);
			int here=max(x,y);
			memo[i][j]=here;
			return here;
		}
		else
		{
			int x=function(arr,i+1,j,1-status);
			int y=function(arr,i,j-1,1-status);
			int here=min(x,y);
			memo[i][j]=here;
			return here;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int j,arr[n];
	for(j=0;j<n;j++)
	   cin>>arr[j];
	int i;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		  memo[i][j]=-1;
	}
	int answer=function(arr,0,n-1,0);
	int total=0;
	for(j=0;j<n;j++)
	  total+=arr[j];
	int x=answer;
	int y=total-answer;
	cout<<x-y<<endl;
}
