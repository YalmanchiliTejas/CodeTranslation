#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int mod = 998244353;
const int nax = 1e7 + 11;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int n;
int fac[nax];
int rev[nax];
int two[nax];

int nt(int N, int K) {
	return 1ll * fac[N] * rev[K] % mod * rev[N - K] % mod;
}

int main() {
	fac[0] = 1;
	rev[0] = 1;
	two[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
		two[i] = 1ll * two[i - 1] * 2 % mod;
	}
	scanf("%d", &n);
	int ans = pt(3, n);
	
	for(int i = n / 2 + 1; i <= n; ++i) 
		ans = (ans - 1ll * nt(n, i) * two[n - i] % mod * 2 % mod + mod) % mod;
	printf("%d\n", ans);
	
	
	return 0;
}

