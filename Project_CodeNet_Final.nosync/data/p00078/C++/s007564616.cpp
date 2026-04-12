#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	while(cin >> n,n){
		int field[20][20] = {{0}};
		int x = n/2,y = n/2+1;
		int cnt = 1;
		while(cnt <= n*n){
			if(x < 0) x = n - 1;
			else if(n <= x) x = 0;
			else if(n <= y) y = 0;
			else if(field[y][x] != 0) x--,y++;
			else{
				field[y][x] = cnt;
				cnt++;
				x++,y++;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%4d",field[i][j]);
			}
			puts("");
		}
	}
	return 0;
}