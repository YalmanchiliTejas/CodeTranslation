#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int h,w,cntnt=0;cin>>h>>w;
	int a[101][101]={0};
	char c;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>c;
			if(c=='#')a[i][j]=2;
			else a[i][j]=1;
		}
	}
	for(int i=0;i<h;i++)
	{
		int cnt=0;
		for(int j=0;j<w;j++)
		{
			if(a[i][j]==1)
			{
				cnt++;
			}
		}
		if(cnt==w)
		{
			for(int j=0;j<w;j++)
			{
				a[i][j]=0;

			}
			cntnt++;
		}
	}
	for(int j=0;j<w;j++)
	{
		int cnt=0;
		for(int i=0;i<h;i++)
		{
			if(a[i][j]==1)
			{
				cnt++;
			}
		}
		if(cnt==h-cntnt)
		{
			for(int i=0;i<h;i++)
			{
				a[i][j]=0;

			}
		}
	}
	for(int i=0;i<h;i++)
	{
		int cnt=0;
		for(int j=0;j<w;j++)
		{
			if(a[i][j]==1)cout<<".";
			else if(a[i][j]==2)cout<<"#";
			else cnt++;
		}
		if(cnt!=w)cout<<endl;
	}
	return 0;
}