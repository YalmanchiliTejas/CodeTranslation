#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;


i64 n, m, k;

//コンビネーション
//けんちょんさんありがとう
const int MAX = 202020, MOD = INF;
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
long long C(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
////

int main(){
	cin >> n >> m >> k;
	
	i64 ans = 0, cnt = 0;
	for(i64 i = 1; i < n; i++){
		cnt = i*(i+1) / 2 % INF;
		cnt = cnt * m % INF * m % INF;
		ans += cnt;
		ans %= INF;
	}
	for(i64 i = 1; i < m; i++){
		cnt = i*(i+1) / 2 % INF;
		cnt = cnt * n % INF * n % INF;
		ans += cnt;
		ans %= INF;
	}
	
	COMinit();
	cout << C(n*m-2, k-2) * ans % INF << endl;
	
	return 0;
}