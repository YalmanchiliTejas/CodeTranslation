#include<cstdio>
#include<algorithm>
using namespace std;
int w[110], n, D[110], Mod = 1000000007;
int Pow(int a, long long b) {
	int r = 1;
	while (b) {
		if (b & 1)r = 1ll * r*a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	D[0] = 1;
	w[n + 1] = 1;
	for (i = 1; i <= n + 1; i++) {
		D[i] = D[i - 1] * 2 % Mod;
		for (j = 1; j < i; j++) {
			int b = max(w[i], w[j - 1]), e = w[j] - 1;
			long long s = 0;
			for (k = j; k < i; k++) {
				e = min(e, w[k] - 1);
				s += max(w[k + 1] - w[k], 0);
			}
			if (b <= e) {
				int t1 = Pow(2, w[j] - 1 - e);
				int t2 = Pow(2, e - b + 1) - 1;
				int t3 = Pow(2, s);
				D[i] = (D[i] + 4ll * D[j - 1] * t1 % Mod* t2%Mod * t3)%Mod;
			}
		}
	}
	printf("%lld\n", 1ll*D[n + 1]*((Mod+1)/2)%Mod);
}