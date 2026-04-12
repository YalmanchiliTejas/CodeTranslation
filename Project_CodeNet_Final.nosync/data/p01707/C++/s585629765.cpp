#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

ll calc(ll x,ll y){
	if(y == 0){
		return x;
	}else{
		return calc(y,x%y);
	}
}

ll N,D,X;
ll dp[2001][2001],next_dp[2001];

void func(){

	if(X == 1){
		printf("0\n");
		return;
	}

	ll ans = 0;
	ll D_C_day;
	ll array[N],ruisekiwa[N];

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= N; k++)dp[i][k] = 0;
	}

	for(int i = 0; i <= N; i++){
		ruisekiwa[i] = 0;
	}

	dp[0][0] = 1;

	for(int eat_day = 1; eat_day <= N; eat_day++){

		if(eat_day != 1){

			array[eat_day-1] = (D-(eat_day-1));
			ll divisor = eat_day;

			while(divisor != 1){

				for(int i = 0; i < eat_day; i++){

					ll common;
					if(array[i] >= divisor){
						common = calc(array[i],divisor);
					}else{
						common = calc(divisor,array[i]);
					}

					array[i] /= common;
					divisor /= common;

					if(divisor == 1)break;
				}
			}

			D_C_day = 1;

			for(int i = 0; i < eat_day; i++){
				D_C_day *= array[i]%MOD;
				D_C_day %= MOD;
			}

			D_C_day %= MOD;

		}else{ //eat_day == 1;
			array[0] = D;
			D_C_day = D%MOD;
		}

		for(int i = 0; i <= N; i++){
			ruisekiwa[i] = dp[eat_day-1][i];
		}

		for(int i = 1; i <= N; i++){
			ruisekiwa[i] += ruisekiwa[i-1];
		}

		for(int num = 1; num <= N; num++){

			if(num-(int)(X-1)-1 < 0){
				next_dp[num] = ruisekiwa[num-1];
			}else{
				next_dp[num] = (ruisekiwa[num-1]-ruisekiwa[num-(int)(X-1)-1]);
			}
		}
		for(int i = 1; i <= N; i++){
			dp[eat_day][i] += next_dp[i];
			dp[eat_day][i] %= MOD;
		}

		ans += ((dp[eat_day][N]%MOD)*(D_C_day%MOD))%MOD;
		ans %= MOD;
	}

	printf("%lld\n",ans%MOD);
}

int main(){

	while(true){
		scanf("%lld %lld %lld",&N,&D,&X);
		if(N == 0 && D == 0 && X == 0)break;

		func();
	}

	return 0;
}