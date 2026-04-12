#include<cstdio>
using namespace std;
int main(void)
{
	int n,i,j,flg,cnt,x,y;
	int a[15][15];
	while(1)	{
		scanf("%d",&n);
		if(n==0)	break;
		for(i=0;i<n;i++)	
			for(j=0;j<n;j++)	a[i][j]=0;
		y=n/2+1;	x=n/2;
		a[y][x]=1;
		for(i=2;i<=n*n;i++)	{
			y++;	x++;
			flg=0;
			while(flg==0)	{
				if(x>=n)	{
					x=0;
				}
				else if(y>=n)	{
					y=0;
				}
				else if(x<0)	{
					x=n-1;
				}
				else if(a[y][x]!=0)	{
					y++;	x--;
				}
				else {
					flg=1;
				}
			}
			a[y][x]=i;
		}
		for(i=0;i<n;i++)	{
			for(j=0;j<n;j++)	{
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
	}	
	return 0;
}
