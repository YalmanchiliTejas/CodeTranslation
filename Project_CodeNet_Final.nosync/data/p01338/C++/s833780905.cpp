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


int table[5][5],push_table[256][4];
int dp[3125],next_dp[3125];
int index = 0,push_index = 0;
map<int,int>MAP,rev_MAP;


int makeNUM(int array[5]){
	return 10000*array[0]+1000*array[1]+100*array[2]+10*array[3]+array[4];
}

int getPoint(int num){

	switch(num){
	case 0:return 0;
	case 1:return 0;
	case 2:return 60;
	case 3:return 70;
	case 4:return 80;
	}
	return -1;//must not reach here
}


void func(){

	for(int row = 0; row < 5; row++){
		for(int col = 0; col < 5; col++)scanf("%d",&table[row][col]);
	}

	int work[2][5];

	for(int i = 0; i < 3125; i++)dp[i] = -1;


	int sum,code;

	for(int i = 0; i < 256; i++){
		for(int a = 0; a < 2; a++){
			for(int b = 0; b < 5; b++)work[a][b] = table[a][b];
		}

		for(int k = 0; k < 4; k++){
			if(work[0][k] != 0){
				work[0][k] += push_table[i][k];
				if(work[0][k] > 4)work[0][k] -= 4;
			}
			if(work[0][k+1] != 0){
				work[0][k+1] += push_table[i][k];
				if(work[0][k+1] > 4)work[0][k+1] -= 4;
			}
			if(work[1][k] != 0){
				work[1][k] += push_table[i][k];
				if(work[1][k] > 4)work[1][k] -= 4;
			}
			if(work[1][k+1] != 0){
				work[1][k+1] += push_table[i][k];
				if(work[1][k+1] > 4)work[1][k+1] -= 4;
			}
		}
		sum = 0;
		for(int k = 0; k < 5; k++)sum += getPoint(work[0][k]);
		code = MAP[makeNUM(work[1])];
		dp[code] = max(dp[code],sum);
	}


	int number,tmp;
	int ans = 0;

	for(int row = 1; row <= 3; row++){

		for(int state = 0; state < 3125; state++)next_dp[state] = -1;

		for(int pre_state = 0; pre_state < 3125; pre_state++){
			if(dp[pre_state] == -1)continue;

			number = rev_MAP[pre_state];

			for(int i = 0; i < 256; i++){
				tmp = number;
				for(int k = 0; k < 5; k++){
					work[0][4-k] = tmp%10;
					tmp /= 10;
				}

				for(int k = 0; k < 5; k++){
					work[1][k] = table[row+1][k];
				}

				for(int k = 0; k < 4; k++){
					if(work[0][k] != 0){
						work[0][k] += push_table[i][k];
						if(work[0][k] > 4)work[0][k] -= 4;
					}
					if(work[0][k+1] != 0){
						work[0][k+1] += push_table[i][k];
						if(work[0][k+1] > 4)work[0][k+1] -= 4;
					}
					if(work[1][k] != 0){
						work[1][k] += push_table[i][k];
						if(work[1][k] > 4)work[1][k] -= 4;
					}
					if(work[1][k+1] != 0){
						work[1][k+1] += push_table[i][k];
						if(work[1][k+1] > 4)work[1][k+1] -= 4;
					}
				}
				sum = 0;
				for(int k = 0; k < 5; k++)sum += getPoint(work[0][k]);

				if(row <= 2){
					code = MAP[makeNUM(work[1])];

					next_dp[code] = max(next_dp[code],sum+dp[pre_state]);

				}else{
					for(int k = 0; k < 5; k++)sum += getPoint(work[1][k]);
					ans = max(ans,sum+dp[pre_state]);
				}
			}
		}

		for(int state = 0; state < 3125; state++)dp[state] = next_dp[state];
	}

	printf("%d\n",ans);
}


void recursive(int array[5],int count){

	if(count == 5){
		int new_num = makeNUM(array);
		MAP[new_num] = index;
		rev_MAP[index] = new_num;
		index++;
		return;
	}

	for(int i = 0; i <= 4; i++){
		int next_array[5];
		for(int k = 0; k < count; k++)next_array[k] = array[k];
		next_array[count] = i;
		recursive(next_array,count+1);
	}
}

void makeCode(){
	int first_array[5];
	recursive(first_array,0);
}


void makePush(int array[4],int count){

	if(count == 4){
		for(int i = 0; i < 4; i++){
			push_table[push_index][i] = array[i];
		}
		push_index++;
		return;
	}

	for(int i = 0; i <= 3; i++){
		int next_array[4];
		for(int k = 0; k < count; k++)next_array[k] = array[k];
		next_array[count] = i;
		makePush(next_array,count+1);
	}
}

int main(){

	makeCode();

	int first_array[4];
	makePush(first_array,0);

	int case_num;
	scanf("%d",&case_num);

	for(int i = 0; i < case_num; i++)func();

	return 0;
}