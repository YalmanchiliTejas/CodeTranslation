#include <cstdio>
#include <cstdlib>
using namespace std;

int r, c;
bool bio[10][10];
char s[10][10];

void dfs( int x, int y ){
	
	if ( y == c ) return;
	bio[x][y] = true;
	if ( x && s[x-1][y] == '#' && y && s[x][y-1] == '#' ){
		printf("Impossible\n");
		exit(0);
	}
	if ( x + 1 < r && s[x+1][y] == '#' && y + 1 < c && s[x][y+1] == '#' ){
		printf("Impossible\n");
		exit(0);
	}
	
	if ( x + 1 < r && s[x+1][y] == '#' ) dfs(x + 1, y);
	else dfs(x, y + 1);
	
}

int main(){
	
	scanf("%d %d", &r, &c);
	for ( int i = 0; i < r; i++ )
		scanf("%s", s[i]);
	dfs(0, 0);
	printf("Possible\n");
	
	return 0;
}
