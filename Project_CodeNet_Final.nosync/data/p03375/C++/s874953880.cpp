#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
ll s[3010][3010], c[3010][3010];
ll modpow(ll a, ll n, ll mod) {
	ll r = 1, b = a;
	while(n > 0) {
		if(n & 1) r = r * b % mod;
		b = b * b % mod;
		n >>= 1;
	}
	return r;
}
int main() {
	scanf("%d%d", &n, &m);
	s[0][0] = 1, c[0][0] = 1;
	for(int i=1; i<=3000; i++) {
		s[i][0] = 1, c[i][0] = 1;
		for(int j=1; j<=i; j++) {
			s[i][j] = (1ll * (j + 1) * s[i-1][j] % m + s[i-1][j-1]) % m;
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % m;
		}
	}
	ll res = 0;
	for(int i=0; i<=n; i++) { // i : 합이 0 또는 1인 것의 개수
		ll loc = 0;
		for(int j=0; j<=i; j++) { // j : 1개 이상의 토핑이 있는 라면의 개수 (토핑이 중복될 수 없으므로 라면의 개수는 i개 이하임을 알 수 있다)
			ll v = s[i][j];
			v = v * modpow(modpow(2, n-i, m), j, m) % m;
			loc = (loc + v) % m;
		}
		loc = loc * c[n][i] % m * modpow(2, modpow(2, n-i, m-1), m) % m;
		ll f = i % 2 ? -1 : 1;
		res = (res + loc * f + m) % m;
	}
	printf("%lld", res);
	return 0;
}