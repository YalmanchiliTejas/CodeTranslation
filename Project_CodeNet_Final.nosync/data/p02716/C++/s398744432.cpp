#include<iostream>
using namespace std;
#include<vector>
#define int long long int
#define mod 1000000007
int function(int arr[],int initial,int final,int curr,int memo[][3])
{
	if(initial>final)
	  return 0;
	if(memo[initial][curr]!=-1)
	{
		return memo[initial][curr];
	}
	else
	{
		if(curr==0)
		{
			int val=arr[initial]+function(arr,initial+2,final,curr,memo);
			memo[initial][curr]=val;
			return val;
		}
		else
		{
			int val1=arr[initial]+function(arr,initial+2,final,curr,memo);
			int val2=arr[initial]+function(arr,initial+3,final,curr-1,memo);
			memo[initial][curr]=max(val1,val2);
			return max(val1,val2);
		}
	}
}
int32_t main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		int arr[n+1];
		int j;
		for(j=1;j<=n;j++)
		{
			cin>>arr[j];
		}
		int prefix[n+1]={0};
		int suffix[n+1]={0};
		for(j=1;j<=n;j++)
		{
			if(j%2!=0)
			{
				prefix[j]=arr[j];
			}
			else
			{
				suffix[j]=arr[j];
			}
		}
		for(j=3;j<=n;j+=2)
		{
			prefix[j]+=prefix[j-2];
		}
		for(j=n-2;j>=1;j-=2)
		{
			suffix[j]+=suffix[j+2];
		}
		int answer=prefix[n-1];
		for(j=n;j>=1;j-=2)
		{
			int answer2=suffix[j];
			if(j-3>=1)
			{
				answer2+=prefix[j-3];
			}
			answer=max(answer,answer2);
		}
		cout<<answer<<endl;
    }
    else
    {
		int arr[n+1];
		int j;
		for(j=1;j<=n;j++)
		{
			cin>>arr[j];
		}
		int memo[n+1][3];
		int i;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				memo[i][j]=-1;
			}
		}
		int val1=function(arr,1,n,2,memo);
		int val2=function(arr,2,n,1,memo);
		int val3=function(arr,3,n,0,memo);
		int answer2=max(val1,max(val2,val3));
		cout<<answer2<<endl;
	}
}
