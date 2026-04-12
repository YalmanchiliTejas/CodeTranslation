#include <bits/stdc++.h>
using namespace std;
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)
#define pb push_back
#define all(x) x.begin(), x.end()
typedef pair<int,int> ii;
typedef long long ll;

ll ways2[3009][3009], ways[3009];
ll fat[3009], invfat[3009], p2[3009*3009];

ll fexp(ll a, ll b, ll mod) {
	ll ans = 1;
	while (b > 0) {
		if (b&1) { ans = (a*ans)%mod; }
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}

ll C(int n, int a, int mod) {
	return ((fat[n] * invfat[a]) % mod) * invfat[n-a] % mod;
}

int main() {
	int N, M;
	cin >> N >> M;

	fat[0] = 1; invfat[0] = 1;
	FOR1e(i, N) { fat[i] = fat[i-1]*i % M; invfat[i] = fexp(fat[i], M-2, M); }

	for (int i = 0; i <= N; i++) {
		ways2[i][0] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ways2[i][j] = (ways2[i-1][j-1] + ways2[i-1][j] + 1LL*j*ways2[i-1][j]) % M;
		}
	}
	p2[0] = 1;
	for (int i = 1; i <= N*N; i++) p2[i] = 2*p2[i-1] % M;

	for (int i = 0; i <= N; i++) {
		ways[i] = 0;
		for (int j = 0; j <= N; j++) {
			// Remaining N-i form 2^(N-i) sets. Each of them is either present or not
			ways[i] = (ways[i] + ways2[i][j]*p2[(N-i)*j]) % M;
		}
		ways[i] = (ways[i] * fexp(2, fexp(2, N-i, M-1), M)) % M;
	}

	ll ans = 0;
	for (int i = 0; i <= N; i++) {
		if (i&1) {
			ans = (ans - C(N, i, M)*ways[i]) % M;
			ans = (ans + M) % M;
		} else {
			ans = (ans + C(N, i, M)*ways[i]) % M;
		}
	}

	printf("%lld\n", ans);
}