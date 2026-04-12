#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main(){
	vector<long long> inv(1001);
	vector<long long> fact(1001);
	vector<long long> factInv(1001);
	inv[0] = inv[1] = 1;
	fact[0] = fact[1] = 1;
	factInv[0] = factInv[1] = 1;
	for(int i=2;i<inv.size();i++){
		inv[i] = inv[MOD%i] * (MOD - MOD/i) % MOD;
		fact[i] = fact[i-1] * i % MOD;
		factInv[i] = factInv[i-1] * inv[i] % MOD;
	}
	long long dp[2][1001];
	static long long comb[1001][1001];
	comb[1][0] = comb[1][1] = 1;
	for(int i=2;i<=1000;i++){
		comb[i][0] = 1;
		for(int j=1;j<i;j++) comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%MOD;
		comb[i][i] = 1;
	}
	int N, A, B, C, D;
	while(cin >> N >> A >> B >> C >> D){
		memset(dp, 0, sizeof(dp));
		dp[0][N] = 1;
		for(int i=0;i<=N;i++){
			int cur = i%2, next = 1-i%2;
			for(int j=0;j<=N;j++) dp[next][j] = dp[cur][j];
			if(i < A || B < i) continue;
			for(int j=0;j<=N;j++){
				long long div = 1;
				for(int k=1;k*i<=j;k++){
					div = (div * factInv[i])%MOD;
					div = (div * inv[k])%MOD;
					if(k > D) break;
					if(k < C) continue;
					long long add = dp[cur][j] * comb[j][k*i] % MOD * fact[k*i] % MOD * div % MOD;
					dp[next][j-k*i] += add;
					dp[next][j-k*i] %= MOD;
				}
			}
		}
		cout << dp[1-N%2][0] << endl;
	}
}
