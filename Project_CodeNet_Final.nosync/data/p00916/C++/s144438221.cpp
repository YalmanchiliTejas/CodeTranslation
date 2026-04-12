#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int W = 2000008,H = 2000008,changed_W,changed_H;
int** map;
int N,x_1,y_1,x_2,y_2,pre,new_num,ans,diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0},next_row,next_col;

int* code_table_X;
int* code_table_Y;


struct Info{
	void set(int arg_left,int arg_right,int arg_top,int arg_bottom){
		left = arg_left;
		right = arg_right;
		top = arg_top;
		bottom = arg_bottom;
	}
	int left,right,top,bottom;
};

struct Data{
	Data(int arg_row,int arg_col){
		row = arg_row;
		col = arg_col;
	}

	int row,col;
};

bool rangeCheck(int row,int col){
	if(row >= 0 && row <= changed_H && col >= 0 && col <= changed_W)return true;
	else{
		return false;
	}
}

void func(){

	Info info[50];

	vector<int> X,Y;

	X.clear();
	Y.clear();

	X.push_back(0);
	Y.push_back(0);
	X.push_back(W);
	Y.push_back(H);

	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d",&x_1,&y_1,&x_2,&y_2);

		x_1++;
		y_1++;
		x_2++;
		y_2++;

		x_1 *= 2;
		y_1 *= 2;
		x_2 *= 2;
		y_2 *= 2;

		info[i].set(x_1,x_2,y_1,y_2);

		X.push_back(x_1);
		X.push_back(x_1-1);
		X.push_back(x_2);
		X.push_back(x_2-1);
		Y.push_back(y_1);
		Y.push_back(y_1-1);
		Y.push_back(y_2);
		Y.push_back(y_2-1);
	}

	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	new_num = 1;
	pre = X[0];

	for(int i = 1; i < X.size(); i++){
		if(pre == X[i]){
			//Do nothing
		}else{
			code_table_X[X[i]] = new_num;
			new_num++;
		}
		pre = X[i];
	}

	new_num = 1;
	pre = Y[0];

	for(int i = 1; i < Y.size(); i++){
		if(pre == Y[i]){
			//Do nothing
		}else{
			code_table_Y[Y[i]] = new_num;
			new_num++;
		}
		pre = Y[i];
	}

	for(int i = 0; i < N; i++){
		info[i].set(code_table_X[info[i].left],code_table_X[info[i].right],code_table_Y[info[i].top],code_table_Y[info[i].bottom]);
	}

	changed_W = code_table_X[W];
	changed_H = code_table_Y[H];

	for(int row = 0; row <= changed_H; row++){
		for(int col = 0; col <= changed_W; col++){
			map[row][col] = 0;
		}
	}

	for(int i = 0; i < N; i++){
		for(int row = info[i].bottom; row <= info[i].top; row++){
			map[row][info[i].left] = 1;
			map[row][info[i].right] = 1;
		}
		for(int col = info[i].left; col <= info[i].right; col++){
			map[info[i].top][col] = 1;
			map[info[i].bottom][col] = 1;
		}
	}

	ans = 0;

	for(int row = 0; row <= changed_H; row++){
		for(int col = 0; col <= changed_W; col++){
			if(map[row][col] == 0){
				map[row][col] = 1;
				ans++;

				queue<Data> Q;

				Q.push(Data(row,col));

				while(!Q.empty()){

					for(int i = 0; i < 4; i++){
						next_row = Q.front().row + diff_row[i];
						next_col = Q.front().col + diff_col[i];

						if(rangeCheck(next_row,next_col) == true && map[next_row][next_col] == 0){
							map[next_row][next_col] = 1;
							Q.push(Data(next_row,next_col));
						}
					}
					Q.pop();
				}
			}
		}
	}
	printf("%d\n",ans);

}


int main(){

	map = new int*[512];
	for(int i = 0; i < 512; i++)map[i] = new int[512];

	code_table_X = new int[2000020];
	code_table_Y = new int[2000020];
	code_table_X[0] = 0;
	code_table_Y[0] = 0;

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}