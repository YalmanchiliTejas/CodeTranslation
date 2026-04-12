#include<iostream>
#include<stdio.h>
using namespace std;

static const int MAX = 15;

int n;
int M[MAX][MAX];

void magic(int y,int x, int tmp){
	if (tmp > (n * n)) {
		return;
	}
	if (x < 0) {
		magic(y, n-1 , tmp);
	}
	else if (x >= n) {
		magic(y, 0, tmp);
	}
	else if (y >= n) {
		magic(0, x, tmp);
	}
	else if (M[y][x] != -1) {
		magic(y+1, x-1, tmp);
	}
	else {
		M[y][x] = tmp;
		magic(y + 1, x + 1, tmp + 1);
	}

}

int main() {
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				M[i][j] = -1;
			}
		}
		M[(n - 1) / 2+1][(n - 1) / 2]=1;
		magic((n - 1) / 2+2 , (n - 1) / 2 + 1, 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%4d", M[i][j]);
			}
			printf("\n");
		}
	}
}
