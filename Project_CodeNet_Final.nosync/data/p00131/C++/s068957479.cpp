#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD NUM000007
#define EPS 0.0000001
#define NUM 30000
using namespace std;

bool rangeCheck(int row,int col){
	if(row >= 0 && row <= 9 && col >= 0 && col <= 9)return true;
	else{
		return false;
	}
}

int diff_row[5] = {-1,0,0,0,1},diff_col[5] = {0,-1,0,1,0};

int main(){

	int N,table[10][10],work[10][10],calc_row,calc_col;
	bool tmp[10][10],ans[10][10],FLG;
	scanf("%d",&N);

	for(int loop = 0; loop < N; loop++){

		for(int i = 0; i < 10; i++){
			for(int k = 0; k < 10; k++){
				scanf("%d",&table[i][k]);
			}
		}

		for(int i = 0; i < 1024; i++){

			for(int a = 0; a < 10; a++){
				for(int b = 0; b < 10; b++){
					work[a][b] = table[a][b];
				}
			}

			for(int k = 0; k < 10; k++){
				if(i & (1 << k)){
					tmp[0][k] = true;
				}else{
					tmp[0][k] = false;
				}
			}

			for(int a = 0; a < 10; a++){
				if(tmp[0][a]){
					for(int b = 0; b < 5; b++){
						calc_row = 0+diff_row[b];
						calc_col = a+diff_col[b];

						if(rangeCheck(calc_row,calc_col) == true){
							work[calc_row][calc_col] = 1 - work[calc_row][calc_col];
						}
					}
				}
			}

			for(int row = 1; row <= 9; row++){
				for(int col = 0; col <= 9; col++){
					if(work[row-1][col] == 1){
						tmp[row][col] = true;
					}else{
						tmp[row][col] = false;
					}
				}

				for(int a = 0; a <= 9; a++){
					if(tmp[row][a]){
						for(int b = 0; b < 5; b++){
							calc_row = row+diff_row[b];
							calc_col = a+diff_col[b];

							if(rangeCheck(calc_row,calc_col) == true){
								work[calc_row][calc_col] = 1 - work[calc_row][calc_col];
							}
						}
					}
				}

			}

			FLG = true;
			for(int a = 0; a <= 9; a++){
				if(work[9][a] == 1){
					FLG = false;
					break;
				}
			}
			if(FLG){
				for(int a = 0; a < 10; a++){
					for(int b = 0; b < 10; b++)ans[a][b] = tmp[a][b];
				}
				break;
			}

		}

		for(int i = 0; i < 10; i++){
			for(int k = 0; k < 9; k++){
				if(ans[i][k]){
					printf("1 ");
				}else{
					printf("0 ");
				}
			}
			if(ans[i][9]){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}
	}

	return 0;
}