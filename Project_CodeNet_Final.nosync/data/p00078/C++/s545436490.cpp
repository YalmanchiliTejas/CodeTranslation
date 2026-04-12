#include <cstdio>
#include <cstring>
using namespace std;
int square[15][15];
int main(){
	int n,x,y,count;
	while(scanf("%d",&n)){
		count = 1;
		if(!n) break;
		memset(square,0,sizeof(square));
		x = y = n / 2;
		++y;
		square[y][x] = count++;
		while(count <= (n * n)){
			++x;
			++y;
			if(y >= n) y = 0;
			if(x >= n) x = 0;
			if(x < 0) x = n - 1;
			if(y < 0) y = n - 1;
			if(square[y][x] == 0) 
				square[y][x] = count;
			else {
				--x;
				++y;
				while(x < 0 || n <= x || y < 0 || n <= y){
					if(y >= n) y = 0;
					if(x >= n) x = 0;
					if(x < 0) x = n - 1;
					if(y < 0) y = n - 1;
				}
				square[y][x] = count;
			}
			++count;
		}
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				printf("%4d",square[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}