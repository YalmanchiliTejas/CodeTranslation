#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
//#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




#define MOD 998244353
#define SIZE 3005

ll N,S;
ll A[SIZE];
ll dp[SIZE][SIZE][3];


int main(){

	scanf("%lld %lld",&N,&S);

	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= S; k++){
			for(int a = 0; a < 3; a++){

				dp[i][k][a] = 0;
			}
		}
	}

	/*
	 * 0:両方未定
	 * 1:左端決定(初めて足す時に左端が決定する)
	 * 2:両方決定(足し終わるまで右端は確定しない)
	 * */

	dp[0][0][0] = 1;

	for(int i = 0; i < N; i++){
		for(int k = 0; k <= S; k++){

			//未定→未定(0以外ありえない)
			if(k == 0){
				dp[i+1][k][0] += dp[i][k][0];
				dp[i+1][k][0] %= MOD;
			}
			//未定→左端決定
			if(k+A[i] <= S){
				dp[i+1][k+A[i]][1] += (dp[i][k][0]*(i+1))%MOD;
				dp[i+1][k+A[i]][1] %= MOD;
			}
			//未定→一気に両端決定
			if(k+A[i] <= S){
				dp[i+1][k+A[i]][2] += (((dp[i][k][0]*(i+1))%MOD)*(N-i))%MOD;
				dp[i+1][k+A[i]][2] %= MOD;
			}
			//左端決定→左端決定
			//足さない
			dp[i+1][k][1] += dp[i][k][1];
			dp[i+1][k][1] %= MOD;
			//足す
			if(k+A[i] <= S){
				dp[i+1][k+A[i]][1] += dp[i][k][1];
 				dp[i+1][k+A[i]][1] %= MOD;
			}

			//左端決定→両方決定
			if(k+A[i] <= S){

				dp[i+1][k+A[i]][2] += dp[i][k][1]*(N-i)%MOD;
				dp[i+1][k+A[i]][2] %= MOD;
			}
			//両方決定→両方決定
			dp[i+1][k][2] += dp[i][k][2];
			dp[i+1][k][2] %= MOD;
		}
	}

	printf("%lld\n",dp[N][S][2]);

	return 0;
}
