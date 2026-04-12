#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3005;

int n, mo;

ll s[N][N], c[N][N];

ll ksm(ll x, ll y, ll mo) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

int main() {
	scanf("%d %d", &n, &mo);
	fo(i, 0, n + 1) {
		if(i == 0) s[i][0] = 1;
		fo(j, 1, i) s[i][j] = (s[i - 1][j] * j + s[i - 1][j - 1]) % mo;
		c[i][0] = 1;
		fo(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
	}
	ll ans = 0;
	fo(i, 0, n) {
		ll xs = (i & 1 ? mo - 1 : 1) * c[n][i] % mo;
		xs = xs * ksm(2, ksm(2, n - i, mo - 1), mo) % mo;
		ll x = ksm(2, n - i, mo), t = 1;
		fo(j, 0, i) {
			ans = (ans + xs * t % mo * s[i + 1][j + 1]) % mo;
			t = t * x % mo;
		}
	}
	pp("%lld\n", ans);
}
