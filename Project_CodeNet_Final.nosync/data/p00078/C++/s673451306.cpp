#include <iostream>
#include <cstdio>

using namespace std;
#define rep2(x,from,to) for(int x = (from); x < (to); ++(x))
#define rep(x,to) rep2(x,0,to)
int main() {
	int n;
	while(cin >> n, n) {
		int board[15][15] = {};
		board[n/2+1][n/2] = 1;
		int y = n/2+1, x = n/2;
		rep2(i,2,n*n+1) {
			y = (y+1)%n, x = (x+1)%n;
			if(board[y][x]) {
				do {
					y = (y+1)%n, x = (n+x-1)%n;
				} while(board[y][x]);
			}
			board[y][x] = i;
		}
		rep(i,n) {
			rep(j,n) {
				printf("%4d",board[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}