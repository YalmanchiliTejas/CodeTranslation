#include<bits/stdc++.h>
using namespace std;

int main() {
	int a[15][15];
	int b;
	while (cin >> b, b) {
		memset(a, -1, sizeof(a));
		int x = b / 2 + 1, y = b / 2;
		a[x][y] = 1;
		for (int c = 2; c <= b * b; c++) {
			x++; y++;
			while (1) {
				if (x >= b)x -= b;
				if (y < 0)y += b;
				if (y >= b)y -= b;
				if (a[x][y] == -1) {
					a[x][y] = c;
					break;
				}
				x++; y--;
			}
		}
		for (int p = 0; p < b; p++) {
			for (int q = 0; q < b; q++) {
				printf("%4d", a[p][q]);
			}
			puts("");
		}
	}
}