//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 10000000 + 10;
const ll MOD = 998244353;
const ll INF = 1000000010;
const ll LOG = 25;

int fac[N], inv[N], tav[N], mx[N];

int POW(int x, int y){
	int res = 1;
	while (y){
		if (y & 1) res = res * 1ll * x % MOD;
		y >>= 1;
		x = x * 1ll * x % MOD;
	}
	return res;
}

int nCr(int a, int b){
	if (b < 0 || a < 0 || b > a) return 0;
	int res = fac[a];
	res = res * 1ll *inv[b] % MOD;
	res = res * 1ll * inv[a - b] % MOD;
	return res;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	fac[0] = tav[0] = 1;
	for (int i = 1; i < N; i++) tav[i] = tav[i - 1] * 2ll % MOD;
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * 1ll * i % MOD;
	inv[N - 1] = POW(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * 1ll * (i + 1) % MOD;
	int ans = POW(3, n);
	for (int i = n / 2 + 1; i <= n; i++){
		int res = nCr(n, i) * 1ll * tav[n - i] % MOD;
		ans -= res * 2ll % MOD;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;	
}
