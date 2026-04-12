#include <bits/stdc++.h>
#define maxn 105 
using namespace std;
int d[maxn][maxn];
int D[maxn][maxn];
int f[maxn][maxn]; 
int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	for(int i = 1; i <= A; ++i) for(int j = 1; j <= B; ++j) scanf("%d", d[i] + j);
	for(int a = 0; a <= 100; ++a) {
		for(int b = 0; b <= 100; ++b) {
			for(int x = 1; x <= A; ++x) {
				for(int y = 1; y <= B; ++y) {
					f[a][b] = max(f[a][b], d[x][y] - x * a - y * b);
				}
			}
		}
	}
	memset(D, 0x3f, sizeof D);
	for(int x = 1; x <= A; ++x) {
		for(int y = 1; y <= B; ++y) {
			for(int a = 0; a <= 100; ++a) {
				for(int b = 0; b <= 100; ++b) {
					D[x][y] = min(D[x][y], x * a + y * b + f[a][b]);
				}
			}
		}
	}
	bool same = true;
	for(int x = 1; x <= A; ++x) 
		for(int y = 1; y <= B; ++y) 
			if(D[x][y] != d[x][y]) same = false;
	puts(same ? "Possible" : "Impossible");
	if(same) {
		puts("202 10401");
		for(int i = 1; i <= 100; ++i) {
			printf("%d %d X\n", i, i + 1);
			printf("%d %d Y\n", i + 101, i + 102);
		}
		for(int a = 0; a <= 100; ++a) 
			for(int b = 0; b <= 100; ++b) 
				printf("%d %d %d\n", a + 1, 202 - b, f[a][b]);
		puts("1 202");
	}
	return 0;
}