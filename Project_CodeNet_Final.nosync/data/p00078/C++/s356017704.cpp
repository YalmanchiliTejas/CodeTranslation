#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define range(i,b) rep(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
	int map[16][16];
	int i,j;
	int a,b;
	int n;

	while(cin >> n, n){
		i = 1;
		a = n / 2 + 1;
		b = n / 2;
		int map[15][15] = {{0}};
		while(i <= n * n){
			if(a >= n){
				a = 0;
			}
			if(b >= n){
				b = 0;
			}else if(b < 0){
				b = n - 1;
			}
			if(map[a][b] != 0){
				a++;
				b--;
				continue;
			}
			map[a][b] = i;
			i++; a++; b++;
		}
		range(k,n){
			range(j,n){
				printf("%4d",map[k][j]);
			}
			cout << endl;
		}
	}

}