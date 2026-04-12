#include<stdio.h>

const int N = 10;
int a[N][N];
bool isClick[N][N];

void Click(int x,int y)
{
	int dx[] = {0,1,-1,0, 0,};
	int dy[] = {0,0, 0,1,-1,};
	for(int i = 0;i < 5; ++i)
	{
		if(x+dx[i] >= 0 && x+dx[i] < N && y+dy[i] >= 0 && y+dy[i] < N)
			a[x+dx[i]][y+dy[i]] = !a[x+dx[i]][y+dy[i]];
	}
}

void AllDelete()
{
	int original[N][N];
	int i,j;
	for(i=0;i<N;++i)for(j=0;j<N;++j)original[i][j]=a[i][j];

	unsigned mask=0;
	for(;;)
	{
		for(i=0;i<N;++i)
			for(j=0;j<N;++j)
				a[i][j] = original[i][j],isClick[i][j] = false;
		for(j = 0;j < N;++j)
		{
			if(mask & (1<<j))
				Click(0,j), isClick[0][j] = true;
		}
		++mask;
		for(i = 1; i < N; ++i)
			for(j = 0; j < N; ++j)
			{
				if(a[i-1][j])
					Click(i,j), isClick[i][j] = true;
			}
		bool isEnd = true;
		for(j = 0; j < N; ++j)
		{
			if(a[N-1][j]) isEnd = false;
		}
		if(isEnd) return;
	}
}

int main(void)
{
	int n,i,j;
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<N;++i)
			for(j=0;j<N;++j)
			{
				scanf("%d",&a[i][j]);
				isClick[i][j] = false;
			}

		AllDelete();
		for(i=0;i<N;++i)
		{
			for(j=0;j<N;++j)
				printf("%s%d%s",(j?" ":""),isClick[i][j],(N-j==1?"\n":""));
		}
	}
	return 0;
}