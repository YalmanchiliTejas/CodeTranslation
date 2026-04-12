/*
	0078:Magic Square
*/
#include	<iostream>
#include	<cstdio>

using namespace std;

int main(void) {
	while(1) {
		unsigned int array[15][15] = { 0 };
		int border, sx, sy, c = 1;
		
		cin >> border;
		if(border == 0) { break; }
		sx = border/2;	sy = border/2 + 1;
		while(c <= border*border) {
			int nx = (sx+1) % border, ny = (sy+1) % border;
			array[sx][sy] = c;
			if(array[nx][ny] != 0) {
				nx = sx;	ny = (sy+2) % border;
			}
			sx = nx;	sy = ny;
			c++;
		}
		
		for(int i = 0; i < border; i++) {
			for(int j = 0; j < border; j++) {
				printf("%4d", array[j][i]);
			}
			putchar('\n');
		}
		
	}
	return 0;
}