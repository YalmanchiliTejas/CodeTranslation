#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010];
char s[1010][1010];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	for(i=1; i<=n; i++)
	{
		scanf("%s",s[i]+1);
		for(j=1; j<=m; j++)
			if(s[i][j]=='.')
			{
				a[i]++;
				b[j]++;
			}
	}
	for(i=1; i<=n; i++)
	{
		if(a[i]==m) continue;
		for(j=1; j<=m; j++)
			if(b[j]!=n) cout<<s[i][j];
		cout<<endl;
	}
	return 0;
}