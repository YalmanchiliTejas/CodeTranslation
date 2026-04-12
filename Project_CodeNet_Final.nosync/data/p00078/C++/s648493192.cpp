#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		int mahoujin[17][17] = {0};
		int count = 1;
		int x,y;
		x = n/2+1;
		y = n/2+2;
		int limit;
		limit = n * n;
		mahoujin[x][y] = 1;
		count++;
		while (count <= limit) {
			x++;
			y++;
			bool hantei = true;
			while (hantei) {
				if (x > n) {
					x = 1;
				} else if (x < 1) {
					x = n;
				} else if (y > n) {
					y = 1;
				} else if (mahoujin[x][y] != 0) {
					x--;
					y++;
				}
				if (x < 1 || n < x || n < y || mahoujin[x][y] != 0) {
				} else {
					mahoujin[x][y] = count;
					count++;
					hantei = false;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%4d", mahoujin[j][i]);
			}
			cout << endl;
		}
	}
	return 0;
}