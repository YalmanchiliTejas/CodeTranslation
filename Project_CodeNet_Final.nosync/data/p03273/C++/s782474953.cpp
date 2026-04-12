#include <cstdio>
#include <cstdlib>
#include <cstring>

int h, w;
bool isRowHasBlack[110];
bool isColHasBlack[110];
char board[110][110];

int main()
{
	scanf("%d%d", &h, &w);
	
	for (int i = 0 ; i < h ; i++)
		scanf("%s", board[i]);
	
	memset(isRowHasBlack, false, sizeof(isRowHasBlack));
	memset(isColHasBlack, false, sizeof(isColHasBlack));
	
	for (int r = 0 ; r < h ; r++)
		for (int c = 0 ; c < w ; c++)
		{
			if (board[r][c] == '#')
			{
				isRowHasBlack[r] = true;
				isColHasBlack[c] = true;
			}
		}
		
	for (int r = 0 ; r < h ; r++)
	{
		if (isRowHasBlack[r] == false)
			continue;
		
		for (int c = 0 ; c < w ; c++)
			if (isColHasBlack[c] == true)
				printf("%c", board[r][c]);
				
		printf("\n");
	}
	
	return 0;
}