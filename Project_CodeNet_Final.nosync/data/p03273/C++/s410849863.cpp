#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[109][109];
bool h[109],l[109];
bool mach;
int main()
{
	scanf("%d%d",&n,&m);
	for(int j=1;j<=n;j++)
		scanf("%s",a[j]);
	for(int j=1;j<=n;j++)
	{
		mach=0;
		for(int i=0;i<m;i++)
			if(a[j][i]=='#')
			{
				mach=1;
				break;
			}
		if(mach==0) h[j]=1;
	}
	for(int i=0;i<m;i++)
	{
		mach=0;
		for(int j=1;j<=n;j++)
			if(h[j]==0 && a[j][i]=='#')
			{
				mach=1;
				break;
			}
		if(mach==0) l[i]=1;
	}
	for(int j=1;j<=n;j++)
	{
		if(h[j]==1) continue;
		for(int i=0;i<m;i++)
			if(l[i]==0) printf("%c",a[j][i]);
		puts("");
	}
	return 0;
}