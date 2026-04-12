#include<cstdio>
using namespace std;
int A[15][15];
main()
{
	int N;
	while(scanf("%d",&N),N)
	{
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)A[i][j]=0;
		int x=N/2+1,y=N/2;
		for(int i=1;i<=N*N;i++)
		{
			while(A[x][y]!=0)
			{
				x=(x+1)%N,y=(y-1+N)%N;
			}
			A[x][y]=i;
			x=(x+1)%N,y=(y+1)%N;
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)printf("%4d",A[i][j]);
			puts("");
		}
	}
}

