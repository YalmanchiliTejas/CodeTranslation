#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x > 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % mod;
}
int mod_pow(int x, int y, int mod_) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod_;
		}
		x = x * x % mod_;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}
/*--------Library Zone!--------*/

int ka[214514];
int comb_(int x, int y) {
	if (y > x)return 0;
	return ka[x] * mod_pow(ka[x - y], mod - 2, mod) % mod * mod_pow(ka[y], mod - 2, mod) % mod;
}
void init() {
	ka[0] = 1;
	REP(i, 214514)ka[i] = ka[i - 1] * i % mod;
}
int n, m, k;
signed main() {
	cin >> n >> m >> k;
	init();
	int ans = 0;
	//X座標
	REP(i, n) {
		ans += i * (n - i) * m % mod * m % mod * comb_(n * m - 2, k - 2) % mod;
		ans %= mod;
	}
	REP(i, m) {
		ans += i * (m - i) * n % mod * n % mod * comb_(n * m - 2, k - 2) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}
