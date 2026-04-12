#include<cstdio>
int n,m,tot;char ch[10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch+1);
		for(int j=1;j<=m;++j)
			tot+=ch[j]=='#';
	}
	puts(tot==n+m-1?"Possible":"Impossible");
	return 0;
}
