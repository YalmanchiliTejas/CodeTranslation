#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


struct Data{
	Data(int arg_row,int arg_col){
		row = arg_row;
		col = arg_col;
	}
	int row,col;
};


int N;
int table[15][15],work[15][15],diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0};

bool rangeCheck(int row,int col){
	if(row >= 0 && row <= N-1 && col >= 0 && col <= N-1)return true;
	else{
		return false;
	}
}

int main(){

	int M;
	scanf("%d %d",&N,&M);

	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++)scanf("%d",&table[row][col]);
	}

	int command,r,c,size,angle,left,right,pre_value;
	int adj_row,adj_col;
	queue<Data> Q;

	for(int loop = 0; loop < M; loop++){
		scanf("%d",&command);

		switch(command){
		case 0:
			scanf("%d %d %d %d",&r,&c,&size,&angle);
			r--;
			c--;

			switch(angle){
			case 90:
				for(int row_diff = 0; row_diff < size; row_diff++){
					for(int col_diff = 0; col_diff < size; col_diff++){
						work[r+col_diff][c+(size-1)-row_diff] = table[r+row_diff][c+col_diff];
					}
				}
				break;
			case 180:
				for(int row_diff = 0; row_diff < size; row_diff++){
					for(int col_diff = 0; col_diff < size; col_diff++){
						work[r+size-1-row_diff][c+size-1-col_diff] = table[r+row_diff][c+col_diff];
					}
				}
				break;
			case 270:
				for(int row_diff = 0; row_diff < size; row_diff++){
					for(int col_diff = 0; col_diff < size; col_diff++){
						work[r+(size-1)-col_diff][c+row_diff] = table[r+row_diff][c+col_diff];
					}
				}
				break;
			default: //0,360
				for(int row_diff = 0; row_diff < size; row_diff++){
					for(int col_diff = 0; col_diff < size; col_diff++){
						work[r+row_diff][c+col_diff] = table[r+row_diff][c+col_diff];
					}
				}
				break;
			}

			for(int row_diff = 0; row_diff < size; row_diff++){
				for(int col_diff = 0; col_diff < size; col_diff++){
					table[r+row_diff][c+col_diff] = work[r+row_diff][c+col_diff];
				}
			}
			break;
		case 1:
			scanf("%d %d %d",&r,&c,&size);
			r--;
			c--;
			for(int row_diff = 0; row_diff < size; row_diff++){
				for(int col_diff = 0; col_diff < size; col_diff++){
					table[r+row_diff][c+col_diff] = 1-table[r+row_diff][c+col_diff];
				}
			}
			break;
		case 2:
			scanf("%d",&r);
			r--;
			left = table[r][0];
			for(int col = 1; col < N; col++){
				table[r][col-1] = table[r][col];
			}
			table[r][N-1] = left;
			break;
		case 3:
			scanf("%d",&r);
			r--;
			right = table[r][N-1];
			for(int col = N-2; col >= 0; col--){
				table[r][col+1] = table[r][col];
			}
			table[r][0] = right;
			break;
		case 4:
			scanf("%d %d",&r,&c);
			r--;
			c--;
			pre_value = table[r][c];
			Q.push(Data(r,c));

			while(!Q.empty()){

				if(table[Q.front().row][Q.front().col] != pre_value){
					Q.pop();
					continue;
				}

				table[Q.front().row][Q.front().col] = 1-table[Q.front().row][Q.front().col];

				for(int i = 0; i < 4; i++){
					adj_row = Q.front().row+diff_row[i];
					adj_col = Q.front().col+diff_col[i];

					if(!rangeCheck(adj_row,adj_col))continue;

					if(table[adj_row][adj_col] == pre_value){
						Q.push(Data(adj_row,adj_col));
					}
				}
				Q.pop();
			}
			break;
		}

	}

	for(int row = 0; row < N; row++){
		printf("%d",table[row][0]);
		for(int col = 1; col < N; col++){
			printf(" %d",table[row][col]);
		}
		printf("\n");
	}

	return 0;
}