//============================================================================
// Name        : 0078.cpp
// Author      : afterCmidday
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, x, y, a[15][15];
	while(cin >> n){
		memset(a,0,sizeof(a));
		x = n / 2;
		y = n / 2 + 1;
		a[y][x] = 1;
		for(int i = 0;i < n * n - 1;i++){
			if(a[(y + 1) % n][(x + 1) % n] == 0){
				x = (x + 1) % n;
				y = (y + 1) % n;
			}else{
				y = (y + 2) % n;
			}
			a[y][x] = i + 2;
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}