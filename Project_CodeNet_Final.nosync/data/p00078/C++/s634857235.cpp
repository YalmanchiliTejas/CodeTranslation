#include <iostream>
#include <cstdio>
using namespace std;

#define UNCO if(x >= n){x = 0;}if(x < 0){x = n - 1;}if(y >= n){y = 0;}

int main() {
	int n, a, x, y;

	while (cin >> n) {
		if (n == 0) break;
		int s[15][15] = { 0 };
		a = n * n;
		x = y = n / 2 + 1; x--;
		
		for (int i = 1; i <= a; i++) {
			if (s[y][x] != 0) {
				y++, x--;
				UNCO
				s[y][x] = i;
			}
			else {
				s[y][x] = i;
			}

			y++, x++;
			UNCO
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%4d", s[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}