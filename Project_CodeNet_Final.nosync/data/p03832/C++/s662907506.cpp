#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll F[1009], M[1009][1009], X[1009][1009], I[1009];
int N, A, B, C, D;

ll pw(ll X, ll Y) {
	if(Y == 0LL) return 1;
	ll t = pw(X, Y >> 1);
	if(Y&1) return t*t%MOD*X%MOD;
	return t*t%MOD;
}

ll inv(ll X) {
	return pw(X, MOD-2);
}

ll ncr(ll N, ll R) {
	if(N < 0 || N < R) return 0;
	if(N == R || R == 0) return 1;
	if(X[N][R]) return X[N][R];
	return X[N][R] = (ncr(N-1, R-1) + ncr(N-1, R)) % MOD;
}

int main() {
	F[0] = 1; I[0] = inv(1);
	for(int i=1; i<=1000; i++) {
		F[i] = F[i-1] * i % MOD;
		I[i] = inv(F[i]);
	}
	scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);
	for(int i=0; i<=B; i++) M[0][i] = 1;
	for(int i=1; i<=N; i++) {
		for(int j=A; j<=B; j++) {
			M[i][j] = M[i][j-1];
			long long s = 1;
			for(int k=1; k<=D; k++) {
				s *= ncr(i - (k-1)*j, j); s %= MOD;
				if(k < C) continue;
				if(i - k*j >= 0) {
					M[i][j] += (M[i - k*j][j-1] * s % MOD * I[k] % MOD);
					// printf("i: %d, j: %d, k: %d, i-k*j: %d, M[i][j]: %lld, C: %lld\n", i, j, k, i-k*j, M[i][j], s * inv(F[k]) % MOD);
				}
				else break;
				M[i][j] %= MOD;
			}
		}
	}
	printf("%lld", M[N][B]);
	return 0;
}