#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105],t[105];
char a[105][105];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	cin>>a[i][j];
	for(int i=1;i<=n;++i)
	{
		int tag=0;
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='.') continue;
			else{tag=1;break;}
		}
		if(!tag) s[i]=1;
	}
	for(int i=1;i<=m;++i)
	{
		int tag=0;
		for(int j=1;j<=n;++j)
		{
			if(a[j][i]=='.') continue;
			else{tag=1;break;}
		}
		if(!tag) t[i]=1;
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i]) continue;
		for(int j=1;j<=m;++j)
		{
			if(t[j]) continue;
			putchar(a[i][j]);
		}
		putchar('\n');
	}
	return 0;
}