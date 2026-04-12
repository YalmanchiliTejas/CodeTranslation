#include<bits/stdc++.h>
using namespace std;
int n,d[100005];
string s;
bool dfs(int i)
{
	if(i==n-1)
	{
		if(s[i]=='o'&&d[i]&&d[(i+1)%n]==d[(i-1+n)%n])return false;
		if(s[i]=='o'&&!d[i]&&d[(i+1)%n]!=d[(i-1+n)%n])return false;
		if(s[i]=='x'&&d[i]&&d[(i+1)%n]!=d[(i-1+n)%n])return false;
		if(s[i]=='x'&&!d[i]&&d[(i-1+n)%n]==d[(i+1)%n])return false;
		if(dfs(0))return true;
		return false;
	}
	if(i==0)
	{
		if(s[i]=='o'&&d[i]&&d[(i+1)%n]==d[(i-1+n)%n])return false;
		if(s[i]=='o'&&!d[i]&&d[(i+1)%n]!=d[(i-1+n)%n])return false;
		if(s[i]=='x'&&d[i]&&d[(i+1)%n]!=d[(i-1+n)%n])return false;
		if(s[i]=='x'&&!d[i]&&d[(i-1+n)%n]==d[(i+1)%n])return false;
		return true;
	}
	if(s[i]=='o')
	{
		if(d[i]==1)
		{
			d[i+1]=!d[i-1];
			if(dfs(i+1))return true;
			return false;
		}
		if(d[i]==0)
		{
			d[i+1]=d[i-1];
			if(dfs(i+1))return true;
			return false;
		}
	}
	if(s[i]=='x')
	{
		if(d[i]==1)
		{
			d[i+1]=d[i-1];
			if(dfs(i+1))return true;
			return false;
		}
		if(d[i]==0)
		{
			d[i+1]=!d[i-1];
			if(dfs(i+1))return true;
			return false;
		}
	}
	
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		d[0]=i;d[1]=j;
		if(dfs(1))
		{
			for(int i=0;i<n;i++)
				printf("%c",d[i]?'W':'S');
			cout<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}