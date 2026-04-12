#include <bits/stdc++.h>
using namespace std;
int n;
char str[100001];
char ans2[100001];
int check(char* ans,char first,char last,int flag)
{
	if(flag==1)
		return 1;
	for(int i=1;i<=n-1;i++)
	{
		if(i==n-1&&ans[n-1]!=last)
			break;
		if(ans[i]=='S')
		{
			if(str[i]=='o')
			{
				ans[(i+1)%n]=ans[i-1];
			}
			if(str[i]=='x')
			{
				if(ans[i-1]=='S')
					ans[(i+1)%n]='W';
				if(ans[i-1]=='W')
					ans[(i+1)%n]='S';
			}
		}
		else if(ans[i]=='W')
		{
			if(str[i]=='x')
			{
				ans[(i+1)%n]=ans[i-1];
			}
			if(str[i]=='o')
			{
				if(ans[i-1]=='S')
					ans[(i+1)%n]='W';
				if(ans[i-1]=='W')
					ans[(i+1)%n]='S';
			}
		}
	}	
	if(ans[n-1]==last&&ans[0]==first)
	{

		for(int i=0;i<n;i++)
			ans2[i]=ans[i];
		return 1;
	}
	else
		return 0;
}
int main(void)
{
	scanf("%d",&n);
	scanf(" %s ",str);
	char ans[n];
	int flag=0;
	if(str[0]=='o')
	{
		ans[0]='S';
		ans[n-1]='S';
		ans[1]='S';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
		ans[0]='S';
		ans[n-1]='W';
		ans[1]='W';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
		ans[0]='W';
		ans[1]='S';
		ans[n-1]='W';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
		ans[0]='W';
		ans[1]='W';
		ans[n-1]='S';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
	}
	else if(str[0]=='x')
	{
		ans[0]='S';
		ans[n-1]='W';
		ans[1]='S';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
		ans[0]='S';
		ans[n-1]='S';
		ans[1]='W';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
		ans[0]='W';
		ans[1]='S';
		ans[n-1]='S';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
		ans[0]='W';
		ans[1]='W';
		ans[n-1]='W';
		flag=flag|check(ans,ans[0],ans[n-1],flag);
	}
	if(flag==0)
		printf("-1\n");
	else
	{
		for(int i=0;i<n;i++)
			printf("%c",ans2[i]);
	}
}