#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long N, M, K;
long long kaidan[1000000];

//フェルマーの小定理:a/b≡a*b^(MOD-2) (mod MOD)

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= MOD;
		}
		ori *= ori;
		ori %= MOD;
		po >>= 1;
	}
	return res;
}

long long comb(long long A, long long B) {
	if(B == 0){
		return 1;
	}
	long long ans = kaidan[A];
	ans *= modpow(kaidan[B], MOD-2);
	ans %= MOD;
	ans *= modpow(kaidan[A-B], MOD-2);
	ans %= MOD;
	return ans;
}

long long cal(long long maxi) {
	kaidan[0] = 1;
	for(long long i = 1; i <= maxi; i++){
		kaidan[i] = i * kaidan[i-1];
		kaidan[i] %= MOD;
	}
}

int main(){
	cin >> N >> M >> K;
	cal(N*M);

	long long ans = 0;

	long long xans = 0;
	for(long long i = 0; i < M; i++){
		long long tmp = i;
		tmp *= (M-i);
		tmp %= MOD;
		tmp *= N * N;
		tmp %= MOD;
		xans += tmp;
		xans %= MOD;
	}
	xans *= comb(N*M-2, K-2);
	xans %= MOD;

	long long yans = 0;
	for(long long i = 0; i < N; i++){
		long long tmp = i;
		tmp *= (N-i);
		tmp %= MOD;
		tmp *= M * M;
		tmp %= MOD;
		yans += tmp;
		yans %= MOD;
	}
	yans *= comb(N*M-2, K-2);
	yans %= MOD;

	cout << (xans + yans)%MOD << endl;

}

