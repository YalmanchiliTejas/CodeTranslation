#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void frip(int y, int x, int map[10][10]){
	if(y < 0 || x < 0 || y >= 10 || x >= 10){
		return;
	}else{
		map[y][x] = !map[y][x];
	}
}

void frips(int y, int x, int map[10][10]){
	frip(y - 1, x, map);
	frip(y + 1, x, map);
	frip(y, x, map);
	frip(y, x - 1, map);
	frip(y, x + 1, map);
}

int main(){
	
	int n;
	
	int origin[10][10];
	
	int f_point[10][10];
	
	int map[10][10];
	
	bool checker;
	
	cin >> n;
	
	int N = 10;

	for(int loop = 0; loop < n; loop++){
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> origin[i][j];
			}
		}
		
		for(int i = 0; i < (1 << N); i++){
			
			for(int x = 0; x < N; x++){
				for(int y = 0; y < N; y++){
					map[y][x] = origin[y][x];
					f_point[y][x] = 0;
				}
			}
			
			for (int x = 0; x < N; x++){
				if((i & (1 << (N - x - 1))) != 0){
					frips(0, x, map);
					f_point[0][x] = 1;
				}else{
				}
			}
			
			for(int y = 1; y < N; y++){
				for(int x = 0; x < N; x++){
					if(map[y - 1][x]){
						frips(y, x, map);
						f_point[y][x] = 1;
					}
				}
			}
			
			checker = true;
			
			for(int x = 0; x < N; x++){
				if(map[N - 1][x]){
					checker = false;
					break;
				}
			}
			
			if(checker){
				for(int y = 0; y < N; y++){
					if(f_point[y][0]){
						printf("1");
					}else{
						printf("0");
					}
					for(int x = 1; x < N; x++){
						if(f_point[y][x]){
							printf(" 1");
						}else{
							printf(" 0");
						}
					}
					printf("\n");
				}
			}
		}
	}
	
	return 0;
}