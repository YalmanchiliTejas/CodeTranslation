#include <cstdio>
#define ll long long
using namespace std;

ll f[55], p[55];

ll F(ll n, ll x) {
	if (n == 0) return 1;
	if (x == 1) return 0;
	if (x > 1 && x <= f[n-1] + 1) return F(n - 1, x - 1);
	if (x == 2 + f[n-1]) return p[n-1] + 1;
	if (2 + f[n-1] < x && x <= 2 + 2 * f[n-1]) return p[n-1] + 1 + F(n - 1, x - 2 - f[n-1]);
	if (x == f[n-1] * 2 + 3) return 2 * p[n-1] + 1;
}

int main() {
	f[0] = p[0] = 1;
	for (int i = 1; i <= 50; i++) {
		f[i] = 2 * f[i-1] + 3;
		p[i] = 2 * p[i-1] + 1;
	}
	ll n; ll x;
	scanf("%lld%lld", &n, &x);
	printf("%lld\n", F(n, x));
	return 0;
}