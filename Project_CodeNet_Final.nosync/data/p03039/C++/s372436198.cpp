#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007

long long N, M, K;

long long kaidan[10000000];

void kaical(long long n){
	kaidan[0] = 1;
	for(long long i = 1; i < n; i++){
		kaidan[i] = kaidan[i-1] * i;
		kaidan[i] %= DIV;
	}
}

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= DIV;
		}
		ori *= ori;
		ori %= DIV;
		po >>= 1;
	}
	return res;
}

//nCk
//https://qiita.com/ofutonfuton/items/92b1a6f4a7775f00b6ae
long long combination(long long n, long long k){
	if(n == 0 && k == 0)return 1;
	if(n < k || n < 0)return 0;
	long long n_kai = kaidan[n];
	long long k_kai = kaidan[k];
	long long nmk_kai = kaidan[n-k];

	long long ans = n_kai * modpow(k_kai, DIV - 2);
	ans %= DIV;
	ans *= modpow(nmk_kai, DIV-2);
	ans %= DIV;
	return ans;
}

int main(){
	cin >> N >> M >> K;

	long long ans = 0;
	
	//x
	for(long long len = 1; len < M; len++){
		ans += len * (M- len) * N * N;
		ans %= DIV;
	}
	

	//y
	for(long long len = 1; len < N; len++){
		ans += len * (N-len) * M * M;
		ans %= DIV;
	}

	kaical(N*M);
	ans *= combination(N*M-2, K-2);
	ans %= DIV;
	cout << ans << endl;
}

