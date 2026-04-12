#include <cstdio>
 
int c[12][12],g[12][12];
int u[1200000],v[1200000],w[1200000];
int i,j,k,m,n,x,y,z;
bool b;
 
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	for (x=0;x<=100;x++)
		for (y=0;y<=100;y++)
			for (z=0;z<=100;z++)
			{
				b=false;
				for (i=1;i<=n;i++)
					for (j=1;j<=m;j++)
						if (x*i+y*j+z<g[i][j])
							b=true;
				if (b)
					continue;
				b=false;
				for (i=1;i<=n;i++)
					for (j=1;j<=m;j++)
						if (x*i+y*j+z==g[i][j])
							b=true,c[i][j]=1;
				if (! b)
					continue;
				k++,u[k]=x,v[k]=y,w[k]=z;
			}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (! c[i][j])
			{
				puts("Impossible");
				return 0;
			}
	puts("Possible");
	printf("%d %d\n",202,k+200);
	for (i=1;i<=100;i++)
		printf("%d %d X\n",i,i+1);
	for (i=102;i<=201;i++)
		printf("%d %d Y\n",i,i+1);
	for (i=1;i<=k;i++)
		printf("%d %d %d\n",1+u[i],202-v[i],w[i]);
	printf("%d %d\n",1,202);
	return 0;
}