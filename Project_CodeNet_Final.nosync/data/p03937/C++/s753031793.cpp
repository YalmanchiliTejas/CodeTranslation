#include "bits/stdc++.h"
using namespace std;
char s[11][11];
bool vis[11][11];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	int x = 0;
	int y = 0;
	do {
		vis[x][y] = true;
		if(x < n-1 && s[x+1][y] == '#') {
			x += 1;
		} else if (y < m-1 && s[x][y+1] == '#') {
			y += 1;
		} else {
			puts("Impossible");
			exit(0);
		}
	} while (x != n-1 || y != m-1);
	vis[n-1][m-1] = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!vis[i][j] && s[i][j] == '#') {
				puts("Impossible");
				exit(0);
			}
		}
	}
	puts("Possible");
	return 0;
}