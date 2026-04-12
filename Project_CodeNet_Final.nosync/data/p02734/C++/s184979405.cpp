#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
//#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define MOD 998244353
#define SIZE 3005

ll N;
int S;
int A[SIZE];
ll dp[SIZE][SIZE][3];

int main(){

	scanf("%lld %d",&N,&S);

	for(int i = 0; i < N; i++){

		scanf("%d",&A[i]);
	}

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= S; k++){
			for(int p = 0; p < 3; p++){
				dp[i][k][p] = 0;
			}
		}
	}

	dp[0][0][0] = 1;

	/*
	 * 0:両方未定
	 * 1:左方決定
	 * 2:両方決定
	 * */

	for(ll i = 0; i < N; i++){
		for(int k = 0; k <= S; k++){

			dp[i+1][k][0] += dp[i][k][0];
			dp[i+1][k][0] %= MOD;

			if(k+A[i] <= S){

				dp[i+1][k+A[i]][1] += dp[i][k][0]*(i+1);
				dp[i+1][k+A[i]][1] %= MOD;

				dp[i+1][k+A[i]][2] += dp[i][k][0]*(i+1)*(N-i);
				dp[i+1][k+A[i]][2] %= MOD;
			}

			dp[i+1][k][1] += dp[i][k][1];
			dp[i+1][k][1] %= MOD;

			if(k+A[i] <= S){

				dp[i+1][k+A[i]][1] += dp[i][k][1];
				dp[i+1][k+A[i]][1] %= MOD;

				dp[i+1][k+A[i]][2] += dp[i][k][1]*(N-i);
				dp[i+1][k+A[i]][2] %= MOD;
			}

			dp[i+1][k][2] += dp[i][k][2];
			dp[i+1][k][2] %= MOD;
		}
	}

	printf("%lld\n",dp[N][S][2]);

	return 0;
}
