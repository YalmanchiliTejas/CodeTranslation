#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
using vint = vector<int>;
using vLL = vector<LL>;
int MOD = 1e9+7;
 
const int MAX = 1000000;
 
vLL fac(MAX), finv(MAX), inv(MAX);
 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
LL COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
	LL N, M, K;
	cin >> N >> M >>K;
	COMinit();
	LL S = COM(N*M-2, K-2);
	LL ans = 0;
	LL dsum = 0;
	for(int i = 1;i < N;i++){
		dsum += i*(N-i);
		dsum %= MOD;
	}
	LL cnt = M*M%MOD;
	LL res = dsum*cnt%MOD;
	ans += res;
	ans %= MOD;
	
	dsum = 0;
	for(int i = 0;i < M;i++){
		dsum += i*(M-i);
		dsum %= MOD;
	}
	
	cnt = N*N%MOD;
	res = dsum*cnt%MOD;
	ans += res;
	ans %= MOD;
	ans *= S;
	ans %= MOD;
	cout << ans << endl;
}