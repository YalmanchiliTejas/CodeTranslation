#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int a[3000][3000];
int cx, cy, cnt;

int main() {
	while (cin >> n) {
		if (n == 0) { break; }
		memset(a, 0, sizeof(a));
		cx = n / 2;
		cy = n / 2 + 1;
		cnt = 1;
		a[cy][cx] = cnt;
		while (cnt < n*n) {
			cnt++;
			if (a[(cy + 1) % n][(cx + 1) % n] == 0) {
				cx = (cx + 1) % n;
				cy = (cy + 1) % n;
				a[cy][cx] = cnt;
			}
			else {
				cy = (cy + 2) % n;
				a[cy][cx] = cnt;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("% 4d", a[i][j]);
			}
			printf("\n");
		}
	}
}