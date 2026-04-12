#include <cstdio>
using namespace std;
typedef long long ll;
const int NC = 1e7 + 5, Mod = 998244353;
int Ml(int x, int y) { return (ll)x * y % Mod; }
int Ad(int x, int y) { return ((x + y) > Mod) ? (x + y - Mod) : (x + y); }
int Dc(int x, int y) { return ((x - y) < 0) ? (x - y + Mod) : (x - y); }
int ksm(int x, int y) {
	int ret = 1;
	for (; y; y >>= 1, x = Ml(x, x))
		if (y & 1) ret = Ml(ret, x);
	return ret;
}
int N, half, fac[NC], ifac[NC];
void Init() {
	fac[0] = 1;
	for (int i = 1; i <= N; ++i)
		fac[i] = Ml(fac[i-1], i);
	ifac[N] = ksm(fac[N], Mod - 2);
	for (int i = N-1; i >= 0; --i)
		ifac[i] = Ml(ifac[i+1], i+1);
}
int binom(int x, int y) {
	if (x < 0 || y < 0 || x < y)
		return 0;
	else {
		return Ml(fac[x], Ml(ifac[y], ifac[x-y]));
	}
}
int main() {
	scanf("%d", &N);
	half = N / 2 + 1;
	int ans = 0;
	Init();
	for (int i = half; i <= N; ++i) {
		ans = Ad(ans, Ml(binom(N, i), ksm(2, N-i)));
	}
	ans = Dc(ksm(3, N), Ml(ans, 2));
	printf("%d\n", ans);
	return 0;
}