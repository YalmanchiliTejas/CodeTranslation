#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int main()
{
    int n,m;
    bool p=true;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",a[i]+1);
	}
	if(a[1][1]!='#'||a[n][m]!='#')p=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#')
			{
				if(a[i+1][j]=='#'&&a[i][j+1]=='#')p=false;
			}
		}
	}
	int rr[15],ll[15];
	for(int i=1;i<=n;i++)
	{
		ll[i]=1000;
		rr[i]=-1000;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#')
			{
				rr[i]=max(rr[i],j);
				ll[i]=min(ll[i],j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(rr[i]>ll[j])p=false;
		}
	}
	if(p)printf("Possible");
	else printf("Impossible");
}
