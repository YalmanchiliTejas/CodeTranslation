#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;
long long int MOD = 1000000007;

long long int pow_m1(long long int num){
	long long int pow_num = MOD - 2;
	long long int mod_num = MOD;
	long long int pow_cur = num;
	long long int ret = 1;
	while(pow_num > 0){
		if(pow_num % 2 == 1){
			ret *= pow_cur;
			ret %= mod_num;
		}
		pow_cur *= pow_cur;
		pow_cur %= mod_num;
		pow_num /= 2;
	}
	return ret;
}

long long int DP[2001][2001];

int main(){
	
	while(true){
		
		long long int N, D, X;
		
		cin >> N >> D >> X;
		if(N == 0){
			break;
		}
		
		D %= MOD;
		
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= N; j++){
				DP[i][j] = 0;
			}
		}
		
		for(int i = 1; i < X; i++){
			DP[1][i] = 1;
		}
		for(int i = 2; i <= N; i++){
			for(int j = 2; j <= N; j++){
				DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];
				if(j - 1 >= X){
					DP[i][j] -= DP[i - 1][j - X];
				}
				DP[i][j] += MOD;
				DP[i][j] %= MOD;
			}
		}
		
		long long int ans = 0, comb = 1;
		
		for(long long int i = 1; i <= N; i++){
			comb *= (D - i + 1);
			comb %= MOD;
			comb *= pow_m1(i);
			comb %= MOD;
			ans += comb * DP[i][N];
			ans %= MOD;
		}
		
		cout << ans << endl;
	}
	return 0;
}
