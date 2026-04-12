//abc127_e.cpp
//Mon Sep 23 17:29:07 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;
const int MAX = 200000;
const int MOD = 1000000007;
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
	ll n,m,k;
	cin >> n >> m >> k;

	COMinit();

	ll otherscom = COM(n*m-2,k-2);
	ll tateall = 0;
	for (int i=1;i<n;i++){
		ll tate = (n-i)*i%MOD;
		tate = ((tate * m)%MOD) * m % MOD;
		tate = tate * otherscom % MOD;
		tateall = (tateall + tate) % MOD;
	}

	ll yokoall = 0;
	for (int i=1;i<m;i++){
		ll yoko = (m-i)*i%MOD;
		yoko = (yoko * n)%MOD * n % MOD;
		yoko = yoko * otherscom % MOD;
		yokoall = (yokoall + yoko) % MOD;
	}

	ll ans = (tateall + yokoall) % MOD;
	cout << ans << endl;
//	printf("%.4f\n",ans);
}