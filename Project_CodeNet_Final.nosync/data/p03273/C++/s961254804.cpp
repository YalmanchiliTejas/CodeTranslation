#include<iostream>
using namespace std;
char a[1000][1000];
int main()
{
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=h;i++)
	{
		int check=1;
		for(int j=1;j<=w;j++)
		{
			if(a[i][j]=='#')
			{
				check=0;
				break;
			}
		}
		if(check==1)
		{
			for(int j=1;j<=w;j++)
		  {
			   a[i][j]='0';
		  }
		}
	}
	for(int i=1;i<=w;i++)
	{
		int check=1;
		for(int j=1;j<=h;j++)
		{
			if(a[j][i]=='#')
			{
				check=0;
				break;
			}
		}
		if(check==1)
		{
			for(int j=1;j<=h;j++)
		  {
			   a[j][i]='0';
		  }
		}
	}
	for(int i=1;i<=h;i++)
	{
		int check=0;
		for(int j=1;j<=w;j++)
		{
			if(a[i][j]=='0')
			continue;
			else
			{
			   cout<<a[i][j];	
			   check=1;
			}
		}
		if(check==1)
		cout<<endl;
	}
}