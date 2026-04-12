#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int MAX = 210000;
const int MOD = 1000000007;

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

int main()
{
	ll N,M,K;
	cin >> N >> M >> K;
	COMinit();
	ll ans = 0;
	ll temp = 0;
	for (int i = 1; i <= N-1; ++i)
	{
		temp = (N-i) * M * M % MOD * i % MOD;
		ans = (ans + COM(N*M-2,K-2) * temp % MOD) % MOD;
	}
	for (int i = 1; i <= M-1; ++i)
	{
		temp = (M-i) * N * N % MOD * i % MOD;
		ans = (ans + COM(N*M-2,K-2) * temp % MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}