#include <bits/stdc++.h>
using namespace std;

char A[55][55], B[55][55];

int H, W;

int main() {
	scanf("%d%d", &H, &W);
	for(int i = 1; i <= H; i++) scanf(" %s", A[i]+1);

	for(int i = 1; i <= H; i++)
		fill(B[i]+1, B[i]+W+1, '.');

	for(int y = 1, x = 1; y <= H && x <= W;) {
		B[y][x] = '#';
		if(A[y+1][x] == '#') { B[y+1][x] = '#'; y++; }
		else if(A[y][x+1] == '#') { B[y][x+1] = '#'; x++; }
		else break;
	}

	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) {
		if(A[i][j] != B[i][j]) {
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	return 0;
}