#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int p2[4000], fact[4000], fact_m[4000];
long long int DP[3100][3100] = {};

long long int mul_pow(long long int num, long long int pow_num, long long int mod_num){
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

int main(){
    long long int N;
    cin >> N >> MOD;
    p2[0] = fact[0] = fact_m[0] = 1;
    for(int i = 1; i < 4000; i++){
        p2[i] = p2[i - 1] * 2;
        p2[i] %= MOD;
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
        fact_m[i] = fact_m[i - 1] * mul_pow(i, MOD - 2, MOD);
        fact_m[i] %= MOD;
    }
    DP[0][0] = 1;
    for(int i = 1; i <= N; i++){
        DP[i][0] = 1;
        for(int j = 1; j <= N; j++){
            DP[i][j] = DP[i - 1][j] * (j + 1) + DP[i - 1][j - 1];
            DP[i][j] %= MOD;
        }
    }
    long long int ans = mul_pow(2, mul_pow(2, N, MOD - 1), MOD);
    long long int sig = -1;
    for(int i = 1; i <= N; i++){
        long long int P = 1, S = 0;
        for(int j = 0; j <= i; j++){
            S += DP[i][j] * P;
            S %= MOD;
            P *= p2[N - i];
            P %= MOD;
        }
        S *= mul_pow(2, mul_pow(2, N - i, MOD - 1), MOD);
        S %= MOD;
        long long int comb = (fact[N] * fact_m[i] % MOD) * fact_m[N - i] % MOD;
        S *= comb;
        S %= MOD;
        ans += S * sig + MOD * 10;
        ans %= MOD;
        sig *= -1;
    }
    cout << ans << endl;
    return 0;
}