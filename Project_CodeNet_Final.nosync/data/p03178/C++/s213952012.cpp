#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define int long long int
#define function function2
#define mod 1000000007
int function(int initial,int final,int memo[][101],int d,int sum)
{
	if(initial>final)
	{
		if(initial==1)
		  return 0;
		return sum==0?1:0;
	}
	if(memo[initial][sum]!=-1)
	   return memo[initial][sum];
	else
	{
		if(initial==1)
		{
			int answer=0;
			int j;
			for(j=1;j<=9;j++)
			{
				answer+=function(initial+1,final,memo,d,(sum+j)%d);
				answer%=mod;
			}
			memo[initial][sum]=answer;
			return answer;
		}
		else
		{
			int answer=0;
			if(sum==0)
			  answer++;
			for(int j=0;j<=9;j++)
			{
				answer+=function(initial+1,final,memo,d,(sum+j)%d);
				answer%=mod;
			}
			memo[initial][sum]=answer;
			return answer;
		}
	}
}
int function(int arr[],int initial,int final,int memo[][101][2],int status,int d,int sum)
{
	if(initial>final)
	{
		return sum==0?1:0;
	}
	if(memo[initial][sum][status]!=-1)
	  return memo[initial][sum][status];
	else
	{
		int val=arr[initial];
		if(initial==0)
		{
			int j;
			int answer=0;
			for(j=1;j<=val;j++)
			{
				int next=(sum+j)%d;
				int nextstatus=0;
				if(j<val)
				  nextstatus=1;
				answer+=function(arr,initial+1,final,memo,nextstatus,d,next);
				answer%=mod;
			}
			memo[initial][sum][status]=answer;
			return answer;
		}
		else
		{
			int j,answer=0;
			if(status==1)
			{
				for(j=0;j<=9;j++)
				{
					answer+=function(arr,initial+1,final,memo,1,d,(sum+j)%d);
					answer%=mod;
				}
				memo[initial][sum][status]=answer;
				return memo[initial][sum][status];
			}
			else
			{
				for(j=0;j<=val;j++)
				{
					int next=(sum+j)%d;
					int nextstatus=0;
					if(j<val)
					  nextstatus=1;
					answer+=function(arr,initial+1,final,memo,nextstatus,d,next);
					answer%=mod;
				}
				memo[initial][sum][status]=answer;
				return memo[initial][sum][status];
			}
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int d;
	cin>>str>>d;
	int n=str.size();
	int j,arr[n];
	for(j=0;j<n;j++)
	   arr[j]=str[j]-48;
	int answer=0;
	int memo[n+1][101];
	int i;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=100;j++)
		{
			memo[i][j]=-1;
		}
	}
	answer+=function(1,n-1,memo,d,0);
	answer%=mod;
	int memo2[n+1][101][2];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=100;j++)
		{
			for(int k=0;k<2;k++)
			{
				memo2[i][j][k]=-1;
			}
		}
	}
	int here=function(arr,0,n-1,memo2,0,d,0);
	answer+=here;
	answer%=mod;
	cout<<answer<<endl;
}
