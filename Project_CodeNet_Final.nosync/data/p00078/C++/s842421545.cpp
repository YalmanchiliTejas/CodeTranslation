#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int m, x, y;
int check(int a[15][15]){
	int f = 1;
	if(x == m)x -= m, f = 0;
	if(y == m)y -= m, f = 0;
	if(x == -1)x = m-1, f = 0;
	if(a[y][x]){x--;y++;f = 0;}
	if(f)return 0;
	check(a);
}

int func(int a[15][15], int n){
	a[y][x] = n;
	x++;y++;
	int f = 0;
	for(int i = 0;i < m;i++)
	for(int j = 0;j < m;j++)if(!a[i][j])f = 1;
	if(!f)return 0;
	check(a);
	func(a, n+1);
}

int main(){
	int a[15][15];
	while(scanf("%d", &m)){
		if(!m)break;
		fill((int*)a, (int*)(a+15), 0);
		x =  m/2, y = m/2+1;
		func(a, 1);
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++)printf("%4d", a[i][j]);
			puts("");
		}
	}
	return 0;
}