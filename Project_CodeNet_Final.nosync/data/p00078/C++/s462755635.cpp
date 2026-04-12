#include <iostream>
#include <cstdio>
using namespace std;

#define N 15 //魔法陣の最大サイズ

int main(void) {
	int A[N][N] = {};
	int n;
	
	while(cin >> n) {
		if(n == 0) break;
		
		//初期化
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				A[i][j] = 0;
			}
		}
		
		int i = n / 2 + 1; //1を埋める行
		int j = n / 2; //1を埋める列
		int t = 1; //代入する値
		while(true) {
			A[i][j] = t;
			++t;
			if(t > n*n) break;
			++i;
			++j;
			if(i == n) i = 0;
			if(j == n) j = 0;
			if(A[i][j] != 0) {
				++i;
				--j;
				if(i == n) i = 0;
				if(j < 0) j = n - 1;
			}
		}
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				printf("%4d", A[i][j]);
			}
			cout << endl;
		}
	}
	
	return 0;
}
