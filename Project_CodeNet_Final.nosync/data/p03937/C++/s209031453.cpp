#include<cstdio>
#include<cstdlib>
#include<cstring>



bool work()
{
	int left = 1;
	char matrix[16][16];
	int h,w;
	scanf("%d%d", &h, &w);
	for(int i=0; i<h; ++i)
	{
		matrix[i][0] = '.';
		scanf("%s", &matrix[i][1]);
		matrix[i][w+1] = '.';
	}
	for(int i=0; i<h; ++i)
	{
		if(matrix[i][left] != '#') return false;
		for(int j=left-1; j>0; --j)
		{
			if(matrix[i][j]=='#')
			{
				return false;
			}
		}
		for(; left <= w; ++left)
		{
			if(matrix[i][left+1] == '.')
				break;
		}
		for(int j=left+1; j<=w; ++j)
		{
			if(matrix[i][j] == '#')
				return false;
		}
	}
	return left == w;
}
int main()
{
	if(work())
	{
		printf("Possible\n");
	}
	else
	{
		printf("Impossible\n");
	}
	return 0;
}