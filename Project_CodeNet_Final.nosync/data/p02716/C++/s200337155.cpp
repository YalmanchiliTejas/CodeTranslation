#include<iostream>
using namespace std;
#include<vector>
#define int long long int
#define inf 1000000000000000
int function(int arr[],int initial,int final,int curr,int memo[][3])
{
	if(initial>final)
	{
		if(curr==2)
		{
			return -inf;
		}
		if(curr==1&&initial==final+3)
		{
			return -inf;
		}
		else
		  return 0;
	}
	if(memo[initial][curr]!=-1)
	  return memo[initial][curr];
	else
	{
		if(curr==0)
		{
			int val=arr[initial]+function(arr,initial+2,final,curr,memo);
			memo[initial][curr]=val;
			return memo[initial][curr];
		}
		else
		{
			int val1=arr[initial]+function(arr,initial+2,final,curr,memo);
			int val2=arr[initial]+function(arr,initial+3,final,curr-1,memo);
			memo[initial][curr]=max(val1,val2);
			return memo[initial][curr];
		}
	}
}
int function2(int arr[],int initial,int final,int curr,int memo[][2])
{
	if(initial>final)
	{
        if(curr==1)
        {
			return -inf;
		}
		if(curr==0&&initial==final+4)
		{
			return -inf;
		}
		return 0;
    }
    if(memo[initial][curr]!=-1)
      return memo[initial][curr];
    else
    {
		if(curr==0)
		{
			
			int x=arr[initial]+function2(arr,initial+2,final,curr,memo);
			memo[initial][curr]=x;
			return memo[initial][curr];
		}
		else
		{
			int x=arr[initial]+function2(arr,initial+2,final,curr,memo);
			int y=arr[initial]+function2(arr,initial+4,final,curr-1,memo);
			memo[initial][curr]=max(x,y);
			return memo[initial][curr];
		}
	}
}
int32_t main()
{
		int n;
		cin>>n;
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
		if(n%2==0)
		{
			int val1=function(arr,1,n,1,memo);
			int val2=function(arr,2,n,0,memo);
			cout<<max(val1,val2)<<endl;
		}
		else
		{
			int val1=function(arr,1,n,2,memo);
			int val2=function(arr,2,n,1,memo);
			int val3=function(arr,3,n,0,memo);
			int answer2=max(val1,max(val2,val3));
			int memo2[n+1][2];
			for(i=0;i<=n;i++)
			{
				memo2[i][0]=-1;
				memo2[i][1]=-1;
			}
			int val4=function2(arr,1,n,1,memo2);
			answer2=max(answer2,val4);
			cout<<answer2<<endl;
		}
}
