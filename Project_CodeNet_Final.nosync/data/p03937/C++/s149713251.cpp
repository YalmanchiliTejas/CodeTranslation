// program luogu.AT2168 Shik and Stone
#include <iostream>
#include <cstdio>
using namespace std;

int m,n;
char s[101][101];

void init() {
	scanf("%d %d",&m,&n);
	for(int i = 1; i <= m; ++i)
		scanf("%s",s[i]+1);
	s[0][1] = s[1][0] = '#';// ÌØÅÐÆðµã 
}

bool check(int x, int y) {
	if( s[x][y] == '.' ) return false;
	if( s[x+1][y] == '#' && s[x][y+1] == '#' ) return true;
	if( s[x-1][y] != '#' && s[x][y-1] != '#' ) return true;
	return false;
}

int main() {
	init();
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if( check(i,j) ) {
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
	return 0;
}