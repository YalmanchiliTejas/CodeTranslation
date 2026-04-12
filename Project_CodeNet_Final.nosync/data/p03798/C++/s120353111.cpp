#include <bits/stdc++.h>
using namespace std;
int n;
char str[100001];
char ans2[100001];
int check(char* ans,char last,int flag)
{
	if(flag==1)
		return 1;
	for(int i=1;i<=n-2;i++)
	{
		if(ans[i]=='S')
		{
			if(str[i]=='o')
			{
				ans[i+1]=ans[i-1];
			}
			if(str[i]=='x')
			{
				if(ans[i-1]=='S')
					ans[i+1]='W';
				if(ans[i-1]=='W')
					ans[i+1]='S';
			}
		}
		else if(ans[i]=='W')
		{
			if(str[i]=='x')
			{
				ans[i+1]=ans[i-1];
			}
			if(str[i]=='o')
			{
				if(ans[i-1]=='S')
					ans[i+1]='W';
				if(ans[i-1]=='W')
					ans[i+1]='S';
			}
		}
	}
	char temp;
	if(ans[n-1]=='S')
		{
			if(str[n-1]=='o')
			{
				temp=ans[n-2];
			}
			if(str[n-1]=='x')
			{
				if(ans[n-2]=='S')
					temp='W';
				if(ans[n-2]=='W')
					temp='S';
			}
		}
		else if(ans[n-1]=='W')
		{
			if(str[n-1]=='x')
			{
				temp=ans[n-2];
			}
			if(str[n-1]=='o')
			{
				if(ans[n-2]=='S')
					temp='W';
				if(ans[n-2]=='W')
					temp='S';
			}
		}
		
	if(ans[n-1]==last&&temp==ans[0])
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
		flag=flag|check(ans,ans[n-1],flag);
		ans[n-1]='W';
		ans[1]='W';
		flag=flag|check(ans,ans[n-1],flag);
		ans[0]='W';
		ans[1]='S';
		ans[n-1]='W';
		flag=flag|check(ans,ans[n-1],flag);
		ans[1]='W';
		ans[n-1]='S';
		flag=flag|check(ans,ans[n-1],flag);
	}
	else if(str[0]=='x')
	{
		ans[0]='S';
		ans[n-1]='W';
		ans[1]='S';
		flag=flag|check(ans,ans[n-1],flag);
		ans[n-1]='S';
		ans[1]='W';
		flag=flag|check(ans,ans[n-1],flag);
		ans[0]='W';
		ans[1]='S';
		ans[n-1]='S';
		flag=flag|check(ans,ans[n-1],flag);
		ans[1]='W';
		ans[n-1]='W';
		flag=flag|check(ans,ans[n-1],flag);
	}
	if(flag==0)
		printf("-1\n");
	else
	{
		for(int i=0;i<n;i++)
			printf("%c",ans2[i]);
	}
}