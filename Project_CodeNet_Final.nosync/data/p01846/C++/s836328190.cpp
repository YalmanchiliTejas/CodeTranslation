#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef pair<int, int>P;

char f[10][10];
int main() {
	string s;
	while (cin >> s, s != "#") {
		int x = 0, y = 0;
		for (char c : s) {
			if ('1' <= c&&c <= '9') {
				rep(i, c - '0')f[x][y++] = '.';
			}
			else if (c == 'b')f[x][y++] = 'b';
			else {
				x++; y = 0;
			}
		}x++;
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); a--; b--; c--; d--;
		f[a][b] = '.'; f[c][d] = 'b';
		rep(i, x) {
			int cnt = 0;
			rep(j, y) {
				if (f[i][j] == '.')cnt++;
				else {
					if (cnt)printf("%d", cnt);
					printf("b"); cnt = 0;
				}
			}
			if (cnt)printf("%d", cnt);
			if (i != x - 1)printf("/");
		}
		printf("\n");
	}
}