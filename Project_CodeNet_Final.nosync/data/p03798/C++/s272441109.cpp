#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char order[100010];
bool mp[100010];
bool pre,last;
int n;
bool turn(bool a)
{
	if(a)return false;
	return true;
}
bool judge1()
{
	mp[1]=mp[2]=1;
	pre=true;
	if(order[1]=='o')
	last=1;
	else
	last=0;
	for(int i=2;i<=n;i++)
	{
		if(mp[i])
		{
			if(order[i]=='o')
			mp[i+1]=pre;
			else
			mp[i+1]=turn(pre);
		}
		else
		{
			if(order[i]=='o')
			mp[i+1]=turn(pre);
			else
			mp[i+1]=pre;
		}
		pre=mp[i];
	}
	if(mp[n]==last&&mp[n+1]==mp[1])
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[i])printf("S");
			else printf("W");
		}
		printf("\n");
		return true;
	}
	return false;
}
bool judge2()
{
	mp[1]=1,mp[2]=0;
	pre=true;
	if(order[1]=='o')
	last=0;
	else
	last=1;
	for(int i=2;i<=n;i++)
	{
		if(mp[i])
		{
			if(order[i]=='o')
			mp[i+1]=pre;
			else
			mp[i+1]=turn(pre);
		}
		else
		{
			if(order[i]=='o')
			mp[i+1]=turn(pre);
			else
			mp[i+1]=pre;
		}
		pre=mp[i];
	}
	if(mp[n]==last&&mp[n+1]==mp[1])
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[i])printf("S");
			else printf("W");
		}
		printf("\n");
		return true;
	}
	return false;
}
bool judge3()
{
	mp[1]=0,mp[2]=0;
	pre=false;
	if(order[1]=='o')
	last=1;
	else
	last=0;
	for(int i=2;i<=n;i++)
	{
		if(mp[i])
		{
			if(order[i]=='o')
			mp[i+1]=pre;
			else
			mp[i+1]=turn(pre);
		}
		else
		{
			if(order[i]=='o')
			mp[i+1]=turn(pre);
			else
			mp[i+1]=pre;
		}
		pre=mp[i];
	}
	if(mp[n]==last&&mp[n+1]==mp[1])
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[i])printf("S");
			else printf("W");
		}
		printf("\n");
		return true;
	}
	return false;
}
bool judge4()
{
	mp[1]=0,mp[2]=1;
	pre=false;
	if(order[1]=='o')
	last=0;
	else
	last=1;
	for(int i=2;i<=n;i++)
	{
		if(mp[i])
		{
			if(order[i]=='o')
			mp[i+1]=pre;
			else
			mp[i+1]=turn(pre);
		}
		else
		{
			if(order[i]=='o')
			mp[i+1]=turn(pre);
			else
			mp[i+1]=pre;
		}
		pre=mp[i];
	}
	if(mp[n]==last&&mp[n+1]==mp[1])
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[i])printf("S");
			else printf("W");
		}
		printf("\n");
		return true;
	}
	return false;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",order+1);
		if(judge1())continue;
		if(judge2())continue;
		if(judge3())continue;
		if(judge4())continue;	
		printf("-1\n");
	}
	return 0;
}