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

long long int rev_mod(long long int num){
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

long long int fact[210000];

int main(){
    fact[0] = 1;
    for(int i = 1; i < 210000; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    long long int N, M, K;
    cin >> N >> M >> K;
    long long int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            long long int p = N - i + 1;
            long long int S = p * (p - 1) / 2 % MOD * M % MOD;
            ans += S;
            ans %= MOD;

            p = i;
            S = p * (p - 1) / 2 % MOD * M % MOD;
            ans += S;
            ans %= MOD;

            p = M - j + 1;
            S = p * (p - 1) / 2 % MOD * N % MOD;
            ans += S;
            ans %= MOD;
            
            p = j;
            S = p * (p - 1) / 2 % MOD * N % MOD;
            ans += S;
            ans %= MOD;
        }
    }
    ans *= fact[N * M - 2];
    ans %= MOD;
    ans *= rev_mod(fact[K - 2]);
    ans %= MOD;
    ans *= rev_mod(fact[N * M - K]);
    ans %= MOD;
    ans *= rev_mod(2);
    ans %= MOD;
    cout << ans << endl;
    return 0;
}