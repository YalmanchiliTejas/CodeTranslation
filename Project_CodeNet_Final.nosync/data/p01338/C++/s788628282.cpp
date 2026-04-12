#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int POW[5];
int table[5][5];
int dp[2][256];

void func(){

	for(int row = 0; row < 5; row++){
		for(int col = 0; col < 5; col++){
			scanf("%d",&table[row][col]);
		}
	}

	int CURRENT = 0,NEXT = 1;
	for(int state = 0; state < POW[4]; state++){

		dp[CURRENT][state] = -BIG_NUM;
		dp[NEXT][state] = -BIG_NUM;
	}


	int work[5],work2[5];

	//1行目を計算
	for(int state = 0; state < POW[4]; state++){

		for(int i = 0; i < 5; i++){

			work[i] = table[0][i];
		}

		int tmp = state;

		for(int i = 0; i <= 3; i++){

			int add = tmp/POW[3-i];

			if(work[i] != 0){
				work[i] += add;
				if(work[i] >= 5){

					work[i] -= 4;
				}
			}

			if(work[i+1] != 0){
				work[i+1] += add;
				if(work[i+1] >= 5){

					work[i+1] -= 4;
				}
			}
			tmp %= POW[3-i];
		}

		int sum = 0;
		for(int i = 0; i < 5; i++){
			switch(work[i]){
			case 0:
			case 1:
				//Do nothing
				break;
			case 2:
				sum += 60;
				break;
			case 3:
				sum += 70;
				break;
			case 4:
				sum += 80;
				break;
			}
		}
		dp[CURRENT][state] = sum;
	}

	int ans = 0;

	for(int row = 1; row <= 4; row++){
		for(int pre = 0; pre < POW[4]; pre++){
			if(dp[CURRENT][pre] == -BIG_NUM)continue;

			for(int i = 0; i < 5; i++){

				work[i] = table[row][i];
			}

			int tmp = pre;

			for(int i = 0; i <= 3; i++){

				int add = tmp/POW[3-i];

				if(work[i] != 0){
					work[i] += add;
					if(work[i] >= 5){

						work[i] -= 4;
					}
				}

				if(work[i+1] != 0){
					work[i+1] += add;
					if(work[i+1] >= 5){

						work[i+1] -= 4;
					}
				}
				tmp %= POW[3-i];
			}

			int sum = 0;
			for(int i = 0; i < 5; i++){
				switch(work[i]){
				case 0:
				case 1:
					//Do nothing
					break;
				case 2:
					sum += 60;
					break;
				case 3:
					sum += 70;
					break;
				case 4:
					sum += 80;
					break;
				}
			}

			if(row == 4){

				ans = max(ans,dp[CURRENT][pre]+sum);
				continue;
			}

			for(int next = 0; next < POW[4]; next++){

				for(int k = 0; k < 5; k++){

					work2[k] = work[k];
				}

				int tmp2 = next;

				for(int k = 0; k <= 3; k++){

					int add2 = tmp2/POW[3-k];

					if(work2[k] != 0){
						work2[k] += add2;
						if(work2[k] >= 5){

							work2[k] -= 4;
						}
					}

					if(work2[k+1] != 0){
						work2[k+1] += add2;
						if(work2[k+1] >= 5){

							work2[k+1] -= 4;
						}
					}
					tmp2 %= POW[3-k];
				}

				int sum2 = 0;
				for(int k = 0; k < 5; k++){
					switch(work2[k]){
					case 0:
					case 1:
						//Do nothing
						break;
					case 2:
						sum2 += 60;
						break;
					case 3:
						sum2 += 70;
						break;
					case 4:
						sum2 += 80;
						break;
					}
				}

				dp[NEXT][next] = max(dp[NEXT][next],dp[CURRENT][pre]+sum2);
			}
		}
		swap(CURRENT,NEXT);
		for(int state = 0; state < POW[4]; state++){

			dp[NEXT][state] = -BIG_NUM;
		}
	}

	printf("%d\n",ans);
}

int main(){

	POW[0] = 1;
	for(int i = 1; i < 5; i++){

		POW[i] = POW[i-1]*4;
	}

	int num_case;
	scanf("%d",&num_case);

	for(int i = 0; i < num_case; i++){

		func();
	}

	return 0;
}

