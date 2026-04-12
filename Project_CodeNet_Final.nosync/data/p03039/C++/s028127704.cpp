#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 2 * 1e5; // 適宜


ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	COMinit();
	
	int n,m,k;
	cin >> n >> m >> k;
	
	
	// calc x
	ll x = 0;
	for(int i = 1; i < m; i++){
		x = (x + (((ll)(m-i)*i) % MOD) ) % MOD;
	}
	x = (x * (((ll)n*n) % MOD)) % MOD;
	
	// calc y
	ll y = 0;
	for(int i = 1; i < n; i++){
		y = (y + (((ll)(n-i)*i) % MOD) ) % MOD;
	}
	y = (y * (((ll)m*m) % MOD)) % MOD;
	
	ll res = (x+y)%MOD;
	
	cout << (res * COM(n*m-2,k-2)) % MOD << endl;
	return 0;
}
