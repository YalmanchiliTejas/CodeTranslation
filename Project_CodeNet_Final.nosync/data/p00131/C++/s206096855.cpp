#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, -1, 0, 1};

int a[10][10];
int grid[10][10];
int res[10][10];

bool ok(int i, int j)
{
	return i >= 0 && j >= 0 && i < 10 && j < 10;
}

void rev(int x, int y)
{
	for (int dir = 0; dir < 5; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (ok(nx, ny)) grid[nx][ny] ^= 1;
	}
}

void solve()
{
	for (int x = 0; x < (1 << 10); x++){
		memset(res, 0, sizeof(res));
		memcpy((void *)grid, (void *)a, sizeof(grid));
		
		for (int i = 0; i < 10; i++){
			if (x & (1 << i)){
				res[0][i] = 1;
				rev(0, i);
			}
		}
		
		for (int i = 1; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (grid[i - 1][j]){
					res[i][j] = 1;
					rev(i, j);
				}
			}
		}
		
		int f = 0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				f += grid[i][j];
			}
		}
		if (!f) break;
	}
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (j) printf(" ");
			printf("%d", res[i][j]);
		}
		puts("");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				scanf("%d", &a[i][j]);
			}
		}
		solve();
	}
	return 0;
}