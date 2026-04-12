#include <cstdio>
using namespace std;

int main()
{
	int H, W;
	scanf("%d %d", &H, &W);
	
	int i, j;
	char a[100][100];
	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++) {
			do {
				a[i][j] = getchar();
			} while (a[i][j] != '#' && a[i][j] != '.');
		}

	bool exRow[100] = { 0 }, exCol[100] = { 0 };

	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++)
			if (a[i][j] == '#')
				break;

		if (j == W)
			exRow[i]++;
	}

	for (j = 0; j < W; j++) {
		for (i = 0; i < H; i++)
			if (a[i][j] == '#')
				break;

		if (i == H)
			exCol[j]++;
	}

	for (i = 0; i < H; i++)
		if (!exRow[i]) {
			for (j = 0; j < W; j++)
				if (!exCol[j])
					putchar(a[i][j]);

			putchar('\n');
		}

	return 0;
}