#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[1100][1100] = {};
long long int fact[1100][1100];

long long int pow_m1(long long int num){
	long long int pow_num = MOD - 2;
	long long int pow_cur = num;
	long long int ret = 1;
	while(pow_num > 0){
		if(pow_num % 2 == 1){
			ret *= pow_cur;
			ret %= MOD;
		}
		pow_cur *= pow_cur;
		pow_cur %= MOD;
		pow_num /= 2;
	}
	return ret;
}

int main(){
	
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	
	fact[1][0] = 1;
	for(int i = 1; i <= N; i++){
		fact[1][i] = fact[1][i - 1] * i;
		fact[1][i] %= MOD;
	}
	for(int i = 0; i <= N; i++){
		fact[0][i] = 1;
	}
	
	for(int i = 2; i <= N; i++){
		for(int j = 0; j <= N; j++){
			fact[i][j] = fact[i - 1][j] * fact[1][j];
			fact[i][j] %= MOD;
		}
	}
	
	DP[A - 1][0] = 1;
	for(int i = A; i <= B; i++){
		for(int j = 0; j <= N; j++){
			long long int SS;
			DP[i][j] = DP[i - 1][j];
			for(int k = C; i * k <= j && k <= D; k++){
				SS = fact[k][i];
				SS *= fact[1][N - j];
				SS %= MOD;
				SS *= fact[1][k];
				SS %= MOD;
				SS = fact[1][N - j + i * k] * pow_m1(SS);
				SS %= MOD;
				DP[i][j] += DP[i - 1][j - i * k] * SS;
				DP[i][j] %= MOD;
			}
		}
	}
	
	cout << DP[B][N] << endl;
}
