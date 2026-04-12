#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,p,x,y; int t[16][16];
	while(scanf("%d",&n), n)
	{
		memset(t,0,sizeof(t));

		p=0; x=n/2; y=n/2+1;
		while(p<n*n)
		{
			x=(x+n)%n;
			y=(y+n)%n;

			if(!t[y][x])
			{
				t[y][x]=++p;
				y++;
				x++;
			}
			else
			{
				y++;
				x--;
			}
		}

		for(y=0; y<n; y++)
		{
			for(x=0; x<n; x++)
			{
				printf("%4d",t[y][x]);
			}
			printf("\n");
		}
	}
}