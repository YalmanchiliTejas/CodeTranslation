#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool** table;

void func(int N,int M){
	int coin[N],second_coin[1024],index = 0;

	for(int i = 0; i < N; i++){
		for(int k = 0; k < M+1; k++)table[i][k] = false;
	}

	for(int i = 0; i < N; i++){
		scanf("%d",&coin[i]);
	}

	table[0][coin[0]] = true;

	for(int i = 1; i < N; i++){

		for(int k = 1; k < coin[i];k++){
			if(table[i-1][k] == true)table[i][k] = true;
		}

		table[i][coin[i]] = true;

		for(int k = coin[i]+1; k <= M; k++){
			if(table[i-1][k] == true || table[i-1][k-coin[i]] == true)table[i][k] = true;
		}
	}

	for(int i = 1; i <= M; i++){
		if(table[N-1][i] == true){
			second_coin[index++] = i;
		}
	}

	int dp[M+1];
	for(int i = 1; i <= M; i++)dp[i] = 2000000000;

	dp[0] = 0;

	for(int i = 1; i <= M; i++){
		for(int k = 0; k < index; k++){
			if(i >= second_coin[k]){
				dp[i] = min(dp[i],dp[i-second_coin[k]] + 1);
			}
		}
	}

	printf("%d\n",dp[M]);

}


int main(){

	int N,M;

	table = new bool*[10];
	for(int i = 0; i < 10; i++){
		table[i] = new bool[100001];
	}

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)break;

		func(N,M);
	}

    return 0;
}