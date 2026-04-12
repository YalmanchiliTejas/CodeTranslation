#include <cstdio>  
#include <iostream>
using namespace std;
char c[110][110];
int row[110],col[110];
int main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	bool judge;
	for(i=1;i<=n;i++)
	{
		judge=false;
		for(j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='#')
				judge=true;
		}
		if(judge)	row[i]=1;
	}
	for(i=1;i<=m;i++)
	{
		judge=false;
		for(j=1;j<=n;j++)
		{
			if(c[j][i]=='#')
				judge=true;
		}
		if(judge)	col[i]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(row[i])
		{
			for(j=1;j<=m;j++)
				if(col[j])
					cout<<c[i][j];
			cout<<endl; 
		}
	}
	return 0;
		
}