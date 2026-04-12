#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 11

int POW[SIZE];
int N,K;
ll dp[205][SIZE][SIZE][1024]; //dp[最後に処理した数][最後に処理した数-左下の数][左下の数-その上の数][上の行の状態] = 場合の数
ll M;

int calc_state(int base_number,int work[2][SIZE]){

	int base_col = 0;
	if(work[1][1] != 0){

		base_col = 1;
	}

	int ret = 0;

	for(int col = base_col+1; col <= K; col++){
		if(work[0][col] == 0)break;

		ret += POW[base_number-work[0][col]];
	}

	return ret;
}

ll recursive(int last_number,int left_under_diff,int left_vertical_diff,int top_state){

	if(dp[last_number][left_under_diff][left_vertical_diff][top_state] != -1){

		return dp[last_number][left_under_diff][left_vertical_diff][top_state];
	}

	int work[2][SIZE];

	for(int row = 0; row < 2; row++){
		for(int col = 0; col < SIZE; col++){
			work[row][col] = 0;
		}
	}

	//左下の数
	int left_under = last_number-left_under_diff;
	work[1][0] = left_under;
	//その上の数
	work[0][0] = left_under-left_vertical_diff;

	//状態の復元
	int top_index = 0;
	for(int diff = (K-1); diff >= 0; diff--){

		if(top_state & (1 << (diff))){

			work[0][1+top_index++] = last_number-diff;
		}
	}

	if(last_number == 2*N){

		if(left_under == 2*N && top_index == 0){

			return 1;
		}else{

			return 0;
		}
	}

	ll ret = 0;

	bool FLG = true;

	//左下更新
	if(top_index == 0){ //上段の列数==下段の列数

		if(work[0][0] != 0 && last_number+1-work[0][0] > K){

			FLG = false;
		}

	}else{
		if(left_under == 0){

			work[1][1] = last_number+1;
			int next_state = calc_state(last_number+1,work);
			if(next_state >= POW[K]){

				//BUG

			}else{
				ret = recursive(last_number+1,0,work[1][1]-work[0][1],next_state);
				work[1][1] = 0;
			}

		}else{

			int tmp = min(work[1][0],work[0][1]);
			if((last_number+1)-tmp > K){

				FLG = false; //差がKより大きくなるので不可
			}else{

				work[1][1] = last_number+1;
				int next_state = calc_state(last_number+1,work);
				if(next_state >= POW[K]){

					//BUG

				}else{
					ret = recursive(last_number+1,0,work[1][1]-work[0][1],next_state);
					work[1][1] = 0;
				}
			}
		}
	}

	//上の行の右端更新
	if(FLG == true && top_index <= K-1 && (last_number+1-work[0][top_index] <= K)){

		work[0][1+top_index] = last_number+1;

		int next_state = calc_state(last_number+1,work);
		if(next_state >= POW[K]){

			//BUG

		}else{

			ret += recursive(last_number+1,last_number+1-left_under,left_vertical_diff,next_state);
			ret %= M;
		}
	}

	return dp[last_number][left_under_diff][left_vertical_diff][top_state] = ret;
}

int main(){

	POW[0] = 1;
	for(int i = 1; i < SIZE; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d %d %lld",&N,&K,&M);

	for(int num = 0; num <= 2*N; num++){
		for(int diff = 0; diff <= K; diff++){
			for(int diff_2 = 0; diff_2 <= K; diff_2++){
				for(int state = 0; state < POW[K]; state++){

					dp[num][diff][diff_2][state] = -1;
				}
			}
		}
	}

	printf("%lld\n",recursive(0,0,0,0)%M);

	return 0;
}

