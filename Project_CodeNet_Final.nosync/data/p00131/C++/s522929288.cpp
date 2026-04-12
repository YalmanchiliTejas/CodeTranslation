#include<bits/stdc++.h>
using namespace std;

int c[10][10];
int f[10][10];
bool s[10][10];
int hanten[2] = { 1,0 };
int dx[5] = { -1,0,0,1,0 }, dy[5] = { 0,-1,1,0,0 };
int main() {
	int a; cin >> a;
	for (int b = 0; b < a; b++) {
		for (int d = 0; d < 10; d++) {
			for (int e = 0; e < 10; e++) {
				scanf("%d",&c[d][e]);
			}
		}
		for (int g = 0; g < 1024; g++) {
			memset(s, 0, sizeof(s));
			for (int h = 0; h < 10; h++) {
				for (int i = 0; i < 10; i++) {
					f[h][i] = c[h][i];
				}
			}
			for (int h = 0; h < 10; h++) {
				if (g & (1 << h)) {
					s[0][h] = true;
					for (int i = 0; i < 5; i++) {
						int x = dx[i], y = h + dy[i];
						if (x >= 0 && x < 10 && y >= 0 && y < 10) {
							f[x][y] = hanten[f[x][y]];
						}
					}
				}
			}
			for (int h = 1; h < 10; h++) {
				for (int i = 0; i < 10; i++) {
					if (f[h - 1][i]) {
						s[h][i] = true;
						for (int j = 0; j < 5; j++) {
							int x = h+dx[j], y = i + dy[j];
							if (x >= 0 && x < 10 && y >= 0 && y < 10) {
								f[x][y] = hanten[f[x][y]];
							}
						}
					}
				}
			}
			bool K = true;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (f[i][j])K = false;
				}
			}
			if (K) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (j)cout << " ";
						cout << s[i][j];
					}
					cout << endl;
				}
			}
		}
	}
}