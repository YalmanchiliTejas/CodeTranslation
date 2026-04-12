#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long F[10100000], InvF[10100000], Mod = 998244353, po[10100000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
int main() {
	int i;
	scanf("%d", &n);
	F[0] = 1;
	po[0] = 1;
	for (i = 1; i <= n; i++) {
		F[i] = F[i - 1] * i%Mod;
		po[i] = po[i - 1] * 2 % Mod;
	}
	InvF[n] = Pow(F[n], Mod - 2);
	for (i = n; i >= 0; i--)InvF[i - 1] = InvF[i] * i%Mod;

	long long res = 0;
	for (i = n / 2 + 1; i <= n; i++) {
		res = (res + Comb(n, i) * po[n - i]) % Mod;
	}
	res = res * 2 % Mod;
	long long rr = 1;
	for (i = 1; i <= n; i++)rr = rr * 3 % Mod;
	printf("%lld\n", (rr - res + Mod) % Mod);
}