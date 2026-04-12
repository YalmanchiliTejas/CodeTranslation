#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn=1e5+5;
char a[maxn],b[maxn];
int n;

int get()
{
	for(int i=1;i<n;i++)
	{
		if(i<n-2)
		{
			if(a[i]=='o')
			{
				if(b[i]=='S')
				    b[i+1]=b[i-1];
				else
				{
					if(b[i-1]=='S')
					    b[i+1]='W';
					else
					    b[i+1]='S';
			    }
			}
			else
			{
				if(b[i]=='W')
				    b[i+1]=b[i-1];
				else
				{
					if(b[i-1]=='S')
					    b[i+1]='W';
					else
					    b[i+1]='S';
			    }
			}
		}
		    else if(i==n-2)
			{
				if(a[i]=='o')
				{
					if(b[i]=='W'){
					    if(b[i-1]==b[i+1])
					        return 0;
					    }
					else{
						if(b[i-1]!=b[i+1])
						    return 0;
					}
				}
				else
				{
					if(b[i]=='W'){
					    if(b[i-1]!=b[i+1])
					        return 0;
					    }
					else{
						if(b[i-1]==b[i+1])
						    return 0;
					}
				}
			}
			else
			{
				if(a[i]=='o')
				{
					if(b[i]=='S')
					{
						if(b[i-1]!=b[0])
						    return 0;
					}
					else
					{
						if(b[i-1]==b[0])
						    return 0;
					}
				}
				else
				{
					if(b[i]=='S')
					{
						if(b[i-1]==b[0])
						    return 0;
					}
					else
					{
						if(b[i-1]!=b[0])
						    return 0;
					}
				}
			}
		}
	return 1;
}

int main()
{
	int flag;
	scanf("%d",&n);
	scanf("%s",a);
	if(a[0]=='o')
	{
		memset(b,0,sizeof(b));
		b[0]='S';
		b[n-1]='S'; 
		b[1]='S';
		flag=get();
		if(flag)
		{
			printf("%s\n",b);
			return 0;
		 } 
		else
		{
			memset(b,0,sizeof(b));
			b[0]='W';
			b[n-1]='S';
			b[1]='W';
			flag=get();
			if(flag)
			{
				printf("%s\n",b);
				return 0;
			 } 
		}
	}
	else
	{
		memset(b,0,sizeof(b));
		b[0]='S';
		b[n-1]='S'; 
		b[1]='W';
		flag=get();
		if(flag)
		{
			printf("%s\n",b);
			return 0;
		 } 
		else
		{
			memset(b,0,sizeof(b));
			b[0]='W';
			b[n-1]='W';
			b[1]='W';
			flag=get();
			if(flag)
			{
				printf("%s\n",b);
				return 0;
			 } 
		}
	}
	if(a[0]=='o')
	{
		memset(b,0,sizeof(b));
		b[0]='S';
		b[n-1]='W'; 
		b[1]='W';
		flag=get();
		if(flag)
		{
			printf("%s\n",b);
			return 0;
		 } 
		else
		{
			memset(b,0,sizeof(b));
			b[0]='W';
			b[n-1]='W';
			b[1]='S';
			flag=get();
			if(flag)
			{
				printf("%s\n",b);
				return 0;
			 } 
		}
	}
	else
	{
		memset(b,0,sizeof(b));
		b[0]='S';
		b[n-1]='W'; 
		b[1]='S';
		flag=get();
		if(flag)
		{
			printf("%s\n",b);
			return 0;
		 } 
		else
		{
			memset(b,0,sizeof(b));
			b[0]='W';
			b[n-1]='S';
			b[1]='S';
			flag=get();
			if(flag)
			{
				printf("%s\n",b);
				return 0;
			 } 
		}
	}
	printf("-1\n");
	return 0;
}