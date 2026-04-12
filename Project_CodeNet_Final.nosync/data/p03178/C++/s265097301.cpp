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

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[11000][110] = {};

int main(){
	
	string K;
	cin >> K;
	
	int D;
	cin >> D;
	
	for(int i = 0; i < K.size(); i++){
		K[i] = K[i] - '0';
	}
	
	DP[0][0] = 1;
	for(int i = 0; i < K.size(); i++){
		for(int j = 0; j < D; j++){
			for(int k = 0; k < 10; k++){
				DP[i + 1][(j + k) % D] += DP[i][j];
				DP[i + 1][(j + k) % D] %= MOD;
			}
		}
	}
	
	long long int ans = 0;
	int cur = 0;
	for(int i = 0; i < K.size(); i++){
		for(int j = 0; j < K[i]; j++){
			ans += DP[K.size() - i - 1][(D * 1000 - cur - j) % D];
			ans %= MOD;
		}
		cur += K[i];
		cur %= D;
	}
	
	ans += MOD - 1;
	ans %= MOD;
	
	if(cur == 0){
		ans += 1;
		ans %= MOD;
	}
	
	cout << ans << endl;
	
	return 0;
}
