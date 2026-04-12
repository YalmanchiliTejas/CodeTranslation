

#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm> 
#include <math.h>
#include <queue>
#include <functional>
#include <map>
#include <vector>
#include <string>
#include <set> 
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
typedef pair<pair<int, int>, int> PP;

const ll INF = 1e15;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void) {
	ll N, M, K; cin >> N >> M >> K;
	ll X = 0, Y = 0;
	for (int d = 1; d < M; d++) {
		X += d*(M - d);
		X %= MOD;
	}
	for (int d = 1; d < N; d++) {
		Y += d * (N - d);
		Y %= MOD;
	}
	COMinit();
	X *= N * N; X %= MOD; X *= COM(N*M - 2, K - 2);X %= MOD;
	Y *= M * M; Y %= MOD; Y *= COM(N*M - 2, K - 2); Y %= MOD;
	cout << (X + Y) % MOD << endl;
	
}
