#include <cstdio>
#include <algorithm>
int N, M, count;
char a[8][9];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", a[i]);
		count += std::count(a[i], a[i] + M, '#');
	}
	if (count != N + M - 1 || a[0][0] != '#')
	{
		puts("Impossible");
		return 0;
	}
	for (int x = 0, y = 0; x != N - 1 || y != M - 1; )
		if (x < N - 1 && a[x + 1][y] == '#')
			x++;
		else if (y < M - 1 && a[x][y + 1] == '#')
			y++;
		else
		{
			puts("Impossible");
			return 0;
		}
	puts("Possible");
	return 0;
}
