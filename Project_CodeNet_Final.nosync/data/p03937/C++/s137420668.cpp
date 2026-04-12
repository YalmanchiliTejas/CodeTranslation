#include <stdio.h>

int H, W;
char a[10][10];
int x = 0, y = 0;
bool ans = true;

int main(void) {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) { scanf("%s", &a[i]); }

	while (true) {
		if (x == H - 1 && y == W - 1) { a[x][y] = '.'; break; }
		if (a[x][y] == '#'&&a[x][y + 1] == '#') { a[x][y] = '.'; y++; }
		else if (a[x][y] == '#'&&a[x + 1][y] == '#') { a[x][y] = '.'; x++; }
		else { ans = false; break; }
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (a[i][j] == '#') { ans = false; }
		}
	}
	if (ans == true) { printf("Possible\n"); }
	else { printf("Impossible"); }
	return 0;
}