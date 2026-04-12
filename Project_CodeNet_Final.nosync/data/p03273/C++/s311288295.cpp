#include<bits/stdc++.h>
using namespace std;
char c[150][150],ans[150][150],f[150][150];
int n,m;
int h[150],l[150];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=m;j++)
		if(c[i][j]=='.')tmp++;
		if(tmp==m)h[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int tmp=0;
		for(int j=1;j<=n;j++)
		if(c[j][i]=='.')tmp++;
		if(tmp==n)l[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i]==1)continue;
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(l[j]!=1)cout<<c[i][j];
			}
			cout<<endl;
		} 	
	}
	return 0;
}