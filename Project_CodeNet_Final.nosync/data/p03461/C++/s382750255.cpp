#include<cstdio>
#include<cstring>
int a[15][15],g[105][105];
int main()
{
	int n,m,i,j,x,y,k,l,o,O,cnt=200;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	memset(g,-1,sizeof(g));
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)
	{
		for(o=x=0;x<=100&&!o;++x)for(y=0;y<=100&&!o;++y)if(g[x][y]>=0&&g[x][y]+x*i+y*j==a[i][j])o=1;
		if(o)continue;
		for(x=0;x<=100&&!o;++x)for(y=0;y<=100&&!o;++y)if(g[x][y]<0&&x*i+y*j<=a[i][j])
		{
			for(O=0,k=1;k<=n&&!O;++k)for(l=1;l<=m&&!O;++l)if(x*k+y*l+a[i][j]-x*i-y*j<a[k][l])O=1;
			if(!O){g[x][y]=a[i][j]-x*i-y*j;o=1;++cnt;}
		}
		if(!o)return 0*puts("Impossible");
	}
	printf("Possible\n202 %d\n",cnt);
	for(i=1;i<=100;++i)printf("%d %d X\n",i,i+1);
	for(i=102;i<=201;++i)printf("%d %d Y\n",i,i+1);
	for(i=0;i<=100;++i)for(j=0;j<=100;++j)if(g[i][j]>=0)printf("%d %d %d\n",i+1,202-j,g[i][j]);
	puts("1 202");
}