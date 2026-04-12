#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>
int main() {
	char a[200][200];
	char b[200][200];
	char c[200][200];
	bool check = false;
	int H, W, i, j, y, t;
	//入力
	scanf("%d %d", &H, &W);
	for (i = 0; i < H; i++) {
		for (j = 0; j <= W; j++) {
			scanf("%c", &a[i][j]);
		}
	}

	//
	y = 0;
	for (i = 0; i < H; i++) {
		check = false;
		for (j = 0; j <= W; j++) {
			if (a[i][j] == '#') {
				check = true;
			}
		}
		if (check) {
			for (j = 0; j <= W; j++) {
				b[y][j] = a[i][j];
			}
			y++;
		}
	}

	t = 0;
	for (i = 0; i <= W; i++) {
		check = false;
		for (j = 0; j < y; j++) {
			if (b[j][i] == '#') {
				check = true;
			}
		}
		if (check) {
			for (j = 0; j < y; j++) {
				c[j][t] = b[j][i];
			}
			t++;
		}
	}



	for (i = 0; i < y; i++) {
		c[i][t] = '\n';
	}

	for (i = 0; i < y; i++) {
		for (j = 0; j <= t; j++) {
			printf("%c", c[i][j]);
		}
	}

	return 0;
}
