#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 60


int main() {
	char a[N][N];
	char b[N];
	bool u[N][N];
	bool v[N][N][4];
	int n, m, k;
	int x, y, z;
	bool ans;

	while (true) {
		f(i, N) {
			f(j, N)a[i][j] = '#';
		}
		scanf("%d %d", &n, &m);
      if(n==0)break;
		f(i, n) {
			f(j, N)b[j] = 0;
			scanf("%s", b);
			f(j, m) {
				a[i + 1][j + 1] = b[j];
			}
		}
		ans = true;
		if (a[2][1] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[1][2] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[n-1][1] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[n][2] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[1][m-1] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[2][m] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[n][m - 1] == '#') {
			printf("NO\n");
			continue;
		}
		if (a[n-1][m] == '#') {
			printf("NO\n");
			continue;
		}
		f(i, N) {
			f(j, N) {
				f(ii, 4)v[i][j][ii] = false;
				u[i][j] = false;
			}
		}

		//ここから下
		x = 2;
		y = 1;
		z = 0;
		while (true) {
			if (u[x][y]) {
				ans = false;
				break;
			}
			if (v[x][y][z]) {
				ans = false;
				break;
			}
			v[x][y][z] = true;
			if ((x == n - 1) && (y == 1))break;
			if ((x == n) && (y == 1))break;
			if (z == 0) {
				if (a[x][y - 1] != '#') {
					y--;
					z = 3;
				}
				else if (a[x + 1][y] != '#')x++;
				else z = 1;
			}
			else if (z == 1) {
				if (a[x+1][y] != '#') {
					x++;
					z = 0;
				}
				else if (a[x][y + 1] != '#')y++;
				else z = 2;
			}
			else if (z == 2) {
				if (a[x][y+1] != '#') {
					y++;
					z = 1;
				}
				else if (a[x - 1][y] != '#')x--;
				else z = 3;
			}
			else {
				if (a[x-1][y] != '#') {
					x--;
					z = 2;
				}
				else if (a[x][y - 1] != '#')y--;
				else z = 0;
			}

		}
		if (!ans) {
			printf("NO\n");
			continue;
		}
		f(i, N) {
			f(j, N) {
				f(ii, 4) {
					if (v[i][j][ii]) {
						u[i][j] = true;
						v[i][j][ii] = false;
					}
				}
			}
		}


		//あと3つ

		//ここから下
		x = n;
		y = 2;
		z = 1;
		while (true) {
			if (u[x][y]) {
				ans = false;
				break;
			}
			if (v[x][y][z]) {
				ans = false;
				break;
			}
			v[x][y][z] = true;
			if ((x == n) && (y == m - 1))break;
			if ((x == n) && (y == m))break;
			if (z == 0) {
				if (a[x][y - 1] != '#') {
					y--;
					z = 3;
				}
				else if (a[x + 1][y] != '#')x++;
				else z = 1;
			}
			else if (z == 1) {
				if (a[x + 1][y] != '#') {
					x++;
					z = 0;
				}
				else if (a[x][y + 1] != '#')y++;
				else z = 2;
			}
			else if (z == 2) {
				if (a[x][y + 1] != '#') {
					y++;
					z = 1;
				}
				else if (a[x - 1][y] != '#')x--;
				else z = 3;
			}
			else {
				if (a[x - 1][y] != '#') {
					x--;
					z = 2;
				}
				else if (a[x][y - 1] != '#')y--;
				else z = 0;
			}

		}
		if (!ans) {
			printf("NO\n");
			continue;
		}
		f(i, N) {
			f(j, N) {
				f(ii, 4) {
					if (v[i][j][ii]) {
						u[i][j] = true;
						v[i][j][ii] = false;
					}
				}
			}
		}

		//あと2つ

		//ここから下
		x = n - 1;
		y = m;
		z = 2;
		while (true) {
			if (u[x][y]) {
				ans = false;
				break;
			}
			if (v[x][y][z]) {
				ans = false;
				break;
			}
			v[x][y][z] = true;
			if ((x == 2) && (y == m))break;
			if ((x == 1) && (y == m))break;
			if (z == 0) {
				if (a[x][y - 1] != '#') {
					y--;
					z = 3;
				}
				else if (a[x + 1][y] != '#')x++;
				else z = 1;
			}
			else if (z == 1) {
				if (a[x + 1][y] != '#') {
					x++;
					z = 0;
				}
				else if (a[x][y + 1] != '#')y++;
				else z = 2;
			}
			else if (z == 2) {
				if (a[x][y + 1] != '#') {
					y++;
					z = 1;
				}
				else if (a[x - 1][y] != '#')x--;
				else z = 3;
			}
			else {
				if (a[x - 1][y] != '#') {
					x--;
					z = 2;
				}
				else if (a[x][y - 1] != '#')y--;
				else z = 0;
			}

		}
		if (!ans) {
			printf("NO\n");
			continue;
		}
		f(i, N) {
			f(j, N) {
				f(ii, 4) {
					if (v[i][j][ii]) {
						u[i][j] = true;
						v[i][j][ii] = false;
					}
				}
			}
		}

		//あと1つ

		x = 1;
		y = m - 1;
		z = 3;
		while (true) {
			if (u[x][y]) {
				ans = false;
				break;
			}
			if (v[x][y][z]) {
				ans = false;
				break;
			}
			v[x][y][z] = true;
			if ((x == 1) && (y == 2))break;
			if ((x == 1) && (y == 1))break;
			if (z == 0) {
				if (a[x][y - 1] != '#') {
					y--;
					z = 3;
				}
				else if (a[x + 1][y] != '#')x++;
				else z = 1;
			}
			else if (z == 1) {
				if (a[x + 1][y] != '#') {
					x++;
					z = 0;
				}
				else if (a[x][y + 1] != '#')y++;
				else z = 2;
			}
			else if (z == 2) {
				if (a[x][y + 1] != '#') {
					y++;
					z = 1;
				}
				else if (a[x - 1][y] != '#')x--;
				else z = 3;
			}
			else {
				if (a[x - 1][y] != '#') {
					x--;
					z = 2;
				}
				else if (a[x][y - 1] != '#')y--;
				else z = 0;
			}
		}
		if (!ans) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");

	}

	return 0;
}
