#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[11][11], v[11][11];
int A, B;
struct Edge {
	int a, b, c;
}E[10100];
int cnt;
int main() {
	int i, j, k, l;
	scanf("%d%d", &A, &B);
	for (i = 1; i <= 100; i++) {
		E[cnt++] = { i,i + 1,-2 };
	}
	for (i = 102; i < 202; i++) {
		E[cnt++] = { i,i + 1,-1 };
	}
	for (i = 1; i <= A; i++)for (j = 1; j <= B; j++)scanf("%d", &w[i][j]);
	for (i = 0; i <= 100; i++)for (j = 0; i + j <= 100; j++){
		int Mx = 0;
		for (k = 1; k <= A; k++) {
			for (l = 1; l <= B; l++) {
				Mx = max(Mx, w[k][l] - i*k - j*l);
			}
		}
		if (Mx < 0)continue;
		int chk = 0;
		for (k = 1; k <= A; k++) {
			for (l = 1; l <= B; l++) {
				if (w[k][l] == i*k + j*l + Mx && !v[k][l])chk = 1, v[k][l] = 1;
			}
		}
		if (!chk)continue;
		E[cnt++] = { i + 1, 202 - j, Mx };
	}
	for (i = 1; i <= A; i++)for (j = 1; j <= B; j++)if (!v[i][j]) {
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	printf("%d %d\n", 202, cnt);
	for (i = 0; i < cnt; i++) {
		printf("%d %d ", E[i].a, E[i].b);
		if (E[i].c < 0)printf("%c\n", E[i].c + 'Z');
		else printf("%d\n", E[i].c);
	}
	printf("%d %d\n", 1, 202);
}