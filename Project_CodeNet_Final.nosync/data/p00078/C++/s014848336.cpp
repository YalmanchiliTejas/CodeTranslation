#include <iostream>
#include <cstdio>
#include <cstring>

int main(){
	int n, square[15][15], count = 0;
	while(std::cin >> n, n){
		count = 0;
		memset(square, 0, sizeof(square));

		int x = n/2, y = n/2+1;
		square[y][x] = ++count;
		while(count != n*n){
			x++, y++;
			while(x < 0 || x >= n || y < 0 || y >= n || square[y][x] != 0){
				if(x >= n)x = 0;
				if(x < 0)x = n-1;
				if(y >= n)y = 0;
				if(square[y][x])x--, y++;
			}
			square[y][x] = ++count;
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%4d", square[i][j]);
			}
			puts("");
		}
	}
}