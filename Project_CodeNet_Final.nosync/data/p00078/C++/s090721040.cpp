#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int n;
	while (cin >> n&&n) {
		int** magic_square = new int*[n];
		for (int i = 0; i < n; i++) {
			magic_square[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				magic_square[i][j] = 0;
			}
		}
		magic_square[n / 2 + 1][n / 2] = 1;
		int in_x = n / 2, in_y = n / 2 + 1; int next_num = 2; int in_cnt = 1;
		while (1) {
			if (in_cnt == n*n)break;
			while (1) {
				bool in = false;
				in_x += 1; in_y += 1;
				one_more:
				if (in_x >= n)in_x = 0;
				if (in_y >= n)in_y = 0;
				if (!magic_square[in_y][in_x]) { 
					magic_square[in_y][in_x] = next_num;
					next_num++;
					in = true;
					in_cnt++;
				}
				else {
					in_x -= 1; in_y += 1;
					if (in_x < 0)in_x = n - 1;
					goto one_more;
				}
				if (in)break;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%4d", magic_square[i][j]);
			}
			cout << endl;
		}
	}
}
