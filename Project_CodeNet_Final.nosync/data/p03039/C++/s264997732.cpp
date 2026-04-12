#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 200002;
const int mod = 1e9 + 7;

// fac[]・・・a! finv[]・・・(a!)^(-1) inv[]・・・a^(-1)

long long fac[MAX], finv[MAX], inv[MAX];

void pre_comb(void){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2; i<MAX; i++){
		fac[i] = fac[i-1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod/i) % mod;
		finv[i] = finv[i-1] * inv[i] % mod;
	}
}

long long comb(int n, int k){
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}


int main(){
	ll N, M, K; cin >> N >> M >> K;
	ll ans = 0;
	pre_comb();
	for(int dx=1; dx<M; dx++){
		ll pat = N * N * (M-dx) % mod;
		ans = (ans + (pat * comb(N*M-2, K-2) % mod) * dx) % mod;
	}
	for(int dy=1; dy<N; dy++){
		ll pat = M * M * (N-dy) % mod;
		ans = (ans + (pat * comb(N*M-2, K-2) % mod) * dy) % mod;
	}
	cout << ans << endl;
	return 0;
}
