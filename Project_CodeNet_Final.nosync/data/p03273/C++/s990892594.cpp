#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int MAXN=110;
char a[MAXN][MAXN];
bool b[MAXN],c[MAXN];
int m,n,l,p,k,ans,tot;
bool flg;
int inline read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
	n=read();
	m=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
	}
	
	if (n==1)
	{
		bool flg=true;
		if (a[1][1]!='.') 
		{
			for (int i=2;i<=m;i++)
			{
				if (a[1][i]!=a[1][1])
				{
					flg=false;
					continue;	
				}	
			}	
			if (flg) 
			{
				printf("%s",a[1]+1);
				return 0;
			}
		}
	} 
	
	
	
	if (m==1)
	{
		bool flg=true;
		if (a[1][1]!='.')
		{
			for (int i=2;i<=n;i++)
			{
				if (a[i][1]!=a[1][1])
				{
					flg=false;
					continue;	
				}	
			}	
			if (flg) 
			{
				for (int i=1;i<=n;i++) printf("%c\n",a[i][1]);
				return 0;
			}
		}
	} 
	
	for (int i=1;i<=n;i++)
	{
		b[i]=1;
		if (a[i][1]!='.')
		{
			b[i]=0;
			continue;
		}
		for (int j=2;j<=m;j++)
		{
			if (a[i][j]!=a[i][1])
			{
				b[i]=0;
				break;
			}
		}
	}
	
	for (int i=1;i<=m;i++)
	{
		c[i]=1;
		
		if (a[1][i]!='.')
		{
			c[i]=0;
			continue;
		}
		
		for (int j=2;j<=n;j++)
		{
			if (a[j][i]!=a[1][i])
			{
				c[i]=0;
				break;
			}
		}
	}
	/*
	flg=true;
	for (int i=1;i<=n;i++)
	{
		if (!b[i])
		{
			flg=false;
			break;
		}
	}
	if (flg)
	{
		printf("%s",a[1]+1);
		return 0;
	}
	
	
	flg=true;
	for (int i=1;i<=m;i++)
	{
		if (!c[i])
		{
			flg=false;
			break;
		}
	}
	if (flg)
	{
		for (int i=1;i<=n;i++) printf("%c\n",a[i][1]);
			return 0;
	}
	*/
	
	for (int i=1;i<=n;i++)
	{
		if (b[i]) continue;
		for (int j=1;j<=m;j++)
		{
			if (c[j])
			{
				continue;
			}
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

