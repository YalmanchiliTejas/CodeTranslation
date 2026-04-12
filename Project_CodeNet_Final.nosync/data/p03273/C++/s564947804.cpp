#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[101][101];
bool x[101],y[101];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='#')	
				x[i]=true;
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[j][i]=='#')
			{
				y[i]=true;
				break;
			}
	for(int i=1;i<=n;i++)
	{
		if(!x[i])
			continue;
		for(int j=1;j<=m;j++)
		{
			if(!y[j])
				continue;
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}