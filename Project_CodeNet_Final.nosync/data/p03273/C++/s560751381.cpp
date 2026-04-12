#include <iostream>
using namespace std;
int main()
{
	int h,w;
	cin>>h>>w;
	char a[100+5][100+5];
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			cin>>a[i][j];
	for(int i=0;i<h;i++)
	{
		int flag=0;
		for(int j=0;j<w;j++)
		{
			if(a[i][j]=='#')
				flag=1;
		}
		if(flag==0)
			for(int j=0;j<w;j++)
				a[i][j]=1;
	}
	for(int i=0;i<w;i++)
	{
		int flag=0;
		for(int j=0;j<h;j++)
		{
			if(a[j][i]=='#')
				flag=1;
		}
		if(flag==0)
			for(int j=0;j<h;j++)
				a[j][i]=1;
	}
	for(int i=0;i<h;i++)
	{
		int flag=0;
		for(int j=0;j<w;j++)
		{
			if(a[i][j]!=1)
			{	
				flag=1;
				cout<<a[i][j];
			}
		}
		if(flag==1)
			cout<<endl;
	}
	return 0;
}