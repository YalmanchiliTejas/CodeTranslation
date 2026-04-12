#include<bits/stdc++.h>
using namespace std;
int d[1001][1001];
int f[1001][1001];
signed main()
{
	int a,b;
	const int n=100;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			scanf("%d",&d[i][j]);
		
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int x=1;x<=a;x++)
				for(int y=1;y<=b;y++)
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
	
	for(int x=1;x<=a;x++)
		for(int y=1;y<=b;y++)
		{
			int val=999999999;
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
					val=min(val,f[i][j]+i*x+j*y);
			if(val!=d[x][y])
			{
				printf("Impossible");
				return 0;
			}
		}
			
	printf("Possible\n");
	
	printf("202 10401\n");
	
	for(int i=1;i<=100;i++)
		printf("%d %d X\n",i,i+1);

	for(int i=102;i<202;i++)
		printf("%d %d Y\n",i,i+1);

	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
	printf("1 202\n");
	return 0;
}
