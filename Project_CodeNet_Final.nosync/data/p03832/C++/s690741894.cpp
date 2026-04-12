#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll pw(ll n, ll k) {
	ll r = 1; for(n %= MOD; k; k >>= 1) {
		if(k&1) r = r * n % MOD;
		n = n * n % MOD;
	}
	return r;
}
ll inv(ll n) { return pw(n, MOD-2); }

const int MAXN = 1005;

ll E[MAXN][MAXN];
ll F[MAXN], RF[MAXN];

int N, A, B, C, D;

ll getC(int a, int b) {
	if(a < 0 || b < 0 || a < b) return 0;
	return F[a] * RF[b] % MOD * RF[a-b] % MOD;
}

int main() {
	F[0] = 1;
	for(int i = 1; i < MAXN; i++) F[i] = F[i-1] * i % MOD;
	RF[MAXN-1] = inv(F[MAXN-1]);
	for(int i = MAXN; --i;) RF[i-1] = RF[i] * i % MOD;

	cin >> N >> A >> B >> C >> D;
	E[A-1][0] = 1;
	for(int i = A; i <= B; i++) {
		for(int j = 0; j <= N; j++) {
			ll &ret = E[i][j];
			ret = E[i-1][j];
			for(int k = C; k <= D && 0 <= j-k*i; k++) {
				ret += E[i-1][j-k*i] * getC(N - (j-k*i), k*i) % MOD * F[k*i] % MOD * RF[k] % MOD * pw(RF[i], k) % MOD;
				ret %= MOD;
			}
		}
	}

	cout << E[B][N] << endl;
	return 0;
}