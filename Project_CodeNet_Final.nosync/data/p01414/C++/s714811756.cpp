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

struct Info{
	Info(int arg_row1,int arg_row2,int arg_col1,int arg_col2){
		row1 = arg_row1;
		row2 = arg_row2;
		col1 = arg_col1;
		col2 = arg_col2;
	}
	int row1,row2,col1,col2;
};

struct Data{
	bool table[4][4];
	int count;
};

bool can_stamp[4][4][4][4];
bool check[65536];
int POW[17];


int main(){

	for(int i = 0; i <= 16; i++)POW[i] = pow(2,i);

	int N;
	scanf("%d",&N);

	for(int i = 0; i < POW[16]; i++)check[i] = false;

	for(int a = 0; a < 4; a++){
		for(int b = 0; b < 4; b++){
			for(int c = 0; c < 4; c++){
				for(int d = 0; d < 4; d++)can_stamp[a][b][c][d] = false;
			}
		}
	}

	int height,width;
	for(int i = 0; i < N; i++){
		scanf("%d %d",&height,&width);

		for(int row2 = 0; row2 <= 3; row2++){
			int row1 = max(0,row2-height+1);

			for(int col2 = 0; col2 <= 3; col2++){
				int col1 = max(0,col2-width+1);
				can_stamp[row1][row2][col1][col2] = true;
			}
			for(int col1 = 0; col1 <= 3; col1++){
				int col2 = min(3,col1+width-1);
				can_stamp[row1][row2][col1][col2] = true;
			}
		}

		for(int row1 = 0; row1 <= 3; row1++){
			int row2 = min(3,row1+height-1);

			for(int col2 = 0; col2 <= 3; col2++){
				int col1 = max(0,col2-width+1);
				can_stamp[row1][row2][col1][col2] = true;
			}
			for(int col1 = 0; col1 <= 3; col1++){
				int col2 = min(3,col1+width-1);
				can_stamp[row1][row2][col1][col2] = true;
			}
		}
	}

	vector<Info> V;

	for(int a = 0; a < 4; a++){
		for(int b = 0; b < 4; b++){
			for(int c = 0; c < 4; c++){
				for(int d = 0; d < 4; d++){
					if(can_stamp[a][b][c][d]){
						V.push_back(Info(a,b,c,d));
					}
				}
			}
		}
	}


	char ans_table[4][5];
	for(int row = 0; row < 4; row++){
		scanf("%s",ans_table[row]);
	}

	Data first;
	first.count = 0;
	for(int row = 0; row < 4; row++){
		for(int col = 0; col < 4; col++)first.table[row][col] = false;
	}
	check[0] = true;

	queue<Data> Q;
	Q.push(first);

	bool FLG;
	char base[4][4],work[4][4];
	bool not_color[3];

	int index,tmp_code;

	char colors[3] = {'R','G','B'};

	while(!Q.empty()){

		FLG = true;
		for(int row = 0; row < 4; row++){
			for(int col = 0; col < 4; col++){
				if(Q.front().table[row][col] == false){
					FLG = false;
					base[row][col] = '@';
				}else{
					base[row][col] = ans_table[row][col];
				}
			}
		}

		if(FLG){
			printf("%d\n",Q.front().count);
			return 0;
		}

		for(int i = 0; i < V.size(); i++){

			for(int k = 0; k < 3; k++)not_color[k] = false;

			FLG = true;
			for(int row = V[i].row1; row <= V[i].row2; row++){
				for(int col = V[i].col1; col <= V[i].col2; col++){
					if(Q.front().table[row][col] == false){
						FLG = false;
						switch(ans_table[row][col]){
						case 'R':
							not_color[0] = true;
							break;
						case 'G':
							not_color[1] = true;
							break;
						case 'B':
							not_color[2] = true;
							break;
						}
					}
				}
			}

			if(FLG)continue;

			for(int paint = 0; paint < 3; paint++){
				if(not_color[paint] == false)continue;

				for(int row = 0; row < 4; row++){
					for(int col = 0; col < 4; col++){
						work[row][col] = base[row][col];
					}
				}

				for(int row = V[i].row1; row <= V[i].row2; row++){
					for(int col = V[i].col1; col <= V[i].col2; col++){
						work[row][col] = colors[paint];
					}
				}

				index = 0,tmp_code = 0;
				Data next_data;
				for(int row = 0; row < 4; row++){
					for(int col = 0; col < 4; col++){
						if(work[row][col] == ans_table[row][col]){
							tmp_code += POW[index];
							next_data.table[row][col] = true;
						}else{
							next_data.table[row][col] = false;
						}
						index++;
					}
				}

				if(check[tmp_code])continue;

				check[tmp_code] = true;
				next_data.count = Q.front().count+1;
				Q.push(next_data);
			}
		}
		Q.pop();
	}
	return 0;
}