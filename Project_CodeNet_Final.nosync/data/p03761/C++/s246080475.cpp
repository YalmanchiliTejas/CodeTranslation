#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<cmath>
#include<iomanip>
#include<algorithm>
#define int long long int
#define mod 1000000007
int memo[101][101];
void function()
{
	int i=0,j=0;
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{
			if(j>i)
			{
				memo[i][j]=0;
			}
		}
	}
	memo[1][1]=1;
	for(i=2;i<=100;i++)
	{
		memo[i][1]=i;
	}
	for(i=2;i<=100;i++)
	{
		for(j=2;j<=100;j++)
		{
			memo[i][j]=(memo[i-1][j]+memo[i-1][j-1]);
		}
	}
}
int ncr(int n,int r)
{
	if(r>n)
	   return 0;
	return memo[n][r];
}
int32_t main()
{
	int n;
	cin>>n;
	int count[n][26]={0};
	int j;
	for(j=0;j<n;j++)
	{
		string str;
		cin>>str;
		for(char x:str)
		{
			count[j][x-97]++;
	    }
	}
	for(int i=0;i<26;i++)
	{
		int val=100000;
		for(j=0;j<n;j++)
		{
			val=min(val,count[j][i]);
		}
		char x=char(i+97);
		for(j=0;j<val;j++)
		  cout<<x;
	}
	cout<<endl;
}
