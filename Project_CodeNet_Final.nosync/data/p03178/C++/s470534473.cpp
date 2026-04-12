#include <iostream>

const long long MOD = (long long ) 1e9 + 7;
const long long MAXN = (long long) 1e4 + 10;

long long dp[MAXN][110][2];
 
int main(){
	std::string k;
	long long D;
	std::cin >> k >> D;
	long long n = k.size();

	dp[0][0][1] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < D; j++){
			for(int dig = 0; dig < 10; dig++){
				if(dig < (k[i] - '0')){
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][0];
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][1];
					dp[i + 1][ (j + dig) % D ][0] %= MOD;
				} else if ( dig == (k[i] - '0') ){
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][0];
					dp[i + 1][ (j + dig) % D ][1] += dp[i][j][1];
					dp[i + 1][ (j + dig) % D ][0] %= MOD;
					dp[i + 1][ (j + dig) % D ][1] %= MOD;
				} else {
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][0];
					dp[i + 1][ (j + dig) % D ][0] %= MOD;
				}
			}
		}
	}
	
	std::cout << (dp[n][0][1] + dp[n][0][0] + 1000000006) % MOD;
	return 0;
}