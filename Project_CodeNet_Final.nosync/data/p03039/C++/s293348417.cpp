#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	return (a %= p) >= 0 ? a : a + p;
}

int fact(int N){
	static vector<int> fac(1, 1);
	for(int i = fac.size(); i <= N; i++){
		fac.push_back(MOD(i * fac[i - 1]));
	}
	return fac[N];
}

int fact_inv(int N){
	static vector<int> inv(2, 1), fac_inv(2, 1);
	for(int i = inv.size(); i <= N; i++){
		inv.push_back(MOD(-(p / i) * inv[p % i]));
		fac_inv.push_back(MOD(inv[i] * fac_inv[i - 1]));
	}
	return fac_inv[N];
}

int comb(int N, int k){
	if(k < 0 || N < k || N < 0) return 0;
	else return MOD(fact(N) * MOD(fact_inv(N - k) * fact_inv(k)));
}

int solve(int N, int M, int K){
	int d, ans = 0;
	for(d = 1; d < N; d++){
		ans = MOD(ans + MOD(MOD(d * (N - d)) * MOD(M * M)) * comb(N * M - 2, K - 2));
	}
	return ans;
}

signed main(){
	int N, M, K, i;
	scanf("%lld%lld%lld", &N, &M, &K);
	printf("%lld\n", MOD(solve(N, M, K) + solve(M, N, K)));
	return 0;
}