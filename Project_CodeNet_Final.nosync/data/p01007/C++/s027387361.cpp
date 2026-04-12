#include<iostream>
#include<cstdio>

using namespace std;

void dfs(int y, int x, int **map, int num, int n);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
	int n, r, c, size, m, o, angle, **map, **temp, f1, f2, f3, f4, tmp;
	//一行目入力(n, m)
	scanf("%d %d",&n, &m);
	map = new int *[n];
	temp = new int *[n];
	for(f1 = 0; f1 < n; f1++)
	{
		map[f1] = new int [n];
		temp[f1] = new int [n];
	}
	//グリッド情報入力
	for(f1 = 0; f1 < n; f1++)
	{
		for(f2 = 0; f2 < n; f2++)
		{
			scanf("%d",&map[f1][f2]);
		}
	}
	//シュミレーション開始
	for(f1 = 1; f1 <= m; f1++)
	{
		scanf("%d",&o);
		switch(o)
		{
			//回転
			case 0:
				scanf("%d %d %d %d",&r, &c, &size, &angle);
				r--; c--; size--;
				for(f2 = 1; f2 <= angle / 90; f2++)
				{
					//コピー
					for(f3 = r; f3 <= r + size; f3++)
					{
						for(f4 = c; f4 <= c + size; f4++)
						{
							temp[f3][f4] = map[f3][f4];
						}
					}
					//代入
					for(f3 = r; f3 <= r + size; f3++)
					{
						for(f4 = c; f4 <= c + size; f4++)
						{
							map[f3][f4] = temp[r + (c + size - f4)][f3 + (c - r)];
						}
					}
				}
			break;
			//反転
			case 1:
				scanf("%d %d %d",&r, &c, &size);
				r--; c--; size--;
				for(f3 = r; f3 <= r + size; f3++)
				{
					for(f4 = c; f4 <= c + size; f4++)
					{
						map[f3][f4] = (map[f3][f4] == 0) ? 1 : 0;
					}
				}
			break;
			//左シフト
			case 2:
				scanf("%d", &r);
				r--;
				tmp = map[r][0];
				for(f2 = 1; f2 < n; f2++)
				{
					map[r][f2-1] = map[r][f2];
				}
				map[r][n-1] = tmp;
			break;
			//右シフト
			case 3:
				scanf("%d", &r);
				r--;
				tmp = map[r][n-1];
				for(f2 = n-2; f2 >= 0; f2--)
				{
					map[r][f2+1] = map[r][f2];
				}
				map[r][0] = tmp;
			break;
			//島反転
			case 4:
				scanf("%d %d", &r, &c);
				r--; c--;
				tmp = map[r][c];
				dfs(r, c, map, tmp, n);
			break;
		}
	}
	//出力
	for(f1 = 0; f1 < n; f1++)
	{
		for(f2 = 0; f2 < n; f2++)
		{
			if(f2 < n - 1)
				printf("%d ",map[f1][f2]);
			else
				printf("%d",map[f1][f2]);
		}
		printf("\n");
	}
	return 0;
}

void dfs(int y, int x, int **map, int num, int n)
{
	int f1, nx, ny;
	map[y][x] = (num == 1) ? 0 : 1;
	for(f1 = 0; f1 < 4; f1++)
	{
		nx = x + dx[f1];
		ny = y + dy[f1];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[ny][nx] == num)
		{
			dfs(ny, nx, map, num, n);
		}
	}
}