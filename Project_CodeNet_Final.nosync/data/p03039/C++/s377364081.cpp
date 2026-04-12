#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, M, K;


const int MAX = 200001;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


// 0 .. n の合計
ll acc(ll n)
{
	return n*(n+1)/2;
}

int main(){
	cin >> N >> M >> K;
	COMinit();
	
	/*
	  2つの駒の配置コスト × 他の場所にK-2個を置く方法の数
	  他の場所にK-2個を置く方法の数 = (N*M-2)C(K-2)
	*/
	
	// 2つの駒の配置コスト の合計
	ll cost = 0;
	for ( ll i = 0; i < N; i++ ){
		ll  a = (acc(i) + acc(N-1-i))%MOD;
		a = a*M%MOD;
		a = a*M%MOD;
		cost = (cost + a)%MOD;
		
		//for ( ll j = 0; j < N; j++ ){
		//	cost = (cost + ((abs(i-j) * (i==j ? M-1 : M))%MOD)*M) % MOD;
		//}
	}
	for ( ll i = 0; i < M; i++ ){
		ll  a = (acc(i) + acc(M-1-i))%MOD;
		a = a*N%MOD;
		a = a*N%MOD;
		cost = (cost + a)%MOD;
		
		//for ( ll j = 0; j < M; j++ ){
		//	cost = (cost + ((abs(i-j) * (i==j ? N-1 : N))%MOD)*N) % MOD;
		//}
	}
	
	cout << ( (cost*finv[2]%MOD) * COM(N*M-2,K-2) )%MOD << endl;

	return 0;
}

