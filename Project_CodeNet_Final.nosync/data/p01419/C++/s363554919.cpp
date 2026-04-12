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

struct Info{
	Info(int arg_row,int arg_col,int arg_time){
		row = arg_row;
		col = arg_col;
		time = arg_time;
	}

	int row,col,time;
};

struct Data{
	int row,col,move_num;
	vector<Info> tmp;
};

int H,W,M,cost[50][50],to_on[50][50],to_off[50][50],sche[1000][2],minCost[50][50];
int diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0};
char map[50][51];

bool rangeCheck(int row,int col){
	if(row >= 0 && row <= H-1 && col >= 0 && col <= W-1)return true;
	else{
		return false;
	}
}

int main(){

	scanf("%d %d %d",&H,&W,&M);
	for(int i = 0; i < H; i++){
		scanf("%s",map[i]);
	}

	for(int i = 0; i < H; i++){
		for(int k = 0; k < W; k++)scanf("%d",&cost[i][k]);
	}

	for(int i = 0; i < H; i++){
		for(int k = 0; k < W; k++)scanf("%d",&to_on[i][k]);
	}

	for(int i = 0; i < H; i++){
		for(int k = 0; k < W; k++)scanf("%d",&to_off[i][k]);
	}

	for(int i = 0; i < M; i++){
		scanf("%d %d",&sche[i][0],&sche[i][1]);
	}

	vector<Info> V;
	V.push_back(Info(sche[0][0],sche[0][1],0));

	int start_row,start_col,goal_row,goal_col;
	int time = 1,next_row,next_col;

	queue<Data> D;

	for(int i = 0; i < M-1; i++){

		start_row = sche[i][0];
		start_col = sche[i][1];
		goal_row = sche[i+1][0];
		goal_col = sche[i+1][1];

		while(!D.empty())D.pop();
		Data first;
		first.row = start_row;
		first.col = start_col;
		first.tmp.push_back(Info(start_row,start_col,0));
		first.move_num = 0;

		for(int a = 0; a < H; a++){
			for(int b = 0; b < W; b++)minCost[a][b] = BIG_NUM;
		}

		minCost[start_row][start_col] = 0;

		D.push(first);

		while(!D.empty()){

			if(D.front().row == goal_row && D.front().col == goal_col){
				for(int a = 1; a < D.front().tmp.size();a++){ //start+1???goal?????§???V???push
					V.push_back(Info(D.front().tmp[a].row,D.front().tmp[a].col,time++));
				}
				break;
			}else if(D.front().move_num > minCost[D.front().row][D.front().col]){
				D.pop();
			}else{

				for(int a = 0; a < 4; a++){
					next_row = D.front().row + diff_row[a];
					next_col = D.front().col + diff_col[a];

					if(rangeCheck(next_row,next_col) == true && map[next_row][next_col] != '#' && minCost[next_row][next_col] > D.front().move_num+1){
						minCost[next_row][next_col] = D.front().move_num+1;
						Data new_data;
						for(int b = 0; b < D.front().tmp.size();b++){
							new_data.tmp.push_back(D.front().tmp[b]);
						}
						new_data.tmp.push_back(Info(next_row,next_col,0));
						new_data.row = next_row;
						new_data.col = next_col;
						new_data.move_num = D.front().move_num+1;
						D.push(new_data);
					}
				}
				D.pop();
			}
		}
	}

	bool check[50][50];
	for(int i = 0; i < H; i++){
		for(int k = 0; k < W; k++)check[i][k] = false;
	}


	int ans = 0;

	bool FLG;
    int	next_time;

	for(int i = 0; i < V.size(); i++){

		if(check[V[i].row][V[i].col] == false){
			ans += to_on[V[i].row][V[i].col];
			check[V[i].row][V[i].col] = true;
		}

		FLG = false;
		for(int k = i+1; k < V.size();k++){
			if(V[k].row == V[i].row && V[k].col == V[i].col){
				next_time = V[k].time;
				FLG = true;
				break;
			}
		}


		if(!FLG){
			ans += to_off[V[i].row][V[i].col];
			check[V[i].row][V[i].col] = false;
		}else{
			if(cost[V[i].row][V[i].col]*(next_time-V[i].time) <= to_off[V[i].row][V[i].col]+to_on[V[i].row][V[i].col]){
				ans += cost[V[i].row][V[i].col]*(next_time-V[i].time);
			}else{
				ans += to_off[V[i].row][V[i].col];
				check[V[i].row][V[i].col] = false;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}