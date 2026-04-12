#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const int MAXN = 100 + 10;
const int Mod = 1e9 + 7;
int N;
int A[MAXN];
int f[MAXN];

inline int fastpow_mod(int a, ll b) {
	int x = 1;
	while(b) {
		if(b & 1) x = 1ll * x * a % Mod;
		a = 1ll * a * a % Mod; b >>= 1;
	}
	return x;
}

int main() {
	register int i, j, k;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		scanf("%d", A + i);
	f[0] = 1;
	A[N + 1] = 1;
	for(i = 1; i <= N + 1; ++i) {
		f[i] = f[i - 1] * 2 % Mod;
		for(j = 1; j < i; ++j) {
			int l = max(A[i], A[j - 1]), r = A[j] - 1;
			ll s = 0;
			for(k = j; k < i; ++k)
				r = min(r, A[k] - 1), s += max(A[k + 1] - A[k], 0);
			if(l <= r) {
				int t1 = fastpow_mod(2, A[j] - r - 1);
				int t2 = fastpow_mod(2, r - l + 1) - 1;
				int t3 = fastpow_mod(2, s);
				f[i] = (f[i] + 4ll * f[j - 1] * t1 % Mod * t2 % Mod * t3 % Mod) % Mod;
			}
		}
	}
	printf("%lld\n", 1ll * f[N + 1] * (Mod + 1) / 2 % Mod);
	return 0;
}